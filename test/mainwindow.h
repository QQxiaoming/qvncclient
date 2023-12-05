#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qvncclientwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onConnected(bool c);
    void on_connect_btn_pressed();
    void on_disconnect_btn_pressed();

private:
    Ui::MainWindow *ui;
    QVNCClientWidget *vncView;
};

#endif // MAINWINDOW_H
