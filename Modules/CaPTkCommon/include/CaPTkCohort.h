/**
contact: software@cbica.upenn.edu
Copyright (c) 2018 University of Pennsylvania. All rights reserved.
Use of this source code is governed by license located in license file:
https://github.com/CBICA/InciSe/blob/main/LICENSE
**/
#ifndef CaPTkCohort_h
#define CaPTkCohort_h

// The following header file is generated by CMake and thus it's located in
// the build directory. It provides an export macro for classes and functions
// that you want to be part of the public interface of your module.
#include <MitkCaPTkCommonExports.h>

namespace captk
{
class CohortSubject;
}

#include <QString>
#include <QList>
#include <QSharedPointer>

namespace captk
{
/** \class Cohort
 * \brief Defines information about a cohort
 * and holds the list of cohort's various subjects.
 */
class MITKCAPTKCOMMON_EXPORT Cohort
{
public:
    Cohort();

    ~Cohort();

    /* Getters */

    QString GetName();

    QList<QSharedPointer<CohortSubject>> GetSubjects();

    /* Setters */

    void SetName(QString name);

    void SetSubjects(QList<QSharedPointer<CohortSubject>> subjects);

private:
    QString m_Name;
    QList<QSharedPointer<CohortSubject>> m_Subjects;
};
}

#endif // ! CaPTkCohort_h