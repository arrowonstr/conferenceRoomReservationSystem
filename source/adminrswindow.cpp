#include "adminrswindow.h"

AdminRsWindow::AdminRsWindow(){
    AdminRsUi adminRsUi=AdminRsUi();
    adminRsUi.setupUi(this);

    cf.getConnectionByName("conference");

    QPushButton* opBtr=findChild<QPushButton*>("pushButton");   //操作按钮
    opBtr->setText("审批");
    QPushButton* viBtr=findChild<QPushButton*>("pushButton_2"); //查看按钮
    QComboBox* box=findChild<QComboBox*>("comboBox");   //下拉选项框
    connect(opBtr,&QPushButton::clicked,this,[=](){
        newReserveWindow(0);
    });
    connect(viBtr,&QPushButton::clicked,this,[=](){
        newReserveWindow(1);
    });
    connect(box,&QComboBox::currentIndexChanged,this,&AdminRsWindow::updateRs);
    updateRs();
}

void AdminRsWindow::newReserveWindow(int isView){
    QListWidget* listwidget=findChild<QListWidget*>("listWidget");
    for(int i = 0; i < listwidget->count(); i++){
        QListWidgetItem *item = listwidget->item(i);
        //将QWidget 转化为QCheckBox  获取第i个item 的控件
        QCheckBox *checkbox = static_cast<QCheckBox *>(listwidget->itemWidget(item));
        if(checkbox->isChecked())
        {
            QStringList checkboxStr = checkbox->text().split(" ");
            QString user=checkboxStr[0];
            int number=checkboxStr[1].toInt();
            QDateTime stime=QDateTime::fromString(checkboxStr[3]+" "+checkboxStr[4],"yyyy-MM-dd hh:mm:ss");
            QDateTime etime=QDateTime::fromString(checkboxStr[6]+" "+checkboxStr[7],"yyyy-MM-dd hh:mm:ss");
            int state=findChild<QComboBox*>("comboBox")->currentIndex();
            Reserves* reserve=cf.selectQueryReserves(user,number,stime,etime,state);
            ReserveWindow* p=new ReserveWindow(reserve->user,reserve->number,reserve->stime,reserve->etime,reserve->subject,reserve->capacity,reserve->state,reserve->describe,isView);
            if(!isView){
                QPushButton* paBtr=p->findChild<QPushButton*>("pushButton");   //通过
                QPushButton* rjBtr=p->findChild<QPushButton*>("pushButton_2"); //驳回
                connect(paBtr,&QPushButton::clicked,this,&AdminRsWindow::updateRs);
                connect(rjBtr,&QPushButton::clicked,this,&AdminRsWindow::updateRs);
            }
            p->show();
            return;
        }
    }
}
void AdminRsWindow::addItem(QString str){
    QListWidget* p=findChild<QListWidget*>("listWidget");
    QListWidgetItem *item = new QListWidgetItem(p);
    QCheckBox* checkbox = new QCheckBox;
    checkbox->setText(str);
    item->setSizeHint(QSize(0,20));
    p->addItem(item);
    p->setItemWidget(item, checkbox);
}

void AdminRsWindow::updateRs(){    //更新列表
    QListWidget* p=findChild<QListWidget*>("listWidget");
    int counter = p->count();
    QListWidgetItem *item;
    for(int index = 0;index <counter;index++){
        item = p->takeItem(0);
        if(item !=NULL)
            delete item;
    }
    int state=findChild<QComboBox*>("comboBox")->currentIndex();
    QPushButton* opBtr=findChild<QPushButton*>("pushButton");
    if(state==0) opBtr->setVisible(true);
    else opBtr->setVisible(false);
    Reserves* reserve=cf.selectQueryReserves(state);
    if(reserve==NULL) return;
    for(int i=0;i<30;i++){
        if(reserve[i].number==-1) break;
        QString str=reserve[i].user+" "+QString::number(reserve[i].number)+" 开始时间: "+reserve[i].stime.toString("yyyy-MM-dd hh:mm:ss")+" 结束时间 "+reserve[i].etime.toString("yyyy-MM-dd hh:mm:ss");
        addItem(str);
    }
    update();
}
