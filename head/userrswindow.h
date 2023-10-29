#ifndef USERRSWINDOW_H
#define USERRSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include <QCheckBox>
#include "reservewindow.h"
#include "mycfsql.h"
QT_BEGIN_NAMESPACE

class UserRsUi
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QComboBox *comboBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(445, 329);
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
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(pushButton);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setLayoutDirection(Qt::LeftToRight);
        comboBox->setAutoFillBackground(false);

        verticalLayout->addWidget(comboBox);


        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\256\241\347\220\206\351\242\204\347\272\246\347\225\214\351\235\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "    \346\234\252\345\256\241\346\211\271", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "    \345\267\262\345\256\241\346\211\271", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "    \351\251\263\345\233\236", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "    \345\217\226\346\266\210", nullptr));

    } // retranslateUi

};

QT_END_NAMESPACE

class UserRsWindow:public QMainWindow
{
private:
    QString user_name;
    MyCfSql cf;
public:
    UserRsWindow(QString name);
    void newReserveWindow(int isView);    
    void addItem(QString str);    //向下拉式选项框添加元素
    void cancelItem();    //取消预约
    void updateRs();    //更新界面
};

#endif // USERRSWINDOW_H
