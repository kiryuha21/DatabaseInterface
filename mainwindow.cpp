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

//void MainWindow::on_pushButton_clicked()
//{
//    QSqlDatabase db = set_database();
//    if (db.open()) {
//        ui->textBrowser->append("DB successfully opened!\n");
//        for (const auto& i : db.tables()) {
//            ui->textBrowser->append(i);
//        }
//    } else {
//        ui->textBrowser->append("все плохо");
//    }

//    table = new QSqlTableModel(this, db);
//    table->setTable("territory_data");
//    table->select();
//    ui->tableView->setModel(table);
//    ui->tableView->resizeColumnsToContents();
//    ui->tableView->resizeRowsToContents();
//    //ui->tableView->resize(QSize(ui->tableView->horizontalHeader()->geometry()))

//    db.close();
//    ui->textBrowser->append("\nDB successfully closed!");
//}

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
    this->hide();
    requests* req = new requests(nullptr, current_role);
    req->show();
}


void MainWindow::on_view_button_clicked()
{
    //this->hide();
    database_view* db_view = new database_view(nullptr, current_role);
    db_view->show();
}

