#ifndef DIALOG_H
#define DIALOG_H
//这个类是系统登录页面

#include <QDialog>
#include <QPushButton>
#include <QStackedWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QLabel* titleLabel;
    QStackedWidget* stackWidget;
    QPushButton *button1, *button2, *loginButton, *registerButton;
    QGridLayout* mainLayout;
    QLineEdit *lineEdit11, *lineEdit12, *lineEdit21, *lineEdit22, *lineEdit23;
private slots:
    void clickedButton1();
    void clickedButton2();
    void clickedLoginButton();
    void clickedRegisterButton();

};
#endif // DIALOG_H
