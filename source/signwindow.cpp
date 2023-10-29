#include "signwindow.h"
SignWindow::SignWindow(QMainWindow* parent):QMainWindow(parent){
    //初始化界面//
    SignUi signUi=SignUi();
    signUi.setupUi(this);
    setWindowTitle("会议室系统登录");

    //初始化成员//
    cf.createConnectionByName("conference");
    adminWindow=new AdminWindow();
    userWindow=new UserWindow();

    //初始化信号和槽//
    //当前界面按键/
    QPushButton* logInBtn=findChild<QPushButton*>("pushButton_2");
    QPushButton* logOnBtn=findChild<QPushButton*>("pushButton");
    connect(logInBtn,&QPushButton::clicked,this,&SignWindow::logIn);
    connect(logOnBtn,&QPushButton::clicked,this,&SignWindow::logOn);
    //管理员界面按键/
    QPushButton* exitBtr1=adminWindow->findChild<QPushButton*>("pushButton_3"); //退出登录
    connect(exitBtr1,&QPushButton::clicked,this,[=](){
        adminWindow->hide();
        this->show();
        this->findChild<QLineEdit*>("lineEdit")->setText("");
        this->findChild<QLineEdit*>("lineEdit_2")->setText("");
    });
    //用户界面按键/
    QPushButton* exitBtr2=userWindow->findChild<QPushButton*>("pushButton_3");  //退出登录
    connect(exitBtr2,&QPushButton::clicked,this,[=](){
        userWindow->hide();
        this->show();
        this->findChild<QLineEdit*>("lineEdit")->setText("");
        this->findChild<QLineEdit*>("lineEdit_2")->setText("");
    });

}

SignWindow::~SignWindow(){
    qDebug()<<"登陆界面关闭";
}

void SignWindow::logIn(){
    QLineEdit* nameLine=findChild<QLineEdit*>("lineEdit");
    QLineEdit* passwordLine=findChild<QLineEdit*>("lineEdit_2");
    QString name=nameLine->text();
    QString password=passwordLine->text();
    int author=findChild<QComboBox*>("comboBox")->currentIndex();
    Users* user=cf.selectQueryUsers(name);
    if(user==NULL){
        QMessageBox::critical(this,"用户登录","用户未注册");
        return;
    }else if(user->password!=password){
        QMessageBox::critical(this,"用户登录","密码错误");
        return;
    }else if(user->author!=author){
        QMessageBox::critical(this,"用户登录","权限错误");
        return;
    }
    hide();
    if(author==0){
        userWindow->show();
        userWindow->user_name=name;
    }
    if(author==1) adminWindow->show();
}
void SignWindow::logOn(){
    QString name=findChild<QLineEdit*>("lineEdit")->text();
    Users* user=cf.selectQueryUsers(name);
    if(user!=NULL){
        QMessageBox::critical(this,"用户注册","用户已存在");
        return;
    }
    QString password=findChild<QLineEdit*>("lineEdit_2")->text();
    int author=findChild<QComboBox*>("comboBox")->currentIndex();
    QMessageBox::information(this,"用户注册","注册成功");
    cf.insertNameUsers(name,password,author);
}


