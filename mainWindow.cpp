//
// Created by mia borko on 14/05/2024.
//
#include "mainwindow.h"
#include "./ui_mainWindow.h"
#include "Room.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load rooms from JSON
    QString jsonFilePath = "/path/to/your/json/file.json";
    std::vector<Room*> rooms = Room::loadRoomsFromJSON(jsonFilePath);
    // Now you can use the loaded rooms as needed
}

MainWindow::~MainWindow()
{
    delete ui;
}