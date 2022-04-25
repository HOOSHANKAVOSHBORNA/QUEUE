#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::GetOutText()
{
    return ui->OutputText->toPlainText();
}

void MainWindow::PrintInText(QString Data)
{
    ui->InputText->append(Data + "\n");
}
