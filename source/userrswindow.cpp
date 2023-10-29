#include "userrswindow.h"

UserRsWindow::UserRsWindow(QString name){
    UserRsUi usRsUi=UserRsUi();
    usRsUi.setupUi(this);
    user_name=name;
    cf.getConnectionByName("conference");

    QPushButton* clBtr=findChild<QPushButton*>("pushButton");   //取消按钮
    QPushButton* viBtr=findChild<QPushButton*>("pushButton_2"); //查看按钮
    QComboBox* box=findChild<QComboBox*>("comboBox");   //下拉选项框
    connect(clBtr,&QPushButton::clicked,this,&UserRsWindow::cancelItem);
    connect(viBtr,&QPushButton::clicked,this,[=](){
        newReserveWindow(1);
    });
    connect(box,&QComboBox::currentIndexChanged,this,&UserRsWindow::updateRs);
    updateRs();
}
void UserRsWindow::newReserveWindow(int isView){
    QListWidget* listwidget=findChild<QListWidget*>("listWidget");
    for(int i = 0; i < listwidget->count(); i++){
        QListWidgetItem *item = listwidget->item(i);
        //将QWidget 转化为QCheckBox  获取第i个item 的控件
        QCheckBox *checkbox = static_cast<QCheckBox *>(listwidget->itemWidget(item));
        if(checkbox->isChecked())
        {
            QStringList checkboxStr = checkbox->text().split(" ");
            int number=checkboxStr[0].toInt();
            QDateTime stime=QDateTime::fromString(checkboxStr[2]+" "+checkboxStr[3],"yyyy-MM-dd hh:mm:ss");
            QDateTime etime=QDateTime::fromString(checkboxStr[5]+" "+checkboxStr[6],"yyyy-MM-dd hh:mm:ss");
            int state=findChild<QComboBox*>("comboBox")->currentIndex();
            Reserves* reserve=cf.selectQueryReserves(user_name,number,stime,etime,state);
            ReserveWindow* p=new ReserveWindow(reserve->user,reserve->number,reserve->stime,reserve->etime,reserve->subject,reserve->capacity,reserve->state,reserve->describe,isView);
            p->show();
            return;
        }
    }
}

void UserRsWindow::addItem(QString str){
    QListWidget* p=findChild<QListWidget*>("listWidget");
    QListWidgetItem *item = new QListWidgetItem(p);
    QCheckBox* checkbox = new QCheckBox;
    checkbox->setText(str);
    item->setSizeHint(QSize(0,20));
    p->addItem(item);
    p->setItemWidget(item, checkbox);
}
void UserRsWindow::cancelItem(){    //取消预约
    QListWidget* listwidget=findChild<QListWidget*>("listWidget");
    for(int i = 0; i < listwidget->count(); i++){
        QListWidgetItem *item = listwidget->item(i);
        //将QWidget 转化为QCheckBox  获取第i个item 的控件
        QCheckBox *checkbox = static_cast<QCheckBox *>(listwidget->itemWidget(item));
        if(checkbox->isChecked())
        {
            QStringList checkboxStr = checkbox->text().split(" ");
            int number=checkboxStr[0].toInt();
            QDateTime stime=QDateTime::fromString(checkboxStr[2]+" "+checkboxStr[3],"yyyy-MM-dd hh:mm:ss");
            QDateTime etime=QDateTime::fromString(checkboxStr[5]+" "+checkboxStr[6],"yyyy-MM-dd hh:mm:ss");
            int state=findChild<QComboBox*>("comboBox")->currentIndex();
            cf.updateReserves(user_name,number,stime,etime,state);
        }
    }
    updateRs();
}

void UserRsWindow::updateRs(){    //更新列表
    QListWidget* p=findChild<QListWidget*>("listWidget");
    int counter = p->count();
    QListWidgetItem *item;
    for(int index = 0;index <counter;index++){
        item = p->takeItem(0);
        if(item !=NULL)
            delete item;
    }
    int state=findChild<QComboBox*>("comboBox")->currentIndex();
    QPushButton* clBtr=findChild<QPushButton*>("pushButton");
    if(state==2||state==3) clBtr->setVisible(false);
    else clBtr->setVisible(true);
    Reserves* reserve=cf.selectQueryReserves(user_name,state);
    if(reserve==NULL) return;
    for(int i=0;i<30;i++){
        if(reserve[i].number==-1) break;
        QString str=QString::number(reserve[i].number)+" 开始时间: "+reserve[i].stime.toString("yyyy-MM-dd hh:mm:ss")+" 结束时间 "+reserve[i].etime.toString("yyyy-MM-dd hh:mm:ss");
        addItem(str);
    }
    update();
}



