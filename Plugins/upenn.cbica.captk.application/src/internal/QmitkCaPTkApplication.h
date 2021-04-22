/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/

#ifndef QMITKCAPTKAPPLICATION_H_
#define QMITKCAPTKAPPLICATION_H_

#include <berryIApplication.h>


class QmitkCaPTkApplication : public QObject, public berry::IApplication
{
  Q_OBJECT
  Q_INTERFACES(berry::IApplication)

public:

  QmitkCaPTkApplication();

  QVariant Start(berry::IApplicationContext* context) override;
  void Stop() override;
};

#endif /*QMITKCAPTKAPPLICATION_H_*/
