#include <QSqlDatabase>
#include <vector>

#pragma once

struct User{
    QString username;
    QString password;
    bool is_enabled;
};

class SqlSingleton
{
public:
    static SqlSingleton* Instance();
    void addUser(QString username);
    void changeStatus(QString username, bool is_eanbled);
    void changePassword(QString username, QString new_password);
    std::vector<User> getUsers();

private:
    QSqlDatabase db;

    SqlSingleton();
    ~SqlSingleton();

    static SqlSingleton* instance;
};

