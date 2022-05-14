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
    QSqlTableModel* get_editable_model(QObject* obj, QString table_name, int limit, int offset);
    QSqlQueryModel* get_readonly_model(QString table_name, int limit, int offset);

    QSqlQueryModel* get_request_model(int index, int input = -1);

    const QSet<int> requests_with_input = {0, 1, 3};

private:
    QSqlDatabase database;

    QVector<QString> get_credentials(string filename);

    const QVector<QString> requests = {"SELECT obj.code, obj.title FROM building_objects obj, work_performance perf, teams, working_stuff stuff WHERE stuff.id = %1 AND stuff.team_id = teams.id AND perf.responsible_team = teams.id AND array_length(perf.working_days, 1) = 5 AND perf.object_code = obj.code",
                                       "SELECT perf.id, perf.work_object FROM teams, work_performance perf, building_objects obj WHERE teams.id = %1 AND perf.responsible_team = teams.id AND perf.object_code = obj.code AND perf.finish_time + INTERVAL '1 year' > obj.deadline",
                                       "SELECT obj.code, obj.title, bld.number_of_buildings FROM building_objects obj, (SELECT buildings.object_code, COUNT(*) AS number_of_buildings FROM buildings GROUP BY buildings.object_code HAVING COUNT(*) > 1) bld WHERE obj.code = bld.object_code",
                                       "SELECT ent.name, ent.services FROM entity ent, (SELECT ent.name, COUNT(*) AS usage_count FROM building_objects obj, entity ent WHERE ent.name = obj.developer_name AND ent.name = obj.distributor_name GROUP BY ent.name HAVING COUNT(*) > %1) en WHERE ent.name = en.name AND array_length(ent.services, 1) > 2",
                                       "SELECT terr.city, COUNT(terrs) as objects_count FROM territory_data terr, (SELECT terr.id FROM territory_data terr, building_objects obj WHERE obj.territory_id = terr.id GROUP BY terr.id HAVING COUNT(*) > 1) terrs, (SELECT DISTINCT obj.code, perf.start_time, obj.territory_id FROM building_objects obj, work_performance perf WHERE perf.object_code = obj.code AND CURRENT_DATE + interval '1 year' < perf.start_time AND CURRENT_DATE + interval '2 years' > perf.start_time) objs WHERE terrs.id = terr.id AND objs.territory_id = terr.id GROUP BY terr.city;"};
};

#endif // DB_INTERACTION_H
