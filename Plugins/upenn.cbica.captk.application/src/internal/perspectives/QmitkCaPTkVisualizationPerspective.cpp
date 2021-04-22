/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/

#include "QmitkCaPTkVisualizationPerspective.h"
#include "berryIViewLayout.h"

void QmitkCaPTkVisualizationPerspective::CreateInitialLayout(berry::IPageLayout::Pointer layout)
{
  /////////////////////////////////////////////////////
  // all di-app perspectives should have the following:
  /////////////////////////////////////////////////////

  QString editorArea = layout->GetEditorArea();

  layout->AddStandaloneView("org.mitk.views.datamanager",
    false, berry::IPageLayout::LEFT, 0.3f, editorArea);

  berry::IFolderLayout::Pointer left =
    layout->CreateFolder("org.mitk.captkapplication.leftcontrols",
    berry::IPageLayout::BOTTOM, 0.1f, "org.mitk.views.datamanager");

  layout->AddStandaloneViewPlaceholder("org.mitk.views.imagenavigator",
    berry::IPageLayout::BOTTOM, .4f, "org.mitk.captkapplication.leftcontrols", true);

  /////////////////////////////////////////////
  // here goes the perspective specific stuff
  /////////////////////////////////////////////

  // Adding the entry for the image navigator to the Windows->"Show View" menu
  layout->AddShowViewShortcut("org.mitk.views.imagenavigator");

  layout->AddPerspectiveShortcut("org.mitk.captkapp.defaultperspective");
  layout->AddPerspectiveShortcut("org.mitk.captk.perspectives.editor");
}
