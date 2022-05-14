#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "utils.h"
#include "database_view.h"
#include "requests.h"
#include "reports.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_view_button_clicked();
    void on_worker_button_clicked();
    void on_manager_button_clicked();
    void on_requests_button_clicked();
    void enable_buttons(roles role);

    void on_reports_button_clicked();

private:
    Ui::MainWindow *ui;
    roles current_role = roles::no_role;
};
#endif // MAINWINDOW_H
