#include "lightcontrol.h"

LightControl::LightControl(QString name)
{
    intensity = 100;
    state = false;
    setText("Light - " + name);
    light_control_dialog = new QDialog();
    light_control_dialog->setWindowTitle("Light Control");
    connect(this, &LightControl::clicked, this, &LightControl::onButtonClicked);

    // set up light control dialog details
    QVBoxLayout* layout = new QVBoxLayout();


    QLabel* valueLabel = new QLabel("Intensity: " + QString::number(intensity)); // Label to display current value
    // slider
    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100); // Set the range of the slider
    slider->setValue(100);     // Set the initial value
    QObject::connect(slider, &QSlider::valueChanged, [=](int value) {
        valueLabel->setText(qPrintable("Intensity: " + QString::number(value))); // Update label with slider value
        });
    QPushButton* state_btn = new QPushButton();

    state_btn->setText("OFF");

    connect(state_btn, &QPushButton::clicked, this, &LightControl::onToggleStateButton);
    layout->addWidget(valueLabel);
    layout->addWidget(slider);
    layout->addWidget(state_btn);
    light_control_dialog->setLayout(layout);
}

void LightControl::onButtonClicked() {
    light_control_dialog->exec();
}

void LightControl::onToggleStateButton() {
    if (state) {
        state = false;
    }
    else {
        state = true;
    }
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (state) {
        button->setText("ON");
    }
    else {
        button->setText("OFF");
    }
}
