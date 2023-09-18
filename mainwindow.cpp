#include <QInputDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->connect_btn->setEnabled(true);
    ui->disconnect_btn->setEnabled(false);

    vncView = new QVNCClientWidget(QVNCClientWidget::TCP,this);
    ui->vncLayout->addWidget(vncView);
    connect( vncView, SIGNAL(connected(bool)), this, SLOT(onConnected(bool)) );
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

void MainWindow::onConnected(bool c)
{
    ui->host_edit->setEnabled(!c);
    ui->comboBox->setEnabled(!c);
    ui->port_spinbox->setEnabled(!c);
    ui->connect_btn->setEnabled(!c);
    ui->disconnect_btn->setEnabled(c);
}
