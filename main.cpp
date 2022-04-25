#include "mainwindow.h"

#include <QApplication>
#include <serialporthandler.h>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    SerialPortHandler SerialPort;
    QPushButton* portInfoButton = w.findChild<QPushButton*>("ShowPortInfo");
    QPushButton* sendButton = w.findChild<QPushButton*>("Send");
    QObject::connect(portInfoButton, &QPushButton::clicked, &SerialPort, &SerialPortHandler::ShowSerialPorts);
    QObject::connect(sendButton, &QPushButton::clicked, &SerialPort, &SerialPortHandler::SendData);
    QObject::connect(&SerialPort, &SerialPortHandler::SendSignal, &w, &MainWindow::GetOutText);
    QObject::connect(&SerialPort, &SerialPortHandler::PrintSignal, &w, &MainWindow::PrintInText);

    w.show();
    return a.exec();
}
