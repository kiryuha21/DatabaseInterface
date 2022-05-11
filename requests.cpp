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
    delete ui;
}

void requests::on_combo_request_textActivated(const QString &arg1)
{
    ui->describe_browser->setText(descriptions[ui->comboBox->currentIndex()]);
}

