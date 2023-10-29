#ifndef ADMINCFWINDOW_H
#define ADMINCFWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include <QCheckBox>
#include "roomwindow.h"
QT_BEGIN_NAMESPACE

class AdminCfUi
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(381, 302);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        horizontalLayout->addWidget(listWidget);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);


        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230\347\225\214\351\235\242", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

QT_END_NAMESPACE


class AdminCfWindow:public QMainWindow
{
private:
    MyCfSql cf;
public:
    AdminCfWindow();
    void addItem(QString str);    //添加会议室
    void delItem();    //删除会议室
    void updateCf();    //更新界面
    void updateItem();    //更新会议室
};

#endif // ADMINCFWINDOW_H
