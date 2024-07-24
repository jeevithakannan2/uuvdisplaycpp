#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    sensorReader = new SensorReader(this);
    connect(sensorReader, &SensorReader::newDataAvailable, this, &MainWindow::updateSensorData);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sensorReader;
}

void MainWindow::updateSensorData(const QString &data) {
    ui->sensorLabel1->setText(data);
}
