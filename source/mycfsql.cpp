#include "mycfsql.h"

MyCfSql::MyCfSql()
{

}

void MyCfSql::createConnectionByName(const QString &connectionName){

    db = QSqlDatabase::addDatabase("QMYSQL", connectionName);
    // 数据库连接需要设置的信息
    db.setHostName("localhost"); // 数据库服务器IP，我用的是本地电脑
    db.setDatabaseName("conference");// 数据库名
    db.setUserName("root");// 用户名
    db.setPassword("1234");// 密码
    db.setPort(3306);// 端口号

    // 连接数据库判断
    bool ok = db.open();

    if (ok){
        qDebug() << "database connect is ok";
    } else {
        qDebug() << "database connect is fail";
    }

}

void MyCfSql::getConnectionByName(const QString &connectionName) {
    // 获取数据库连接
    db=QSqlDatabase::database(connectionName);
}
void MyCfSql::outputDatabaseInfo(){
    QStringList tables = db.tables();
    QStringListIterator itr(tables);
    while (itr.hasNext())
    {
        QString tableNmae = itr.next().toLocal8Bit();
        qDebug() << QString::fromLocal8Bit("表名：")+ tableNmae;
    }
}
//用户数据//
void MyCfSql::insertNameUsers(const QString &name, const QString &password,const int author) {
    QSqlQuery query(db);
    query.prepare("INSERT INTO conference_users (users_name, users_password,users_author) VALUES (:users_name, :users_password,:users_author)");
    query.bindValue(":users_name", name);
    query.bindValue(":users_password", password);
    query.bindValue(":users_author",author);
    query.exec();
}
Users* MyCfSql::selectQueryUsers(const QString &name) {
    QString sql = "SELECT * FROM conference_users WHERE users_name='" + name + "'";
    QSqlQuery query(db);    // [1] 传入数据库连接
    query.exec(sql);        // [2] 执行sql语句
    if(query.size()==0) return NULL;;
    Users* user=new Users();
    while (query.next()) {  // [3] 遍历查询结果
        user->name=query.value(1).toString();
        user->password=query.value(2).toString();
        user->author=query.value(3).toInt();
    }
    return user;
}

void MyCfSql::queryAllUsers() {
    QString sql = "SELECT users_id,users_name, users_password,users_author FROM conference_users" ; // 组装sql语句
    QSqlQuery query(db);                               // [1] 传入数据库连接
    query.exec(sql);                                   // [2] 执行sql语句
    while (query.next()) {                             // [3] 遍历查询结果
        qDebug() << QString("Id: %1, Username: %2,UserPassword:%3,UserAuthor:%4")
                        .arg(query.value("users_id").toInt())
                        .arg(query.value("users_name").toString())
                        .arg(query.value("users_password").toString())
                        .arg(query.value("users_author").toInt());
    }
}

//会议室数据//
void MyCfSql::insertNameRooms(const QString &name, const int number,const int capacity,const int square,const QString &describe,const QString &reserve){
    QSqlQuery query(db);
    query.prepare("INSERT INTO conference_rooms(rooms_name, rooms_number,rooms_capacity,rooms_square,rooms_describe,rooms_reserve) VALUES (:rooms_name, :rooms_number,:rooms_capacity,:rooms_square,:rooms_describe,:rooms_reserve)");
    query.bindValue(":rooms_name", name);
    query.bindValue(":rooms_number", number);
    query.bindValue(":rooms_capacity",capacity);
    query.bindValue(":rooms_square",square);
    query.bindValue(":rooms_describe",describe);
    query.bindValue(":rooms_reserve",reserve);
    if(!query.exec()){
        qDebug()<<"add rooms error";
    }
}; // 增操作
void MyCfSql::deleteRooms(const int number) {
    QSqlQuery query(db);
    query.prepare("DELETE FROM conference_rooms WHERE rooms_number=:rooms_number");
    query.bindValue(":rooms_number",number);
    if(!query.exec()){
        qDebug()<<"delete rooms error";
    }
}
Rooms* MyCfSql::selectQueryRooms(const int number){
    QString sql = "SELECT * FROM conference_rooms WHERE rooms_number='" + QString::number(number) + "'";
    QSqlQuery query(db);    // [1] 传入数据库连接
    query.exec(sql);        // [2] 执行sql语句
    if(query.size()==0) return NULL;;
    Rooms* room=new Rooms();
    while (query.next()) {  // [3] 遍历查询结果
        room->name=query.value(1).toString();
        room->number=query.value(2).toInt();
        room->capacity=query.value(3).toInt();
        room->square=query.value(4).toInt();
        room->describe=query.value(5).toString();
        room->reserve=query.value(6).toString();
    }
    return room;
};
void MyCfSql::updateRooms(const QString &name, const int number,const int capacity,const int square,const QString &describe) {
    QSqlQuery query(db);
    query.prepare("update conference_rooms set rooms_name=:rooms_name,rooms_capacity=:rooms_capacity,rooms_square=:rooms_square,rooms_describe=:rooms_describe WHERE rooms_number=:rooms_number");
    query.bindValue(":rooms_number", number);
    query.bindValue(":rooms_name", name);
    query.bindValue(":rooms_capacity",capacity);
    query.bindValue(":rooms_square",square);
    query.bindValue(":rooms_describe",describe);
    if(!query.exec()){
        qDebug()<<"update rooms error";
    }
}
Rooms* MyCfSql::queryAllRooms(){
    QString sql = "SELECT rooms_id,rooms_name, rooms_number,rooms_capacity,rooms_square,rooms_describe,rooms_reserve FROM conference_rooms" ; // 组装sql语句
    QSqlQuery query(db);                               // [1] 传入数据库连接
    query.exec(sql);                                   // [2] 执行sq
    Rooms* p=new Rooms[30];
    int i=0;
    while (query.next()){
        p[i].name=query.value(1).toString();
        p[i].number=query.value(2).toInt();
        p[i].capacity=query.value(3).toInt();
        p[i].square=query.value(4).toInt();
        p[i].describe=query.value(5).toString();
        p[i].reserve=query.value(6).toString();
        i++;
    }
    p[i].number=-1;
    return p;
}


//预约数据//
void MyCfSql::insetNameReserves(const QString &user,const int number,const QDateTime &stime,const QDateTime &etime,const QString &subject,const int capacity,const int state,const QString &describe){
    QSqlQuery query(db);
    query.prepare("INSERT INTO conference_reserves(reserves_user,reserves_number,reserves_stime,reserves_etime,reserves_subject,reserves_capacity,reserves_state,reserves_describe) VALUES (:reserves_user,:reserves_number,:reserves_stime,:reserves_etime,:reserves_subject,:reserves_capacity,:reserves_state,:reserves_describe)");
    query.bindValue(":reserves_user",user);
    query.bindValue(":reserves_number", number);
    query.bindValue(":reserves_stime",stime);
    query.bindValue(":reserves_etime",etime);
    query.bindValue(":reserves_subject",subject);
    query.bindValue(":reserves_capacity",capacity);
    query.bindValue(":reserves_state",state);
    query.bindValue(":reserves_describe",describe);
    if(!query.exec()){
        qDebug()<<"add reserves error";
    }
}

Reserves* MyCfSql::selectQueryReserves(const QDateTime &stime,const QDateTime &etime){  //通过开始时间、截止时间筛选预约记录
    QString sql = "SELECT * FROM conference_reserves WHERE";
    sql+=" not ";
    sql+="(";
    sql+="reserves_stime>='"+ etime.toString("yyyy-MM-dd hh:mm:ss")+"'";
    sql+=" or ";
    sql+="reserves_etime<='"+stime.toString("yyyy-MM-dd hh:mm:ss")+"'";
    sql+=")";
    sql+=" and ";
    sql+="(reserves_state=0 or reserves_state=1)";
    QSqlQuery query(db);    // [1] 传入数据库连接
    if(!query.exec(sql)){        // [2] 执行sql语句
        qDebug()<<"查找预约记录失败(time)";
    }
    if(query.size()==0) return NULL;
    Reserves* p=new Reserves[30];
    int i=0;
    while (query.next()){
        p[i].user=query.value(1).toString();
        p[i].number=query.value(2).toInt();
        p[i].stime=query.value(3).toDateTime();
        p[i].etime=query.value(4).toDateTime();
        p[i].subject=query.value(5).toString();
        p[i].capacity=query.value(6).toInt();
        p[i].state=query.value(7).toInt();
        p[i].describe=query.value(8).toString();
        i++;
    }
    p[i].number=-1;
    return p;
}

Reserves* MyCfSql::selectQueryReserves(const QString &user,const int state){    //通过用户和状态筛选预约记录
    QString sql="SELECT * FROM conference_reserves WHERE reserves_user='" +user+ "'and reserves_state='"+QString::number(state)+"'";
    QSqlQuery query(db);    // [1] 传入数据库连接
    if(!query.exec(sql)){        // [2] 执行sql语句
        qDebug()<<"查找预约记录失败（user)";
    }
    if(query.size()==0) return NULL;
    Reserves* p=new Reserves[30];
    int i=0;
    while (query.next()){
        p[i].user=query.value(1).toString();
        p[i].number=query.value(2).toInt();
        p[i].stime=query.value(3).toDateTime();
        p[i].etime=query.value(4).toDateTime();
        p[i].subject=query.value(5).toString();
        p[i].capacity=query.value(6).toInt();
        p[i].state=query.value(7).toInt();
        p[i].describe=query.value(8).toString();
        i++;
    }
    p[i].number=-1;
    return p;
}
Reserves* MyCfSql::selectQueryReserves(const QString &user,const int number,const QDateTime &stime,const QDateTime &etime,const int state){
    QString sql="SELECT * FROM conference_reserves WHERE reserves_user='" +user+ "'and reserves_number='"+QString::number(number)+"'and reserves_stime='"+stime.toString("yyyy-MM-dd hh:mm:ss") +"'and reserves_etime='"+etime.toString("yyyy-MM-dd hh:mm:ss")+"'and reserves_state='"+QString::number(state)+"'";
    QSqlQuery query(db);    // [1] 传入数据库连接
    if(!query.exec(sql)){        // [2] 执行sql语句
        qDebug()<<"查找预约记录失败（user and time)";
    }
    if(query.size()==0) return NULL;
    Reserves* p=new Reserves();
    while (query.next()) {  // [3] 遍历查询结果
        p->user=query.value(1).toString();
        p->number=query.value(2).toInt();
        p->stime=query.value(3).toDateTime();
        p->etime=query.value(4).toDateTime();
        p->subject=query.value(5).toString();
        p->capacity=query.value(6).toInt();
        p->state=query.value(7).toInt();
        p->describe=query.value(8).toString();
    }
    return p;
}
Reserves* MyCfSql::selectQueryReserves(const int state){
    QString sql="SELECT * FROM conference_reserves WHERE reserves_state='"+QString::number(state)+"'";
    QSqlQuery query(db);    // [1] 传入数据库连接
    if(!query.exec(sql)){        // [2] 执行sql语句
        qDebug()<<"查找预约记录失败（state)";
    }
    if(query.size()==0) return NULL;
    Reserves* p=new Reserves[30];
    int i=0;
    while (query.next()){
        p[i].user=query.value(1).toString();
        p[i].number=query.value(2).toInt();
        p[i].stime=query.value(3).toDateTime();
        p[i].etime=query.value(4).toDateTime();
        p[i].subject=query.value(5).toString();
        p[i].capacity=query.value(6).toInt();
        p[i].state=query.value(7).toInt();
        p[i].describe=query.value(8).toString();
        i++;
    }
    p[i].number=-1;
    return p;
}
void MyCfSql::updateReserves(const QString &user,const int number,const QDateTime &stime,const QDateTime &etime,const int state){
    QSqlQuery query(db);
    query.prepare("update conference_reserves set reserves_state=3 WHERE reserves_user=:reserves_user and reserves_number=:reserves_number and reserves_stime=:reserves_stime and reserves_etime=:reserves_etime and reserves_state=:reserves_state");
    query.bindValue(":reserves_user",user);
    query.bindValue(":reserves_number",number);
    query.bindValue(":reserves_stime",stime);
    query.bindValue(":reserves_etime",etime);
    query.bindValue(":reserves_state",state);
    if(!query.exec()){
        qDebug()<<"update reserves error";
    }
}

void MyCfSql::updateReserves(const QString &user,const int number,const QDateTime &stime,const QDateTime &etime,const int state,const QString &describe,const int newState){
    QSqlQuery query(db);
    query.prepare("update conference_reserves set reserves_state=:reserves_newState,reserves_describe=:reserves_describe WHERE reserves_user=:reserves_user and reserves_number=:reserves_number and reserves_stime=:reserves_stime and reserves_etime=:reserves_etime and reserves_state=:reserves_state");
    query.bindValue(":reserves_newState",newState);
    query.bindValue(":reserves_describe",describe);
    query.bindValue(":reserves_user",user);
    query.bindValue(":reserves_number",number);
    query.bindValue(":reserves_stime",stime);
    query.bindValue(":reserves_etime",etime);
    query.bindValue(":reserves_state",state);
    if(!query.exec()){
        qDebug()<<"update reserves error";
    }
}
