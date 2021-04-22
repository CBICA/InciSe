/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/


#ifndef QmitkCaPTkVisualizationPerspective_H_
#define QmitkCaPTkVisualizationPerspective_H_

#include <berryIPerspectiveFactory.h>

class QmitkCaPTkVisualizationPerspective : public QObject, public berry::IPerspectiveFactory
{
  Q_OBJECT
  Q_INTERFACES(berry::IPerspectiveFactory)

public:

  QmitkCaPTkVisualizationPerspective() {}
  ~QmitkCaPTkVisualizationPerspective() override {}

  void CreateInitialLayout(berry::IPageLayout::Pointer layout) override;
};

#endif /* QmitkCaPTkVisualizationPerspective_H_ */
