/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/
#ifndef MITKPLUGINACTIVATOR_H
#define MITKPLUGINACTIVATOR_H

// Parent classes
#include <berryAbstractUICTKPlugin.h>

namespace mitk
{
  class PluginActivator : public berry::AbstractUICTKPlugin
  {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "upenn_cbica_captk_common")
    Q_INTERFACES(ctkPluginActivator)

  public:

    PluginActivator();
    ~PluginActivator();

    void start(ctkPluginContext *context) override;
    void stop(ctkPluginContext *context) override;

    static PluginActivator* getDefault();

    static ctkPluginContext* getContext();

  private:

    static ctkPluginContext* m_context;
    static PluginActivator* m_Instance;
  };
}

#endif
