/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/

#include "QmitkCaPTkApplicationPlugin.h"
#include "perspectives/QmitkCaPTkDefaultPerspective.h"
#include "perspectives/QmitkCaPTkEditorPerspective.h"
#include "perspectives/QmitkCaPTkVisualizationPerspective.h"
#include "QmitkCaPTkIntroPart.h"
#include "QmitkCaPTkApplication.h"

#include "mitkWorkbenchUtil.h"
#include <mitkVersion.h>
#include <mitkLogMacros.h>

#include <service/cm/ctkConfigurationAdmin.h>
#include <service/cm/ctkConfiguration.h>

#include <QFileInfo>
#include <QDateTime>

QmitkCaPTkApplicationPlugin* QmitkCaPTkApplicationPlugin::inst = nullptr;

QmitkCaPTkApplicationPlugin::QmitkCaPTkApplicationPlugin()
{
  inst = this;
}

QmitkCaPTkApplicationPlugin::~QmitkCaPTkApplicationPlugin()
{
}

QmitkCaPTkApplicationPlugin* QmitkCaPTkApplicationPlugin::GetDefault()
{
  return inst;
}

void QmitkCaPTkApplicationPlugin::start(ctkPluginContext* context)
{
  berry::AbstractUICTKPlugin::start(context);

  this->context = context;

  BERRY_REGISTER_EXTENSION_CLASS(QmitkCaPTkDefaultPerspective, context);
  BERRY_REGISTER_EXTENSION_CLASS(QmitkCaPTkEditorPerspective, context);
  BERRY_REGISTER_EXTENSION_CLASS(QmitkCaPTkIntroPart, context);
  BERRY_REGISTER_EXTENSION_CLASS(QmitkCaPTkApplication, context);
  BERRY_REGISTER_EXTENSION_CLASS(QmitkCaPTkVisualizationPerspective, context);


  ctkServiceReference cmRef = context->getServiceReference<ctkConfigurationAdmin>();
  ctkConfigurationAdmin* configAdmin = nullptr;
  if (cmRef)
  {
    configAdmin = context->getService<ctkConfigurationAdmin>(cmRef);
  }

  // Use the CTK Configuration Admin service to configure the BlueBerry help system
  if (configAdmin)
  {
    ctkConfigurationPtr conf = configAdmin->getConfiguration("org.blueberry.services.help", QString());
    ctkDictionary helpProps;
    helpProps.insert("homePage", "qthelp://upenn.cbica.captk.application/bundle/index.html");
    conf->update(helpProps);
    context->ungetService(cmRef);
  }
  else
  {
    MITK_WARN << "Configuration Admin service unavailable, cannot set home page url.";
  }

  // Set CBICA logo
  mitk::WorkbenchUtil::SetDepartmentLogoPreference(":/upenn.cbica.captk.application/cbica-logo.png", context);
}

ctkPluginContext* QmitkCaPTkApplicationPlugin::GetPluginContext() const
{
  return context;
}
