#include <QFileDialog>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionSelect_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select file", ".", "All files (*)");
    QFile file(fileName);

    file.open(QIODevice::ReadOnly);

    if(!file.isOpen()) {
        QMessageBox::critical(this, "File error", "Could not open file!");
    }

    while(!file.atEnd()) {
        QByteArray line = file.readLine();

        for(int i = 0; i  < line.size(); ++i) {
            QMessageBox::information(this, "Char", QString(line.at(i)));
        }
    }

    file.close();
}
