#include "reports.h"
#include "ui_reports.h"

reports::reports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reports)
{
    ui->setupUi(this);

    interaction = new db_interaction();
    interaction->set_database("manager_credentials.txt");
    interaction->open_database();

    ui->report_combo->addItems(descriptions);
}

reports::~reports()
{
    interaction->close_database();
    delete ui;
}

void reports::on_make_button_clicked()
{
    ui->tableView->setModel(interaction->get_report_model(ui->report_combo->currentIndex()));
    ui->tableView->resizeColumnsToContents();
}

