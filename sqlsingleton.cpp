#include "sqlsingleton.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

SqlSingleton* SqlSingleton::instance = nullptr;
SqlSingleton* SqlSingleton::Instance(){
    if(!instance) {
        instance = new SqlSingleton();
        return instance;
    }
    else {
        return instance;
    }

}

SqlSingleton::SqlSingleton()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("internal.db");
    if(!db.open()){
        qDebug() << db.lastError().text();
    }

    QSqlQuery query("CREATE TABLE IF NOT EXISTS users ("
                    "username text PRIMARY KEY,"
                    "password text DEFAULT \"\","
                    "enabled integer DEFAULT 1"
                    ") WITHOUT ROWID;");
    query.exec();
    qDebug() << query.lastError().text();
}

void SqlSingleton::addUser(QString username){
    QSqlQuery query("INSERT INTO users (username)"
                    "VALUES (:username);");
    query.bindValue(":username", username);
    query.exec();
    qDebug() << query.lastError().text();
}

void SqlSingleton::changeStatus(QString username, bool is_enabled){
    QSqlQuery query;
    query.prepare("UPDATE users SET enabled = :enabled WHERE username = :username;");
    query.bindValue(":username", username);
    query.bindValue(":enabled", is_enabled);
    query.exec();
    qDebug() << query.lastError().text();
}

void SqlSingleton::changePassword(QString username, QString new_password){
    QSqlQuery query;
    query.prepare("UPDATE users SET enabled = :enabled WHERE password = :password;");
    query.bindValue(":username", username);
    query.bindValue(":password", new_password);
    query.exec();
    qDebug() << query.lastError().text();
}

std::vector<User> SqlSingleton::getUsers(){
    QSqlQuery query("SELECT * FROM users");
    std::vector<User> result;
    while(query.next()){
        User tmp;
        tmp.username = query.value("username").toString();
        tmp.password = query.value("password").toString();
        tmp.is_enabled = query.value("enabled").toInt();
        result.push_back(tmp);
    }
    return result;
}

SqlSingleton::~SqlSingleton(){}
