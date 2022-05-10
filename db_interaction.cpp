#include "db_interaction.h"

db_interaction::db_interaction() { }

void db_interaction::set_database(string filename) {
    QVector<QString> credentials = get_credentials(filename);
    database = QSqlDatabase::addDatabase("QPSQL");

    database.setHostName(credentials[0]);
    database.setPort(5432);
    database.setDatabaseName(credentials[1]);
    database.setUserName(credentials[2]);
    database.setPassword(credentials[3]);
}

void db_interaction::open_database() { database.open(); }
void db_interaction::close_database() { database.close(); }

QVector<QString> db_interaction::get_credentials(string filename) {
    QVector<QString> result(4);
    string line;

    fstream fs(filename);
    for (int i = 0; i < 4; ++i) {
        fs >> line;
        result[i] = QString::fromStdString(line);
    }

    return result;
}

QStringList db_interaction::get_tables(QString role) {
    QSqlQuery query;
    query.exec(QString("select table_name from information_schema.role_table_grants where grantee='%1' AND privilege_type = 'SELECT';").arg(role));

    QStringList result;
    while (query.next()) {
        result.push_back(query.value(0).toString());
    }

    return result;
}

QSqlTableModel* db_interaction::get_editable_model(QObject* obj, QString table_name, int limit, int offset) {
    QSqlTableModel* model = new QSqlTableModel(obj, database);
    model->setTable(table_name);
    model->setFilter(QString("id > %1 AND id < %2").arg(offset).arg(limit + offset + 1));
    model->select();
    return model;
}

QSqlQueryModel* db_interaction::get_readonly_model(QString table_name, int limit, int offset) {
    QSqlQueryModel* model = new QSqlQueryModel;
    model->setQuery(QString("SELECT * FROM %1 LIMIT %2 OFFSET %3").arg(table_name).arg(limit).arg(offset));
    return model;
}
