#include "requests.h"
#include "ui_requests.h"

requests::requests(QWidget *parent, roles role) :
    QDialog(parent),
    ui(new Ui::requests),
    current_role(role)
{
    ui->setupUi(this);

    std::string filename = role == roles::worker ? "worker" : "manager";
    filename += "_credentials.txt";

    interaction = new db_interaction();
    interaction->set_database(filename);
    interaction->open_database();

    ui->combo_request->addItems({"Запрос №1", "Запрос №2"});
    if (current_role == roles::manager) {
        ui->combo_request->addItems({"Запрос №3", "Запрос №4", "Запрос №5"});
    }
}

requests::~requests()
{
    interaction->close_database();
    delete ui;
}

void requests::on_combo_request_textActivated(const QString &arg1)
{
    int current_index = ui->combo_request->currentIndex();
    ui->input_edit->setDisabled(interaction->requests_with_input.contains(current_index) ? false : true);
    ui->describe_browser->setText(descriptions[current_index]);
}


void requests::on_find_button_clicked()
{
    if (ui->input_edit->isEnabled()) {
        ui->tableView->setModel(interaction->get_request_model(ui->combo_request->currentIndex(), ui->input_edit->text().toInt()));
        ui->input_edit->clear();
        ui->input_edit->setFocus();
    } else {
        ui->tableView->setModel(interaction->get_request_model(ui->combo_request->currentIndex()));
    }
    ui->tableView->resizeColumnsToContents();
}

