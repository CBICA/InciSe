/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/
#include "CaPTkCohort.h"

#include "CaPTkCohortSubject.h"

captk::Cohort::Cohort()
{

}

captk::Cohort::~Cohort()
{

}

QString captk::Cohort::GetName()
{
    return m_Name;
}

QList<QSharedPointer<captk::CohortSubject>> captk::Cohort::GetSubjects()
{
    return m_Subjects;
}

void captk::Cohort::SetName(QString name)
{
    m_Name = name;
}

void captk::Cohort::SetSubjects(QList<QSharedPointer<captk::CohortSubject>> subjects)
{
    m_Subjects = subjects;
}