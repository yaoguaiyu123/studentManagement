#include "dialog.h"
#include <QLineEdit>
#include <QDebug>
#include <QFont>
#include <QMessageBox>
#include "databaseutils.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    // 布局
    resize(360, 300);
    setWindowTitle("学生管理系统---登录页面");
    titleLabel = new QLabel("欢迎来到学生管理系统");
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont font = QFont("DFKai-SB", 14);
    titleLabel->setFont(font);
    button1 = new QPushButton("登录");
    button2 = new QPushButton("注册");
    loginButton = new QPushButton("登录");
    registerButton = new QPushButton("注册");
    stackWidget = new QStackedWidget();
    // 第一个分窗口
    QWidget* widget1 = new QWidget();
    QLabel* label11 = new QLabel("账号");
    QLabel* label12 = new QLabel("密码");
    lineEdit11 = new QLineEdit();
    lineEdit11->setPlaceholderText("请输入学号或职工号");
    lineEdit12 = new QLineEdit();
    lineEdit12->setPlaceholderText("请输入密码");
    QGridLayout* layout1 = new QGridLayout(widget1);
    layout1->addWidget(label11, 0, 0);
    layout1->addWidget(lineEdit11, 0, 1);
    layout1->addWidget(label12, 1, 0);
    layout1->addWidget(lineEdit12, 1, 1);
    layout1->addWidget(loginButton, 2, 1);
    stackWidget->addWidget(widget1);
    // 第二个分窗口
    QWidget* widget2 = new QWidget();
    QLabel* label21 = new QLabel("账号");
    QLabel* label22 = new QLabel("密码");
    QLabel* label23 = new QLabel("确认密码");
    lineEdit21 = new QLineEdit();
    lineEdit21->setPlaceholderText("请输入学号或职工号");
    lineEdit22 = new QLineEdit();
    lineEdit22->setPlaceholderText("请输入密码");
    lineEdit23 = new QLineEdit();
    lineEdit23->setPlaceholderText("请再次输入密码");
    QGridLayout* layout2 = new QGridLayout(widget2);
    layout2->addWidget(label21, 0, 0);
    layout2->addWidget(lineEdit21, 0, 1);
    layout2->addWidget(label22, 1, 0);
    layout2->addWidget(lineEdit22, 1, 1);
    layout2->addWidget(label23, 2, 0);
    layout2->addWidget(lineEdit23, 2, 1);
    layout2->addWidget(registerButton, 3, 1);
    stackWidget->addWidget(widget2);
    // 总窗口
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(titleLabel, 0, 0, 1, 2);
    mainLayout->addWidget(button1, 1, 0);
    mainLayout->addWidget(button2, 1, 1);
    mainLayout->addWidget(stackWidget, 2, 0, 3, 2);
    // 连接槽函数
    connect(button1, SIGNAL(clicked(bool)), this, SLOT(clickedButton1()));
    connect(button2, SIGNAL(clicked(bool)), this, SLOT(clickedButton2()));
    connect(loginButton, SIGNAL(clicked(bool)), this, SLOT(clickedLoginButton()));
}

void Dialog::clickedButton1()
{
    stackWidget->setCurrentIndex(0);
}

void Dialog::clickedButton2(){
    stackWidget->setCurrentIndex(1);
}

void Dialog::clickedLoginButton(){
//    qDebug() << "登录点击";
    if (lineEdit11->text() == "" || lineEdit12->text() == "") {
//        qDebug() << "null";
        return;
    }
    //连接数据库进行校验
    if (DatabaseUtils::managerLogin(lineEdit11->text(), lineEdit12->text())) {
        QMessageBox::information(nullptr, "登录成功", QObject::tr("欢迎管理员%1的到来").arg(lineEdit11->text()), QMessageBox::Ok);
        accept();
    } else {
        QMessageBox::information(nullptr, "登录失败", "用户名或密码错误", QMessageBox::Ok);
    }
}

void Dialog::clickedRegisterButton(){

}

Dialog::~Dialog()
{
}

