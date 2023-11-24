#ifndef FRIDGECONTROL_H
#define FRIDGECONTROL_H

#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QGroupBox>

class FridgeControl :public QPushButton
{
public:
    FridgeControl(QString name);
private:
    // refridgerator
    int setting_temperature_r;
    int current_temperature_r;
    // freezer
    int setting_temperature_f;
    int current_temperature_f;
    // ice making
    bool ice;
    QDialog* fridge_control_dialog;

private slots:
    void onButtonClicked();
    void onToggleStateButton();
};

#endif // FRIDGECONTROL_H
