#include "reservewindow.h"

ReserveWindow::ReserveWindow(const QString &user,const int number,const QDateTime &stime,const QDateTime &etime,const QString &subject,const int capacity,const int state,const QString &describe,const int isView)
{
    ReserveUi reserveUi=ReserveUi();
    reserveUi.setupUi(this);
    findChild<QLabel*>("label_9")->setText(user);
    findChild<QLabel*>("label_10")->setText(QString::number(number));
    findChild<QLabel*>("label_11")->setText(stime.toString("yyyy-MM-dd hh:mm:ss"));
    findChild<QLabel*>("label_12")->setText(etime.toString("yyyy-MM-dd hh:mm:ss"));
    findChild<QLabel*>("label_13")->setText(subject);
    findChild<QLabel*>("label_14")->setText(QString::number(capacity));
    QString strL[4]={"未审批","已审批","驳回","取消"};
    findChild<QLabel*>("label_15")->setText(strL[state]);
    findChild<QTextEdit*>("textEdit")->setText(describe);

    cf.getConnectionByName("conference");

    QPushButton* paBtr=findChild<QPushButton*>("pushButton");   //通过
    QPushButton* rjBtr=findChild<QPushButton*>("pushButton_2"); //驳回
    QPushButton* exBtr=findChild<QPushButton*>("pushButton_3"); //退出查看
    connect(exBtr,&QPushButton::clicked,this,&ReserveWindow::close);
    if(isView){
        findChild<QTextEdit*>("textEdit")->setReadOnly(true);
        paBtr->setVisible(false);
        rjBtr->setVisible(false);
    }else{
        connect(paBtr,&QPushButton::clicked,this,[=](){
            QString user=findChild<QLabel*>("label_9")->text();
            int number=findChild<QLabel*>("label_10")->text().toInt();
            QDateTime stime=QDateTime::fromString(findChild<QLabel*>("label_11")->text(),"yyyy-MM-dd hh:mm:ss");
            QDateTime etime=QDateTime::fromString(findChild<QLabel*>("label_12")->text(),"yyyy-MM-dd hh:mm:ss");
            QString describe=findChild<QTextEdit*>("textEdit")->toPlainText();
            describe+=" 通过时间:"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            cf.updateReserves(user,number,stime,etime,0,describe,1);
        });
        connect(rjBtr,&QPushButton::clicked,this,[=](){
            QString user=findChild<QLabel*>("label_9")->text();
            int number=findChild<QLabel*>("label_10")->text().toInt();
            QDateTime stime=QDateTime::fromString(findChild<QLabel*>("label_11")->text(),"yyyy-MM-dd hh:mm:ss");
            QDateTime etime=QDateTime::fromString(findChild<QLabel*>("label_12")->text(),"yyyy-MM-dd hh:mm:ss");
            QString describe=findChild<QTextEdit*>("textEdit")->toPlainText();
            describe+=" 驳回时间:"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            cf.updateReserves(user,number,stime,etime,0,describe,2);
        });
    }
}
