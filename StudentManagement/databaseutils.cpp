#include "databaseutils.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

DatabaseUtils::DatabaseUtils()
{
    ;
}

// 初始化数据库，创建数据库表
void DatabaseUtils::initDatabase()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("studentManage");
    if (!database.open()) {
        QMessageBox::information(nullptr, "数据库创建", "studentManage数据库创建失败", QMessageBox::Ok);
        return;
    }
    QMessageBox::information(nullptr, "数据库创建", "studentManage数据库创建成功", QMessageBox::Ok);
    QSqlQuery query;
    //创建管理员表
    query.exec("create table manager (username varchar(40) unique,password varchar(40))");
    //创建学生表
    query.exec("create table student (id int primary key,name varchar(40),"
               "username varchar(40) unique,password varchar(40))");
    //创建课程表
    query.exec("create table course (id int primary key,name varchar(40))");
    //创建成绩表(连接学生表和课程表)
    query.exec("create table grade ("
               "id int primary key, "
               "studentId INT, "
               "courseId INT, "
               "score double DEFAULT -1, "
               "midterm double, "
               "final double, "
               "homework double, "
               "prictice double DEFAULT -1, "
               "thesis double DEFAULT -1 ,"
               "FOREIGN KEY (studentId) REFERENCES student(id), "
               "FOREIGN KEY (courseId) REFERENCES course(id)"
               ")");
    query.exec("insert into student values(1,'大渊','2022051615114','123456')");
    query.exec("insert into student values(2,'疯子狗蛋','2022051615116','123456')");
    query.exec("insert into student values(3,'坤坤','2022051615145','123456')");
    query.exec("insert into student values(4,'甜饼干','2022051615231','123456')");
    query.exec("insert into student values(5,'山药将军','2022051615136','123456')");
    query.exec("insert into student values(6,'苹果商人','2022051615130','123456')");
    query.exec("insert into course values(1,'语文')");
    query.exec("insert into course values(2,'数学')");
//    qDebug() << query.lastError().text();
    query.exec("insert into grade values(1,1,1,-1,98,99,99,98,-1)");
    query.exec("insert into grade values(2,2,2,-1,45,60,77,20,-1)");
    query.exec("insert into grade values(3,2,2,-1,96,60,78,36,-1)");
    query.exec("insert into grade values(4,3,1,-1,90,75,56,89,-1)");
}

bool DatabaseUtils::managerLogin(QString username, QString password)
{
    if (username == "ddd" && password == "123456") {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("studentManage");
        if (db.open()) {
            return true;
        }
    }
    return false;
}
