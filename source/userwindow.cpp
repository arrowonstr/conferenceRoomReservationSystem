#include "userwindow.h"

UserWindow::UserWindow()
{
    UserUi userUi=UserUi();
    userUi.setupUi(this);
    setWindowTitle("用户界面");

    QPushButton* cfBtr=findChild<QPushButton*>("pushButton");   //预约会议室按钮
    cfBtr->setText("预约会议室");
    QPushButton* rsBtr=findChild<QPushButton*>("pushButton_2");   //管理预约按钮
    connect(cfBtr,&QPushButton::clicked,this,[=](){
        UserCfWindow* p=new UserCfWindow(user_name);
        p->show();
    });
    connect(rsBtr,&QPushButton::clicked,this,[=](){
        UserRsWindow* p=new UserRsWindow(user_name);
        p->show();
    });
}
