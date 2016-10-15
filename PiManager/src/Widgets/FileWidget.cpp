//
// Created by Dawid on 15.10.2016.
//

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include "FileWidget.hpp"


FileWidget::FileWidget(QWidget *parent)
        : QWidget(parent), mFilePathWidget(new QLineEdit) {

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
    layout->addWidget(mFilePathWidget);
}

QString FileWidget::getFilePath() const {
    return mFilePathWidget->text();
}

