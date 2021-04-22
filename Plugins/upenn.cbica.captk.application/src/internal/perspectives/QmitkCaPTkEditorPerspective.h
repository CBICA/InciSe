/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/


#ifndef QMITKCAPTKEDITORPERSPECTIVE_H_
#define QMITKCAPTKEDITORPERSPECTIVE_H_

#include <berryIPerspectiveFactory.h>

class QmitkCaPTkEditorPerspective : public QObject, public berry::IPerspectiveFactory
{
  Q_OBJECT
  Q_INTERFACES(berry::IPerspectiveFactory)

public:

  QmitkCaPTkEditorPerspective() {}
  ~QmitkCaPTkEditorPerspective() override {}

  void CreateInitialLayout(berry::IPageLayout::Pointer /*layout*/) override;
};

#endif /* QMITKCAPTKEDITORPERSPECTIVE_H_ */
