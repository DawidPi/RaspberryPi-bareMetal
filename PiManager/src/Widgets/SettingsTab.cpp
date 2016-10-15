//
// Created by Dawid on 15.10.2016.
//

#include <QtWidgets/QFormLayout>
#include "SettingsTab.hpp"
#include "SerialPortsComboBox.hpp"
#include "FileWidget.hpp"

SettingsTab::SettingsTab(QWidget *parent) {
    auto *layout = new QFormLayout(this);

    layout->setVerticalSpacing(2 * layout->verticalSpacing());
    layout->setMargin(2 * layout->margin());
    layout->addRow("Binary file: ", new FileWidget);
    layout->addRow("Translator exe: ", new FileWidget);
    layout->addRow("PC Port: ", new SerialPortsComboBox);

    setLayout(layout);
}

void SettingsTab::enable(bool enabled) {
    Q_EMIT changeEnable(enabled);
}
