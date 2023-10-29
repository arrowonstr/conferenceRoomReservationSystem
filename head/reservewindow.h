#ifndef RESERVEWINDOW_H
#define RESERVEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "mycfsql.h"
QT_BEGIN_NAMESPACE

class ReserveUi
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QSpacerItem *verticalSpacer_3;
    QTextEdit *textEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_8;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(423, 318);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_9 = new QLabel(widget_2);
        label_9->setObjectName("label_9");

        verticalLayout_2->addWidget(label_9);

        label_10 = new QLabel(widget_2);
        label_10->setObjectName("label_10");

        verticalLayout_2->addWidget(label_10);

        label_11 = new QLabel(widget_2);
        label_11->setObjectName("label_11");

        verticalLayout_2->addWidget(label_11);

        label_12 = new QLabel(widget_2);
        label_12->setObjectName("label_12");

        verticalLayout_2->addWidget(label_12);

        label_13 = new QLabel(widget_2);
        label_13->setObjectName("label_13");

        verticalLayout_2->addWidget(label_13);

        label_14 = new QLabel(widget_2);
        label_14->setObjectName("label_14");

        verticalLayout_2->addWidget(label_14);

        label_15 = new QLabel(widget_2);
        label_15->setObjectName("label_15");

        verticalLayout_2->addWidget(label_15);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        textEdit = new QTextEdit(widget_2);
        textEdit->setObjectName("textEdit");

        verticalLayout_2->addWidget(textEdit);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget_3);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_2->addWidget(widget_3);


        gridLayout->addWidget(widget_2, 0, 1, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");

        verticalLayout->addWidget(label_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(widget, 0, 0, 2, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\256\241\347\220\206\351\242\204\347\272\246\347\225\214\351\235\242", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "test", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "000", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "NULL", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "NULL", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "NULL", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "NULL", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\351\200\232\350\277\207", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\351\251\263\345\233\236", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\346\237\245\347\234\213", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\210\277\345\217\267\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\227\245\346\234\237\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\235\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\344\274\232\350\256\256\344\270\273\351\242\230\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\344\272\272\346\225\260", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\350\257\264\346\230\216:", nullptr));
    } // retranslateUi

};

QT_END_NAMESPACE

class ReserveWindow:public QMainWindow
{
private:
    MyCfSql cf;
public:
    ReserveWindow(const QString &user,const int number,const QDateTime &stime,const QDateTime &etime,const QString &subject,const int capacity,const int state,const QString &describe,const int isView);
};

#endif // RESERVEWINDOW_H
