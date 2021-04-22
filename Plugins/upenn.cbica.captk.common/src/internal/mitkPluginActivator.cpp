/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/
#include "mitkPluginActivator.h"

#include "QmitkCaPTkSplitLabelsToImagesAction.h"

using namespace mitk;

ctkPluginContext* PluginActivator::m_context = nullptr;
PluginActivator* PluginActivator::m_Instance = nullptr;

PluginActivator::PluginActivator()
{
  m_Instance = this;
}

PluginActivator::~PluginActivator()
{
  m_Instance = nullptr;
}

void PluginActivator::start(ctkPluginContext *context)
{
  BERRY_REGISTER_EXTENSION_CLASS(QmitkCaPTkSplitLabelsToImagesAction, context)

  this->m_context = context;
}

void PluginActivator::stop(ctkPluginContext *)
{
  this->m_context = nullptr;
}

PluginActivator* PluginActivator::getDefault()
{
  return m_Instance;
}

ctkPluginContext*PluginActivator::getContext()
{
  return m_context;
}
