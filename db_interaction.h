#ifndef DB_INTERACTION_H
#define DB_INTERACTION_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSqlQuery>

#include <fstream>

using namespace std;

class db_interaction
{
public:
    db_interaction();

    void set_database(string filename);
    void open_database();
    void close_database();

    QStringList get_tables(QString role);
    QSqlTableModel* get_editable_table(QObject* obj, QString table_name, int limit, int offset);
    QSqlQueryModel* get_readonly_table(QString table_name, int limit, int offset);

private:
    QSqlDatabase database;

    QVector<QString> get_credentials(string filename);
};

#endif // DB_INTERACTION_H
