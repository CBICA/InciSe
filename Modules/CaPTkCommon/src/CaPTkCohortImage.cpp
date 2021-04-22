/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/
#include "CaPTkCohortImage.h"

captk::CohortImage::CohortImage()
{

}

captk::CohortImage::~CohortImage()
{

}

QString captk::CohortImage::GetPath()
{
    return m_Path;
}

QString captk::CohortImage::GetImageInfoPath()
{
    return m_ImageInfoPath;
}

void captk::CohortImage::SetPath(QString path)
{
    m_Path = path;
}

void captk::CohortImage::SetImageInfoPath(QString imageInfoPath)
{
    m_ImageInfoPath = imageInfoPath;
}