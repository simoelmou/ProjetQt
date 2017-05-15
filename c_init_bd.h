#ifndef C_INIT_BD_H
#define C_INIT_BD_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>

class C_INIT_BD
{
public:
    C_INIT_BD();

    //Creates the database
    static bool Create_BD(void);

    //Removes the database
    static bool Remove_BD(void);
};

#endif // C_INIT_BD_H
