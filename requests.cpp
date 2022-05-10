#include "requests.h"
#include "ui_requests.h"

requests::requests(QWidget *parent, roles role) :
    QDialog(parent),
    ui(new Ui::requests),
    current_role(role)
{
    ui->setupUi(this);
}

requests::~requests()
{
    delete ui;
}
