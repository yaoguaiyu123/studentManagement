#ifndef GRADE_H
#define GRADE_H
//成绩类，是一个基类，其子类为关联类
#include <QString>

class Grade
{
public:
    Grade();
    virtual ~Grade();
private:
    QString name;
    int id;  //标识唯一课程

};

#endif // GRADE_H
