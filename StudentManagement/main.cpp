// Date:2024/2/15
// Author:妖怪鱼
// Introduction:学生管理系统
// 先进行简单化处理，只有管理员访问系统
// 有一个问题，就是怎么思考关联类与数据库的平衡，有了数据库之后，所有的数据都可以使用数据库查看，似乎没有必要采用关联类的形式获取数据
// 这里先实现主要的功能，关联类的实现之后再进行补充
#include "dialog.h"
#include <QApplication>
#include "databaseutils.h"
#include "managermainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    DatabaseUtils::initDatabase();
    Dialog dialog;
    dialog.show();
    if (dialog.exec() != QDialog::Accepted) {
        return -1;
    }
    ManagerMainWindow managerMainWindow;
    managerMainWindow.show();
    return a.exec();
}
