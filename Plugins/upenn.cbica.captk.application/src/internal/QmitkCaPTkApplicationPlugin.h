/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/


#ifndef QMITKCAPTKAPPLICATIONPLUGIN_H_
#define QMITKCAPTKAPPLICATIONPLUGIN_H_

#include <berryAbstractUICTKPlugin.h>

#include <QString>

class QmitkCaPTkApplicationPlugin : public berry::AbstractUICTKPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "upenn_cbica_captk_application")
  Q_INTERFACES(ctkPluginActivator)

public:

  QmitkCaPTkApplicationPlugin();
  ~QmitkCaPTkApplicationPlugin() override;

  static QmitkCaPTkApplicationPlugin* GetDefault();

  ctkPluginContext* GetPluginContext() const;

  void start(ctkPluginContext*) override;

  QString GetQtHelpCollectionFile() const;

private:

  static QmitkCaPTkApplicationPlugin* inst;

  ctkPluginContext* context;
};

#endif /* QMITKCAPTKAPPLICATIONPLUGIN_H_ */
