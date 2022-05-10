#include "database_view.h"
#include "ui_database_view.h"

database_view::database_view(QWidget *parent, roles role) :
    QDialog(parent),
    ui(new Ui::database_view),
    current_role(role)
{
    ui->setupUi(this);
    QString role_param = role == roles::worker ? "worker" : "manager";
    std::string filename = role_param.toStdString() + "_credentials.txt";

    interaction = new db_interaction();
    interaction->set_database(filename);
    interaction->open_database();

    ui->db_combo->addItems(interaction->get_tables(role_param));
}

database_view::~database_view()
{
    interaction->close_database();
    delete ui;
}


void database_view::on_db_combo_textActivated(const QString &arg1)
{
    int offset = ui->first_number_edit->text().toInt() - 1;
    int limit = ui->records_limit_edit->text().toInt();

    if (current_role == roles::manager && (arg1 == "working_stuff" || arg1 == "teams")) {
        auto model = interaction->get_editable_model(this, arg1, limit, offset);
        ui->redact_edit->setText("Разрешено");
        ui->table_view->setModel(model);
    } else {
        auto model = interaction->get_readonly_model(arg1, limit, offset);
        ui->redact_edit->setText("Запрещено");
        ui->table_view->setModel(model);
    }
}

