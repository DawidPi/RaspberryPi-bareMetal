//
// Created by Dawid on 15.10.2016.
//

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include "FileWidget.hpp"


FileWidget::FileWidget(QWidget *parent)
        : QWidget(parent) {

    auto *layout = new QHBoxLayout(this);
    setFileText(layout);
    setChooseFileButton(layout);
    layout->setMargin(0);
}


void FileWidget::setChooseFileButton(QLayout *layout) {
    auto *chooseFileButton = new QPushButton("...");
    chooseFileButton->setFixedWidth(30);
    layout->addWidget(chooseFileButton);
}

void FileWidget::setFileText(QLayout *layout) {
    auto *fileText = new QLineEdit;
    layout->addWidget(fileText);
}

