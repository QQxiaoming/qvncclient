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
    if(ui->comboBox->currentText() == "TCP") {
        vncView->setType(QVNCClientWidget::TCP);
    } else if(ui->comboBox->currentText() == "WebSocket") {
        vncView->setType(QVNCClientWidget::WEBSOCKET);
    }
    vncView->connectToVncServer(ui->host_edit->text(),
        QInputDialog::getText(this, "Password", "Enter password:", QLineEdit::Password),
        ui->port_spinbox->value() );
}


void MainWindow::on_disconnect_btn_pressed()
{
    vncView->disconnectFromVncServer();
}
