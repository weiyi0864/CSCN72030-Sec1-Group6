#ifndef LIGHTCONTROL_H
#define LIGHTCONTROL_H

#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>

class LightControl :public QPushButton
{
public:
    LightControl(QString name);
private:
    bool state;
    int intensity;
    QDialog* light_control_dialog;

private slots:
    void onButtonClicked();
    void onToggleStateButton();
};

#endif // LIGHTCONTROL_H
