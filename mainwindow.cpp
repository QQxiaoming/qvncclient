#include <QInputDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    vncView = new QVNCClientWidget(QVNCClientWidget::TCP,this);
    ui->vncLayout->addWidget(vncView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connect_btn_pressed()
{
    vncView->connectToVncServer(ui->host_edit->text(), QInputDialog::getText(this, "Password", "Enter password:", QLineEdit::Password));
}


void MainWindow::on_disconnect_btn_pressed()
{
    vncView->disconnectFromVncServer();
}
