#include "managermainwindow.h"
#include "ui_managermainwindow.h"
#include <QSqlRecord>
#include <QMessageBox>
#include <QGridLayout>
#include <QWidget>

ManagerMainWindow::ManagerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerMainWindow)
{
//    ui->setupUi(this);
    // 初始化数据
    resize(1400,1100);
    studentModel = new QSqlTableModel(this);
    studentModel->setTable("student"); // todo这里是怎么连接到数据库的
    studentModel->select();
    courseModel = new QSqlTableModel(this);
    courseModel->setTable("course");
    courseModel->select();
    gradeModel = new QSqlRelationalTableModel(this);
    gradeModel->setTable("grade");
    gradeModel->setRelation(1, QSqlRelation("student", "id","name")); // 设置外键
    gradeModel->setRelation(2, QSqlRelation("course", "id","name"));
    gradeModel->select();
    // 布局
    QWidget* widget = new QWidget();
    QGridLayout* mainLayout = new QGridLayout(widget);
    mainLayout->addWidget(getStudentBox(), 0, 0);
    mainLayout->addWidget(getGradeBox(), 0, 1, 2, 2);
    mainLayout->addWidget(getCourseBox(), 1, 0);
    mainLayout->setColumnStretch(0, 1);  // 第一列的拉伸因子为1
    mainLayout->setColumnStretch(1, 2);  // 第二列的拉伸因子为2
    setCentralWidget(widget);
}

QGroupBox* ManagerMainWindow::getStudentBox()
{
    studentView = new QTableView();  //初始化视图
    studentView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑单元格内容
    studentView->setSortingEnabled(true);       //允许用户对表格内容进行排序
    studentView->setSelectionMode(QAbstractItemView::SingleSelection);  //单选
    studentView->setShowGrid(false);  //不显示网格线
    studentView->setAlternatingRowColors(true);   //表格将显示为行颜色交替
    studentView->setModel(studentModel);
    QGroupBox* box = new QGroupBox("学生信息");
    QGridLayout* layout = new QGridLayout();
    layout->addWidget(studentView, 0, 0);
    box->setLayout(layout);
    return box;
}

QGroupBox* ManagerMainWindow::getCourseBox(){
    courseView = new QTableView();
    courseView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    courseView->setSortingEnabled(true);
    courseView->setSelectionMode(QAbstractItemView::SingleSelection);
    courseView->setShowGrid(false);
    courseView->setAlternatingRowColors(true);
    courseView->setModel(courseModel);
    QGroupBox* box = new QGroupBox("课程信息");
    QGridLayout* layout = new QGridLayout();
    layout->addWidget(courseView, 0, 0);
    box->setLayout(layout);
    return box;
}

QGroupBox* ManagerMainWindow::getGradeBox(){
    gradeView = new QTableView();
    gradeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    gradeView->setSortingEnabled(true);
    gradeView->setSelectionMode(QAbstractItemView::SingleSelection);
    gradeView->setShowGrid(false);
    gradeView->setAlternatingRowColors(true);
    gradeView->setModel(gradeModel);
    QGroupBox* box = new QGroupBox("成绩信息");
    QGridLayout* layout = new QGridLayout();
    layout->addWidget(gradeView, 0, 0);
    box->setLayout(layout);
    return box;
}

ManagerMainWindow::~ManagerMainWindow()
{
    delete ui;
}
