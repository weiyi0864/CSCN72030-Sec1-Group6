#ifndef AREA_H
#define AREA_H

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>
#include <QFormLayout>


#include "lightcontrol.h"
#include "curtaincontrol.h"
#include "cameracontrol.h"
#include "fridgecontrol.h"
#include "accontrol.h"

class Area :public QGroupBox
{
public:
    Area(QString title);
    void addButtonsIntoLayout();
    void addButtonControl(QPushButton* btn);


private:
    std::vector<QPushButton*> btns;
    QVBoxLayout* mainLayout;
    QVBoxLayout* addControlLayout;
    QVBoxLayout* controlLayout;

    QDialog* add_new_control_dialog;

    QLineEdit* typ;
    QComboBox* comboBox;

private slots:
    void addButtonClicked();
    void addControlButtonClicked();
    void cancelButtonClicked();


};

#endif // AREA_H
