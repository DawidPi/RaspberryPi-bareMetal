//
// Created by Dawid on 04.09.2016.
//

#include <iostream>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/qmessagebox.h>

int main(int argv, char **argc) {
    QApplication app(argv, argc);

    QMessageBox dialog;
    dialog.setText("Qt set properly");
    dialog.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    return dialog.exec();
}