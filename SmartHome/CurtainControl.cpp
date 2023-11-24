#include "curtaincontrol.h"

CurtainControl::CurtainControl(QString name)
{
    slide_percentage = 0;
    shade_percentage = 0;
    setText("Curtain - " + name);
    curtain_control_dialog = new QDialog();
    curtain_control_dialog->setWindowTitle("Curtain Control");
    connect(this, &CurtainControl::clicked, this, &CurtainControl::onButtonClicked);

    // set up curtain control dialog details
    QVBoxLayout* layout = new QVBoxLayout();


    QLabel* slide_label = new QLabel("Sliding Percentage: " + QString::number(slide_percentage) + "%"); // Label to display current value
    // slider
    QSlider* slide_slider = new QSlider(Qt::Horizontal);
    slide_slider->setRange(0, 100); // Set the range of the slider
    slide_slider->setValue(0);     // Set the initial value
    QObject::connect(slide_slider, &QSlider::valueChanged, [=](int value) {
        slide_percentage = value;
        slide_label->setText(qPrintable("Sliding Percentage: " + QString::number(value) + "%")); // Update label with slider value
        });

    QLabel* shade_label = new QLabel("Shade Percentage: " + QString::number(shade_percentage) + "%"); // Label to display current value
    // slider
    QSlider* shade_slider = new QSlider(Qt::Horizontal);
    shade_slider->setRange(0, 100); // Set the range of the slider
    shade_slider->setValue(0);     // Set the initial value
    QObject::connect(shade_slider, &QSlider::valueChanged, [=](int value) {
        shade_percentage = value;
        shade_label->setText(qPrintable("Shade Percentage: " + QString::number(value) + "%")); // Update label with slider value
        });

    layout->addWidget(slide_label);
    layout->addWidget(slide_slider);
    layout->addWidget(shade_label);
    layout->addWidget(shade_slider);
    curtain_control_dialog->setLayout(layout);
}

void CurtainControl::onButtonClicked() {
    curtain_control_dialog->exec();
}
