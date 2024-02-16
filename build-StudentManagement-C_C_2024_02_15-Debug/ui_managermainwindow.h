/********************************************************************************
** Form generated from reading UI file 'managermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERMAINWINDOW_H
#define UI_MANAGERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerMainWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManagerMainWindow)
    {
        if (ManagerMainWindow->objectName().isEmpty())
            ManagerMainWindow->setObjectName("ManagerMainWindow");
        ManagerMainWindow->resize(800, 600);
        menubar = new QMenuBar(ManagerMainWindow);
        menubar->setObjectName("menubar");
        ManagerMainWindow->setMenuBar(menubar);
        centralwidget = new QWidget(ManagerMainWindow);
        centralwidget->setObjectName("centralwidget");
        ManagerMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ManagerMainWindow);
        statusbar->setObjectName("statusbar");
        ManagerMainWindow->setStatusBar(statusbar);

        retranslateUi(ManagerMainWindow);

        QMetaObject::connectSlotsByName(ManagerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ManagerMainWindow)
    {
        ManagerMainWindow->setWindowTitle(QCoreApplication::translate("ManagerMainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagerMainWindow: public Ui_ManagerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERMAINWINDOW_H
