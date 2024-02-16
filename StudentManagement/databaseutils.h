#ifndef DATABASEUTILS_H
#define DATABASEUTILS_H
//这个类是连接数据库的工具类
#include <QString>


class DatabaseUtils
{
public:
    DatabaseUtils();
    static void initDatabase();  //初始化函数
    static bool managerLogin(QString username,QString password);
};

#endif // DATABASEUTILS_H
