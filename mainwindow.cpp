#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enable_buttons(roles role) {
    ui->view_button->setEnabled(true);
    ui->requests_button->setEnabled(true);
    ui->reports_button->setEnabled(role == roles::manager ? true : false);
}


void MainWindow::on_worker_button_clicked()
{
    enable_buttons(roles::worker);
    ui->worker_button->setChecked(true);
    ui->manager_button->setChecked(false);
    current_role = roles::worker;
}


void MainWindow::on_manager_button_clicked()
{
    enable_buttons(roles::manager);
    ui->manager_button->setChecked(true);
    ui->worker_button->setChecked(false);
    current_role = roles::manager;
}


void MainWindow::on_requests_button_clicked()
{
    requests* req = new requests(nullptr, current_role);
    req->show();
}


void MainWindow::on_view_button_clicked()
{
    database_view* db_view = new database_view(nullptr, current_role);
    db_view->show();
}


void MainWindow::on_reports_button_clicked()
{
    reports* rep = new reports();
    rep->show();
}

