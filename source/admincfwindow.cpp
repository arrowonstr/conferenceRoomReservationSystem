#include "admincfwindow.h"

AdminCfWindow::AdminCfWindow()
{
    AdminCfUi adminCfUi=AdminCfUi();
    adminCfUi.setupUi(this);

    //初始化成员//
    cf.getConnectionByName("conference");

    //初始化信号和槽//
    QPushButton* addBtr=findChild<QPushButton*>("pushButton");  //添加
    QPushButton* delBtr=findChild<QPushButton*>("pushButton_2");    //删除
    QPushButton* updBtr=findChild<QPushButton*>("pushButton_3");    //修改
    connect(addBtr,&QPushButton::clicked,this,[=](){
        RoomWindow* p=new RoomWindow();
        QPushButton* btr=p->findChild<QPushButton*>("pushButton_2");
        connect(btr,&QPushButton::clicked,this,&AdminCfWindow::updateCf);
        p->show();
    });
    connect(delBtr,&QPushButton::clicked,this,&AdminCfWindow::delItem);
    connect(updBtr,&QPushButton::clicked,this,&AdminCfWindow::updateItem);

    updateCf();
}

void AdminCfWindow::addItem(QString str){   //添加会议室
    QListWidget* p=findChild<QListWidget*>("listWidget");
    QListWidgetItem *item = new QListWidgetItem(p);
    QCheckBox* checkbox = new QCheckBox;
    checkbox->setText(str);
    item->setSizeHint(QSize(0,20));
    p->addItem(item);
    p->setItemWidget(item, checkbox);
}
void AdminCfWindow::delItem(){  //删除会议室
    QListWidget* listwidget=findChild<QListWidget*>("listWidget");
    for(int i = 0; i < listwidget->count(); i++){
        QListWidgetItem *item = listwidget->item(i);
        //将QWidget 转化为QCheckBox  获取第i个item 的控件
        QCheckBox *checkbox = static_cast<QCheckBox *>(listwidget->itemWidget(item));
        if(checkbox->isChecked())
        {
            QString checkboxStr = checkbox->text().split(" ")[1];
            cf.deleteRooms(checkboxStr.toInt());
        }
    }
    updateCf();
}
void  AdminCfWindow::updateItem(){  //修改会议室
    QListWidget* listwidget=findChild<QListWidget*>("listWidget");
    for(int i = 0; i < listwidget->count(); i++){
        QListWidgetItem *item = listwidget->item(i);
        //将QWidget 转化为QCheckBox  获取第i个item 的控件
        QCheckBox *checkbox = static_cast<QCheckBox *>(listwidget->itemWidget(item));
        if(checkbox->isChecked()){
            QString checkboxStr = checkbox->text().split(" ")[1];
            Rooms* room=cf.selectQueryRooms(checkboxStr.toInt());
            RoomWindow* p=new RoomWindow(room->name,room->number,room->capacity,room->square,room->describe,1);
            QPushButton* btr=p->findChild<QPushButton*>("pushButton_2");
            connect(btr,&QPushButton::clicked,this,&AdminCfWindow::updateCf);
            p->show();
            return;
        }
    }
    QMessageBox::critical(this,"会议室修改","没有选择会议室");
}
void AdminCfWindow::updateCf(){ //更新列表
    QListWidget* p=findChild<QListWidget*>("listWidget");
    int counter = p->count();
    QListWidgetItem *item;
    for(int index = 0;index <counter;index++){
        item = p->takeItem(0);
        if(item !=NULL)
            delete item;
    }
    Rooms* rooms=cf.queryAllRooms();
    for(int i=0;i<30;i++){
        if(rooms[i].number==-1) break;
        QString str=rooms[i].name+" "+QString::number(rooms[i].number)+" 容量"+QString::number(rooms[i].capacity)+"人";
        addItem(str);
    }
    update();
}
