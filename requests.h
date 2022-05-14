#ifndef REQUESTS_H
#define REQUESTS_H

#include <QDialog>

#include "utils.h"
#include "db_interaction.h"

namespace Ui {
class requests;
}

class requests : public QDialog
{
    Q_OBJECT

public:
    explicit requests(QWidget *parent = nullptr, roles role = roles::no_role);
    ~requests();

private slots:
    void on_combo_request_textActivated(const QString &arg1);

    void on_find_button_clicked();

private:
    Ui::requests *ui;
    roles current_role;
    db_interaction* interaction;

    const QVector<QString> descriptions = {"Объекты, на которых бригада выбранного рабочего(ввод) работает пять дней в неделю",
                                          "Работы бригады(ввод), которые закончатся менее чем за год до конца строительства объекта",
                                          "Строящиеся объекты, которым до конца строительства более года, но уже имеющие больше одного здания",
                                          "Юридические лица, которые были выбраны одновременно затройщиком и дистрибьютором на (ввод) объектах и имеет более двух доступных услуг",
                                          "Города, в которых несколько строительных объектов, а ближайшие работы начнутся в интервале от одного до двух лет"};
};

#endif // REQUESTS_H
