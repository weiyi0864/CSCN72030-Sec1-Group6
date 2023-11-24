#include "area.h"
#include <QWidget>


Area::Area(QString title)
{
    setTitle(title);
}


void Area::addButtonControl(QPushButton* btn) {
    btns.push_back(btn);
}

void Area::addButtonsIntoLayout() {
    QVBoxLayout* layout = new QVBoxLayout();

    int i = 0;
    // add 4 buttons every row
    while (i < btns.size()) {
        QHBoxLayout* row = new QHBoxLayout();
        for (int j = 0; j < 4; j++) {
            if (i < btns.size()) {
                row->addWidget(btns[i++]);
            }
            else {
                row->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
            }
        }
        layout->addLayout(row);
    }

    setLayout(layout);
}
