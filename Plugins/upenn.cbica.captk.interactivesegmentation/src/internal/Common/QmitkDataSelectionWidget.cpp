/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/

#include "QmitkDataSelectionWidget.h"
#include "internal/mitkPluginActivator.h"

#include <berryPlatform.h>
#include <mitkIDataStorageService.h>
#include <mitkImage.h>
#include <mitkLabelSetImage.h>
#include <mitkNodePredicateAnd.h>
#include <mitkNodePredicateOr.h>
#include <mitkNodePredicateDataType.h>
#include <mitkNodePredicateNot.h>
#include <mitkNodePredicateProperty.h>
#include <mitkProperties.h>
#include <mitkSurface.h>
#include <QmitkDataStorageComboBox.h>
#include <QLabel>
#include <algorithm>
#include <cassert>
#include <iterator>

#include <ctkServiceReference.h>

static mitk::NodePredicateBase::Pointer CreatePredicate(QmitkDataSelectionWidget::PredicateType predicateType)
{

  mitk::NodePredicateAnd::Pointer  seedsPredicate = mitk::NodePredicateAnd::New();
  seedsPredicate->AddPredicate(mitk::TNodePredicateDataType<mitk::LabelSetImage>::New());
  seedsPredicate->AddPredicate(mitk::NodePredicateNot::New(mitk::NodePredicateProperty::New("helper object")));

  // CaPTk: To not detect output segmentations as seeds
  seedsPredicate->AddPredicate(
      mitk::NodePredicateNot::New(
          mitk::NodePredicateProperty::New(
              "captk.interactive.segmentation.output", 
              mitk::BoolProperty::New(true)
          )
      )
  );

  mitk::NodePredicateAnd::Pointer maskPredicate = mitk::NodePredicateAnd::New();
  maskPredicate->AddPredicate(mitk::NodePredicateProperty::New("binary", mitk::BoolProperty::New(true)));
  maskPredicate->AddPredicate(mitk::NodePredicateNot::New(mitk::NodePredicateProperty::New("helper object", mitk::BoolProperty::New(true))));

  mitk::NodePredicateDataType::Pointer isDwi = mitk::NodePredicateDataType::New("DiffusionImage");
  mitk::NodePredicateDataType::Pointer isDti = mitk::NodePredicateDataType::New("TensorImage");
  mitk::NodePredicateDataType::Pointer isOdf = mitk::NodePredicateDataType::New("OdfImage");
  mitk::TNodePredicateDataType<mitk::Image>::Pointer isImage = mitk::TNodePredicateDataType<mitk::Image>::New();

  mitk::NodePredicateOr::Pointer validImages = mitk::NodePredicateOr::New();
  validImages->AddPredicate(isImage);
  validImages->AddPredicate(isDwi);
  validImages->AddPredicate(isDti);
  validImages->AddPredicate(isOdf);

  mitk::NodePredicateAnd::Pointer imagePredicate = mitk::NodePredicateAnd::New();
  imagePredicate->AddPredicate(validImages);
  imagePredicate->AddPredicate(mitk::NodePredicateNot::New(seedsPredicate));
  imagePredicate->AddPredicate(mitk::NodePredicateNot::New(mitk::NodePredicateProperty::New("binary", mitk::BoolProperty::New(true))));
  imagePredicate->AddPredicate(mitk::NodePredicateNot::New(mitk::NodePredicateProperty::New("helper object", mitk::BoolProperty::New(true))));

  // CaPTk: To not detect output segmentations as normal images
  imagePredicate->AddPredicate(
      mitk::NodePredicateNot::New(
          mitk::NodePredicateProperty::New(
              "captk.interactive.segmentation.output", 
              mitk::BoolProperty::New(true)
          )
      )
  );

  mitk::NodePredicateAnd::Pointer surfacePredicate = mitk::NodePredicateAnd::New();
  surfacePredicate->AddPredicate(mitk::TNodePredicateDataType<mitk::Surface>::New());
  surfacePredicate->AddPredicate(mitk::NodePredicateNot::New(mitk::NodePredicateProperty::New("helper object", mitk::BoolProperty::New(true))));

  switch(predicateType)
  {
    case QmitkDataSelectionWidget::ImagePredicate:
      return imagePredicate.GetPointer();

    case QmitkDataSelectionWidget::MaskPredicate:
      return maskPredicate.GetPointer();

    case QmitkDataSelectionWidget::SegmentationPredicate:
      return seedsPredicate.GetPointer();

    case QmitkDataSelectionWidget::SurfacePredicate:
      return surfacePredicate.GetPointer();

    default:
      assert(false && "Unknown predefined predicate!");
      return nullptr;
  }
}

QmitkDataSelectionWidget::QmitkDataSelectionWidget(QWidget* parent)
  : QWidget(parent)
{
  m_Controls.setupUi(this);
  m_Controls.helpLabel->hide();
}

QmitkDataSelectionWidget::~QmitkDataSelectionWidget()
{
}

unsigned int QmitkDataSelectionWidget::AddDataStorageComboBox(QmitkDataSelectionWidget::PredicateType predicate)
{
  return this->AddDataStorageComboBox("", predicate);
}

unsigned int QmitkDataSelectionWidget::AddDataStorageComboBox(mitk::NodePredicateBase* predicate)
{
  return this->AddDataStorageComboBox("", predicate);
}

unsigned int QmitkDataSelectionWidget::AddDataStorageComboBox(const QString &labelText, QmitkDataSelectionWidget::PredicateType predicate)
{
  return this->AddDataStorageComboBox(labelText, CreatePredicate(predicate));
}

unsigned int QmitkDataSelectionWidget::AddDataStorageComboBox(const QString &labelText, mitk::NodePredicateBase* predicate)
{
  int row = m_Controls.gridLayout->rowCount();

  if (!labelText.isEmpty())
  {
    QLabel* label = new QLabel(labelText, m_Controls.dataSelectionWidget);
    label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
    m_Controls.gridLayout->addWidget(label, row, 0);
  }

  QmitkDataStorageComboBox* comboBox = new QmitkDataStorageComboBox(this->GetDataStorage(), predicate, m_Controls.dataSelectionWidget);
  connect(comboBox, SIGNAL(OnSelectionChanged(const mitk::DataNode *)), this, SLOT(OnSelectionChanged(const mitk::DataNode *)));
  comboBox->SetAutoSelectNewItems(true);
  m_Controls.gridLayout->addWidget(comboBox, row, 1);

  m_DataStorageComboBoxes.push_back(comboBox);
  return static_cast<unsigned int>(m_DataStorageComboBoxes.size() - 1);
}

mitk::DataStorage::Pointer QmitkDataSelectionWidget::GetDataStorage() const
{
    ctkServiceReference ref = mitk::PluginActivator::getContext()->getServiceReference<mitk::IDataStorageService>();
    assert(ref == true);

    mitk::IDataStorageService* service = mitk::PluginActivator::getContext()->getService<mitk::IDataStorageService>(ref);

    assert(service);

  return service->GetDefaultDataStorage()->GetDataStorage();
}

mitk::DataNode::Pointer QmitkDataSelectionWidget::GetSelection(unsigned int index)
{
  assert(index < m_DataStorageComboBoxes.size());
  return m_DataStorageComboBoxes[index]->GetSelectedNode();
}

void QmitkDataSelectionWidget::SetPredicate(unsigned int index, PredicateType predicate)
{
  this->SetPredicate(index, CreatePredicate(predicate));
}

void QmitkDataSelectionWidget::SetPredicate(unsigned int index, mitk::NodePredicateBase* predicate)
{
  assert(index < m_DataStorageComboBoxes.size());
  m_DataStorageComboBoxes[index]->SetPredicate(predicate);
}

void QmitkDataSelectionWidget::SetHelpText(const QString& text)
{
  if (!text.isEmpty())
  {
    m_Controls.helpLabel->setText(text);

    if (!m_Controls.helpLabel->isVisible())
      m_Controls.helpLabel->show();
  }
  else
  {
    m_Controls.helpLabel->hide();
  }
}

void QmitkDataSelectionWidget::OnSelectionChanged(const mitk::DataNode* selection)
{
  std::vector<QmitkDataStorageComboBox*>::iterator it = std::find(m_DataStorageComboBoxes.begin(), m_DataStorageComboBoxes.end(), sender());
  assert(it != m_DataStorageComboBoxes.end());

  emit SelectionChanged(std::distance(m_DataStorageComboBoxes.begin(), it), selection);
}
