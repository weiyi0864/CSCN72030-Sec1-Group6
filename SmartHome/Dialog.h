#ifndef DIALOG_H
#define DIALOG_H


#include <qdialog.h>
#include <vector>
#include <QGroupBox>
#include <QLabel>
#include "area.h"


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog();
    ~Dialog();

private:
    std::vector<Area*> areas;
    QDialog* add_new_area_dialog;
private slots:
    void addButtonClicked();
};
#endif // DIALOG_H
