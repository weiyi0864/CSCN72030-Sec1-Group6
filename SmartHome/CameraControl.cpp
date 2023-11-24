#include "cameracontrol.h"




CameraControl::CameraControl(QString name)
{


    yaw_degree = 90;
    pitch_degree = 30;
    setText("Camera - " + name);
    camera_control_dialog = new QDialog();
    camera_control_dialog->setWindowTitle("Camera Control");
    camera_control_dialog->setMinimumSize(400, 400);
    connect(this, &CameraControl::clicked, this, &CameraControl::onButtonClicked);


    // set up camera control dialog details
    QVBoxLayout* layout = new QVBoxLayout();

    // Camera Control
    QLabel* pitch_label = new QLabel("Pitch Degree: Central"); // Label to display current value
    // slider
    QSlider* pitch_slider = new QSlider(Qt::Horizontal);
    pitch_slider->setRange(0, 60); // Set the range of the slider
    pitch_slider->setValue(30);     // Set the initial value
    QString degreeSymbol = " degree";
    QObject::connect(pitch_slider, &QSlider::valueChanged, [=](int value) {
        pitch_degree = value;

        if (pitch_degree == 30) {
            pitch_label->setText("Pitch Degree: Central");
        }
        else if (pitch_degree < 30) {
            pitch_label->setText(qPrintable("Pitch Degree: UP " + QString::number(30 - value) + degreeSymbol));
        }
        else {
            pitch_label->setText(qPrintable("Pitch Degree: DOWN " + QString::number(value - 30) + degreeSymbol));
        }
        });
    layout->addWidget(pitch_label);
    layout->addWidget(pitch_slider);

    QLabel* yaw_label = new QLabel("Yaw Degree: Central"); // Label to display current value
    // slider
    QSlider* yaw_slider = new QSlider(Qt::Horizontal);
    yaw_slider->setRange(0, 180); // Set the range of the slider
    yaw_slider->setValue(90);     // Set the initial value
    QObject::connect(yaw_slider, &QSlider::valueChanged, [=](int value) {
        yaw_degree = value;

        if (yaw_degree == 90) {
            yaw_label->setText("Yaw Degree: Central");
        }
        else if (yaw_degree < 90) {
            yaw_label->setText(qPrintable("Yaw Degree: LEFT " + QString::number(90 - value) + degreeSymbol));
        }
        else {
            yaw_label->setText(qPrintable("Yaw Degree: RIGHT " + QString::number(value - 90) + degreeSymbol));
        }
        });
    layout->addWidget(yaw_label);
    layout->addWidget(yaw_slider);

    // Camera Image
    QLabel* cameraLabel = new QLabel("Camera Image");
    QLabel* imageLabel = new QLabel();
    QPixmap* image = new QPixmap("../SmartHome/room.jpeg");

    if (image->isNull()) {
        imageLabel->setText("Image cannot be loaded");
    }
    else {
        QPixmap scaledImage = image->scaled(400, 400, Qt::IgnoreAspectRatio);
        imageLabel->setPixmap(scaledImage);
    }
    layout->addWidget(cameraLabel);
    layout->addWidget(imageLabel);
    camera_control_dialog->setLayout(layout);
}

void CameraControl::onButtonClicked() {
    camera_control_dialog->exec();
}
