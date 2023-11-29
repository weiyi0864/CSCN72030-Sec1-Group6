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
    QLineEdit* typ;
    QVBoxLayout* mainLayout;
    QVBoxLayout* areaLayout;
private slots:
    void addButtonClicked();
    void addAreaButtonClicked();
    void cancelButtonClicked();
};
#endif // DIALOG_H
