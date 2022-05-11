#ifndef DATABASE_VIEW_H
#define DATABASE_VIEW_H

#include <QDialog>

#include "utils.h"
#include "db_interaction.h"

namespace Ui {
class database_view;
}

class database_view : public QDialog
{
    Q_OBJECT

public:
    explicit database_view(QWidget *parent = nullptr, roles role = roles::no_role);
    ~database_view();

private slots:
    void on_db_combo_textActivated(const QString &arg1);

    void on_delete_button_clicked();

    void on_add_button_clicked();

private:
    Ui::database_view *ui;
    roles current_role;
    db_interaction* interaction;
    QAbstractItemModel* model;
};

#endif // DATABASE_VIEW_H
