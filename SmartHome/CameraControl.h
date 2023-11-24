#ifndef CAMERACONTROL_H
#define CAMERACONTROL_H

#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>

class CameraControl :public QPushButton
{
public:
    CameraControl(QString name);
private:
    // 0-180 - 90 central
    int yaw_degree;
    // 0-60 - 30 central
    int pitch_degree;
    QDialog* camera_control_dialog;

private slots:
    void onButtonClicked();
};

#endif // CAMERACONTROL_H
