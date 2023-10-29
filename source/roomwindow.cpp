#include "roomwindow.h"

RoomWindow::RoomWindow(){
    RoomUi roomui=RoomUi();
    roomui.setupUi(this);

    cf.getConnectionByName("conference");
    //cf.outputDatabaseInfo();
    QPushButton* btr=findChild<QPushButton*>("pushButton_2");
    connect(btr,&QPushButton::clicked,this,&RoomWindow::addRoom);

}
RoomWindow::RoomWindow(QString name, int number,int capacity,int square,QString discribe,int isUpdate)
{
    RoomUi roomui=RoomUi();
    roomui.setupUi(this);

    cf.getConnectionByName("conference");

    findChild<QLineEdit*>("lineEdit")->setText(name);
    findChild<QLineEdit*>("lineEdit_2")->setText(QString::number(number));
    findChild<QLineEdit*>("lineEdit_2")->setReadOnly(true);
    findChild<QLineEdit*>("lineEdit_3")->setText(QString::number(capacity));
    findChild<QLineEdit*>("lineEdit_4")->setText(QString::number(square));
    findChild<QTextEdit*>("textEdit")->setText(discribe);

    if(isUpdate){
        QPushButton* btr=findChild<QPushButton*>("pushButton_2");
        connect(btr,&QPushButton::clicked,this,&RoomWindow::updateRoom);
    }
}
void RoomWindow::addRoom(){
    QString name=findChild<QLineEdit*>("lineEdit")->text();
    int number=findChild<QLineEdit*>("lineEdit_2")->text().toInt();
    int capacity=findChild<QLineEdit*>("lineEdit_3")->text().toInt();
    int square=findChild<QLineEdit*>("lineEdit_4")->text().toInt();
    QString describe=findChild<QTextEdit*>("textEdit")->toPlainText();
    QString reserve="000000000000";
    Rooms* room=cf.selectQueryRooms(number);
    if(room!=NULL){
        QMessageBox::critical(this,"会议室添加","会议室已存在");
        return;
    }
    cf.insertNameRooms(name,number,capacity,square,describe,reserve);
    QMessageBox::information(this,"会议室添加","会议室添加成功");
}
void RoomWindow::updateRoom(){
    QString name=findChild<QLineEdit*>("lineEdit")->text();
    int number=findChild<QLineEdit*>("lineEdit_2")->text().toInt();
    int capacity=findChild<QLineEdit*>("lineEdit_3")->text().toInt();
    int square=findChild<QLineEdit*>("lineEdit_4")->text().toInt();
    QString describe=findChild<QTextEdit*>("textEdit")->toPlainText();
    cf.updateRooms(name,number,capacity,square,describe);
    QMessageBox::information(this,"会议室修改","会议室修改成功");
}
