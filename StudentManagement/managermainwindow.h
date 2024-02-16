#ifndef MANAGERMAINWINDOW_H
#define MANAGERMAINWINDOW_H
//管理员的主界面类
#include <QMainWindow>
#include <QGroupBox>
#include <QTableView>
#include <QListWidget>
#include <QLabel>
#include <QFile>
#include <QSqlRelationalTableModel>

namespace Ui {
class ManagerMainWindow;
}

class ManagerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagerMainWindow(QWidget *parent = nullptr);
    ~ManagerMainWindow();

private:
    Ui::ManagerMainWindow *ui;
    QSqlTableModel *studentModel, *courseModel;
    QSqlRelationalTableModel* gradeModel;
    QTableView *studentView, *courseView, *gradeView;

    QGroupBox* getStudentBox();
    QGroupBox* getCourseBox();
    QGroupBox* getGradeBox();

};

#endif // MANAGERMAINWINDOW_H
