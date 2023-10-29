#ifndef USERCFWINDOW_H
#define USERCFWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

#include <QMessageBox>
#include <QList>
#include <QCheckBox>
#include "mycfsql.h"
#include "roomwindow.h"
QT_BEGIN_NAMESPACE

class UserCfUi
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QTimeEdit *timeEdit;
    QTimeEdit *timeEdit_2;
    QDateEdit *dateEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(445, 329);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        gridLayout_2->addWidget(widget_2, 1, 1, 1, 1);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        gridLayout_2->addWidget(listWidget, 0, 1, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 4, 1, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 5, 1, 1, 1);

        timeEdit = new QTimeEdit(widget);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setMaximumTime(QTime(20, 0, 0));
        timeEdit->setMinimumTime(QTime(8, 0, 0));
        timeEdit->setTime(QTime(8, 0, 0));

        gridLayout->addWidget(timeEdit, 2, 1, 1, 1);

        timeEdit_2 = new QTimeEdit(widget);
        timeEdit_2->setObjectName("timeEdit_2");
        timeEdit_2->setMaximumTime(QTime(20, 0, 0));
        timeEdit_2->setMinimumTime(QTime(8, 0, 0));
        timeEdit_2->setTime(QTime(8, 0, 0));

        gridLayout->addWidget(timeEdit_2, 3, 1, 1, 1);

        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setMaximumDateTime(QDateTime(QDate(2023, 12, 31), QTime(23, 59, 59)));
        dateEdit->setMinimumDateTime(QDateTime(QDate(2023, 10, 28), QTime(0, 0, 0)));

        gridLayout->addWidget(dateEdit, 1, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 4, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        gridLayout_2->addWidget(pushButton, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\242\204\347\272\246\344\274\232\350\256\256\345\256\244\347\225\214\351\235\242", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\351\242\204\347\272\246", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", nullptr));
        timeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "H:00", nullptr));
        timeEdit_2->setDisplayFormat(QCoreApplication::translate("MainWindow", "H:00", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "M/d", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\344\274\232\350\256\256\344\272\272\346\225\260\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\344\274\232\350\256\256\344\270\273\351\242\230\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\255\233\351\200\211", nullptr));
    } // retranslateUi

};

QT_END_NAMESPACE

class UserCfWindow: public QMainWindow
{
private:
    QString user_name;
    MyCfSql cf;
public:
    UserCfWindow(QString name);
    void addItem(QString str);
    void filter();    //筛选会议室并更新界面
    void reserve();    //预约会议室
    void view();    //查看会议室
};

#endif // USERCFWINDOW_H


