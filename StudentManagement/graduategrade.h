#ifndef GRADUATEGRADE_H
#define GRADUATEGRADE_H
//研究生成绩类，继承自Grade,是一个关联类

#include "grade.h"

class GraduateGrade : public Grade
{
public:
    GraduateGrade();
    void research();
};

#endif // GRADUATEGRADE_H
