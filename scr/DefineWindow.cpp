#include "newWindow.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QMainWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create a button widget
    QPushButton *button = new QPushButton("Open New Window", this);

    // Set the button's position and size
    button->setGeometry(50, 50, 200, 50);

    // Connect the button's clicked signal to a slot
    connect(button, &QPushButton::clicked, this, &MainWindow::openNewWindow);
}

// Slot implementation for opening the new window
void MainWindow::openNewWindow()
{
    // Create an instance of the new window
    NewWindow *newWindow = new NewWindow(this);

    // Show the new window
    newWindow->show();
}
