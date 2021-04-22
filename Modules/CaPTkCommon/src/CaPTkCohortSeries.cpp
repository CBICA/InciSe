/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/
#include "CaPTkCohortSeries.h"

#include "CaPTkCohortImage.h"

#include "mitkException.h"
#include "mitkLogMacros.h"
#include "mitkIOUtil.h"

captk::CohortSeries::CohortSeries()
{

}

captk::CohortSeries::~CohortSeries()
{

}

QString captk::CohortSeries::GetModality()
{
    return m_Modality;
}

QString captk::CohortSeries::GetSeriesDescription()
{
    return m_SeriesDescription;
}

QString captk::CohortSeries::GetSegmentLabel()
{
    return m_SegmentLabel;
}

QList<QSharedPointer<captk::CohortImage>> captk::CohortSeries::GetImages()
{
    return m_Images; 
}

mitk::Image::Pointer captk::CohortSeries::LoadImagesAsOne()
{
    mitk::Image::Pointer image;

    if (this->GetImages().size() > 0)
    {
        try
        {
            // Load the first one and the others will follow
            // automatically
            // TODO: what happens when they are not in the same dir?
            auto path = this->GetImages()[0]->GetPath();
            image = mitk::IOUtil::Load<mitk::Image>(path.toStdString());
        }
        catch (mitk::Exception& e)
        {
            MITK_ERROR << "Exception caught: " << e.GetDescription();
        }        
    }

    return image;
}

mitk::LabelSetImage::Pointer captk::CohortSeries::LoadSegmentationImagesAsOne()
{
    mitk::LabelSetImage::Pointer image;

    if (this->GetImages().size() > 0)
    {
        try
        {
            // Load the first one and the others will follow
            // automatically
            // TODO: what happens when they are not in the same dir?
            auto path = this->GetImages()[0]->GetPath();
            image = mitk::IOUtil::Load<mitk::LabelSetImage>(path.toStdString());
        }
        catch (mitk::Exception& e)
        {
            MITK_ERROR << "Exception caught: " << e.GetDescription();
        }        
    }

    return image;
}

void captk::CohortSeries::SetModality(QString modality)
{
    m_Modality = modality;
}

void captk::CohortSeries::SetSeriesDescription(QString seriesDescription)
{
    m_SeriesDescription = seriesDescription;
}

void captk::CohortSeries::SetSegmentLabel(QString segmentLabel)
{
    m_SegmentLabel = segmentLabel;
}

void captk::CohortSeries::SetImages(QList<QSharedPointer<captk::CohortImage>> images)
{
    m_Images = images;
}