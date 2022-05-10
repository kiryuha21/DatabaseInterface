#ifndef REQUESTS_H
#define REQUESTS_H

#include <QDialog>
#include "utils.h"

namespace Ui {
class requests;
}

class requests : public QDialog
{
    Q_OBJECT

public:
    explicit requests(QWidget *parent = nullptr, roles role = roles::no_role);
    ~requests();

private:
    Ui::requests *ui;
    roles current_role;
};

#endif // REQUESTS_H
