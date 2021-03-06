/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/
#include "CaPTkCohortStudy.h"

#include "CaPTkCohortSeries.h"

captk::CohortStudy::CohortStudy()
{

}

captk::CohortStudy::~CohortStudy()
{

}

QString captk::CohortStudy::GetName()
{
    return m_Name;
}

QList<QSharedPointer<captk::CohortSeries>> captk::CohortStudy::GetSeries()
{
    return m_Series;
}

void captk::CohortStudy::SetName(QString name)
{
    m_Name = name;
}

void captk::CohortStudy::SetSeries(QList<QSharedPointer<captk::CohortSeries>> series)
{
    m_Series = series;
}