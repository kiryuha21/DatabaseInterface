#ifndef REPORTS_H
#define REPORTS_H

#include <QDialog>

#include "db_interaction.h"

namespace Ui {
class reports;
}

class reports : public QDialog
{
    Q_OBJECT

public:
    explicit reports(QWidget *parent = nullptr);
    ~reports();

private slots:
    void on_make_button_clicked();

private:
    Ui::reports *ui;
    db_interaction* interaction;

    const QVector<QString> descriptions = {"Отчет по объектам",
                                          "Отчет по бригадам"};
};

#endif // REPORTS_H
