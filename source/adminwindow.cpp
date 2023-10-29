#include "adminwindow.h"

AdminWindow::AdminWindow()
{
    AdminUi adminUi=AdminUi();
    adminUi.setupUi(this);

    QPushButton* cfBtr=findChild<QPushButton*>("pushButton");   //管理会议室按钮
    QPushButton* rsBtr=findChild<QPushButton*>("pushButton_2");   //管理预约按钮
    connect(cfBtr,&QPushButton::clicked,this,[=](){
        AdminCfWindow* p=new AdminCfWindow();
        p->show();
    });
    connect(rsBtr,&QPushButton::clicked,this,[=](){
        AdminRsWindow* p=new AdminRsWindow();
        p->show();
    });
}
