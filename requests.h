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

private:
    Ui::requests *ui;
    roles current_role;
    db_interaction* interaction;

    const QVector<QString> descriptions = {"Объекты, на которых ваша бригада работает пять дней в неделю",
                                          "Работы, которые закончатся менее чем за год до конца строительства объекта"};
};

#endif // REQUESTS_H
