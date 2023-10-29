#ifndef MYCFSQL_H
#define MYCFSQL_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QDebug>

struct Users{
    QString name;
    QString password;
    int author;
};
struct Rooms{
    QString name;
    int number;
    int capacity;
    int square;
    QString describe;
    QString reserve;
};
struct Reserves{
    QString user;
    int number;
    QDateTime stime;
    QDateTime etime;
    QString subject;
    int capacity;
    int state;
    QString describe;
};

class MyCfSql
{
private:
    QSqlDatabase db;
public:
    MyCfSql();
    void createConnectionByName(const QString &connectionName); //使用自定义 connectionName 创建连接
    void getConnectionByName(const QString &connectionName);  // 使用自定义 connectionName 获取连接
    void outputDatabaseInfo();

    void insertNameUsers(const QString &name, const QString &password,const int author); // 增操作
    Users* selectQueryUsers(const QString &username);
    void queryAllUsers();


    void insertNameRooms(const QString &name, const int number,const int capacity,const int square,const QString &describe,const QString &reserve); // 增操作
    void deleteRooms(const int number);
    Rooms* selectQueryRooms(const int number);
    void updateRooms(const QString &name, const int number,const int capacity,const int square,const QString &describe);
    Rooms* queryAllRooms();

    void insetNameReserves(const QString &user,const int number,const QDateTime &stime,const QDateTime &etime,const QString &subject,const int capacity,const int state,const QString &describe);
    Reserves* selectQueryReserves(const QDateTime &stime,const QDateTime &etime);
    Reserves* selectQueryReserves(const QString &user,const int state);
    Reserves* selectQueryReserves(const QString &user,const int number,const QDateTime &stime,const QDateTime &etime,const int state);
    Reserves* selectQueryReserves(const int state);
    void updateReserves(const QString &user,const int number,const QDateTime &stime,const QDateTime &etime,const int state);
    void updateReserves(const QString &user,const int number,const QDateTime &stime,const QDateTime &etime,const int state,const QString &describe,const int newState);
};

#endif // MYCFSQL_H
