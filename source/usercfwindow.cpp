#include "usercfwindow.h"

UserCfWindow::UserCfWindow(QString name){
    UserCfUi userCfUi=UserCfUi();
    userCfUi.setupUi(this);
    //初始化成员//
    user_name=name;
    cf.getConnectionByName("conference");

    //初始化信号和槽//
    QPushButton* fiBtr=findChild<QPushButton*>("pushButton");
    QPushButton* reBtr=findChild<QPushButton*>("pushButton_2");
    QPushButton* viBtr=findChild<QPushButton*>("pushButton_3");
    connect(fiBtr,&QPushButton::clicked,this,&UserCfWindow::filter);
    connect(reBtr,&QPushButton::clicked,this,&UserCfWindow::reserve);
    connect(viBtr,&QPushButton::clicked,this,&UserCfWindow::view);
}

void UserCfWindow::addItem(QString str){
    QListWidget* p=findChild<QListWidget*>("listWidget");
    QListWidgetItem *item = new QListWidgetItem(p);
    QCheckBox* checkbox = new QCheckBox;
    checkbox->setText(str);
    item->setSizeHint(QSize(0,20));
    p->addItem(item);
    p->setItemWidget(item, checkbox);
}

void UserCfWindow::filter(){
    QListWidget* listWidget=findChild<QListWidget*>("listWidget");
    int counter = listWidget->count();
    QListWidgetItem *item;
    for(int index = 0;index <counter;index++){
        item = listWidget->takeItem(0);
        if(item !=NULL)
            delete item;
    }
    QTime stime=findChild<QTimeEdit*>("timeEdit")->time();
    QTime etime=findChild<QTimeEdit*>("timeEdit_2")->time();
    if(stime>=etime){
        QMessageBox::critical(this,"筛选会议室","时间错误");
        return;
    }
    QDate date=findChild<QDateEdit*>("dateEdit")->date();
    QDateTime sdateTime=QDateTime::fromString(date.toString()+" "+stime.toString());
    QDateTime edateTime=QDateTime::fromString(date.toString()+" "+etime.toString());
    //qDebug()<<stime<<etime<<date<<user_name<<sdateTime;
    Reserves* reserve=cf.selectQueryReserves(sdateTime,edateTime);
    QList<int> list;
    if(reserve!=NULL){
        for(int i=0;i<30;i++){
            if(reserve[i].number==-1) break;
            list.append(reserve[i].number);
        }
    }
    Rooms* room=cf.queryAllRooms();
    int capacity=findChild<QLineEdit*>("lineEdit_2")->text().toInt();
    for(int i=0;i<30;i++){
        if(room[i].number==-1) break;
        if(!list.contains(room[i].number)&&room[i].capacity>=capacity){
            QString str=room[i].name+" "+QString::number(room[i].number)+" 容量"+QString::number(room[i].capacity)+"人";
            addItem(str);
        }
    }
    update();
}

void UserCfWindow::reserve(){
    QListWidget* listwidget=findChild<QListWidget*>("listWidget");
    for(int i = 0; i < listwidget->count(); i++){
        QListWidgetItem *item = listwidget->item(i);
        //将QWidget 转化为QCheckBox  获取第i个item 的控件
        QCheckBox *checkbox = static_cast<QCheckBox *>(listwidget->itemWidget(item));
        if(checkbox->isChecked()){
            int number = checkbox->text().split(" ")[1].toInt();
            QTime stime=findChild<QTimeEdit*>("timeEdit")->time();
            QTime etime=findChild<QTimeEdit*>("timeEdit_2")->time();
            QDate date=findChild<QDateEdit*>("dateEdit")->date();
            QDateTime sdateTime=QDateTime::fromString(date.toString()+" "+stime.toString());
            QDateTime edateTime=QDateTime::fromString(date.toString()+" "+etime.toString());
            QString subject=findChild<QLineEdit*>("lineEdit")->text();
            int capacity=findChild<QLineEdit*>("lineEdit_2")->text().toInt();
            cf.insetNameReserves(user_name,number,sdateTime,edateTime,subject,capacity,0,"");
            filter();
            return;
        }
    }
    QMessageBox::critical(this,"会议室预约","没有选择会议室");
}

void UserCfWindow::view(){
    QListWidget* listwidget=findChild<QListWidget*>("listWidget");
    for(int i = 0; i < listwidget->count(); i++){
        QListWidgetItem *item = listwidget->item(i);
        //将QWidget 转化为QCheckBox  获取第i个item 的控件
        QCheckBox *checkbox = static_cast<QCheckBox *>(listwidget->itemWidget(item));
        if(checkbox->isChecked()){
            int number = checkbox->text().split(" ")[1].toInt();
            Rooms* room=cf.selectQueryRooms(number);
            RoomWindow* p=new RoomWindow(room->name,room->number,room->capacity,room->square,room->describe,0);
            QPushButton* btr=p->findChild<QPushButton*>("pushButton_2");
            connect(btr,&QPushButton::clicked,p,&QMainWindow::close);
            p->show();
            return;
        }
    }
    QMessageBox::critical(this,"会议室查看","没有选择会议室");
}
