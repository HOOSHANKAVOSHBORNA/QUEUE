#include "serialporthandler.h"
#include <QSerialPortInfo>
#include <QMessageBox>

SerialPortHandler::SerialPortHandler(QObject *parent) : QObject(parent)
{
    connect(&SerialPort, &QSerialPort::readyRead, this, &SerialPortHandler::PrintData);
}

void SerialPortHandler::SendData()
{
    QString Data = emit SendSignal();
    if(Data.isEmpty())
    {
        return;
    }
    if(QSerialPortInfo::availablePorts().length() <= 1)
    {
        QMessageBox MessageBox;
        MessageBox.setText("Unable to find serial port");
        MessageBox.exec();
        return;
    }
    SerialPort.setPort(QSerialPortInfo::availablePorts()[1]);
    SerialPort.write(Data.toStdString().c_str());
}

void SerialPortHandler::ShowSerialPorts()
{
    QMessageBox MessageBox;
    QString Ports;
    for(auto Info : QSerialPortInfo::availablePorts())
    {
       Ports += Info.portName();
       Ports += "\n";
    }
    MessageBox.setText(Ports);
    MessageBox.exec();
}

void SerialPortHandler::PrintData()
{
    QString StringData(SerialPort.readAll());
    emit PrintSignal(StringData);
}
