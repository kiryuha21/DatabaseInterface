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

void MainWindow::enable_buttons() {
    ui->view_button->setEnabled(true);
    ui->requests_button->setEnabled(true);
}


void MainWindow::on_worker_button_clicked()
{
    enable_buttons();
    ui->worker_button->setChecked(true);
    ui->manager_button->setChecked(false);
    current_role = roles::worker;
}


void MainWindow::on_manager_button_clicked()
{
    enable_buttons();
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

