#ifndef STUDENT_H
#define STUDENT_H
//学生类，是一个基类
#include <QString>

class Student {
private:
    QString name;
    int id;
    QString username, password;  //用于登录系统
public:
    Student();
    virtual ~Student();
    virtual void score();  //成绩计算函数,虚函数
};

#endif // STUDENT_H
