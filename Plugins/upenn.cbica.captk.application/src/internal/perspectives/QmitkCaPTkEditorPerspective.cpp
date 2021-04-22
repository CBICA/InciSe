/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/

#include "QmitkCaPTkEditorPerspective.h"

void QmitkCaPTkEditorPerspective::CreateInitialLayout(berry::IPageLayout::Pointer layout)
{
  layout->GetEditorArea();

  layout->AddPerspectiveShortcut("org.mitk.captkapp.defaultperspective");
  layout->AddPerspectiveShortcut("org.mitk.captk.perspectives.visualization");
}
