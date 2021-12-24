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
    int i;
    Ter_MainWindow *termainal_win;

    for (i = 0 ; i < termainal_win_list.count(); i++) {
        termainal_win = termainal_win_list.last();
        delete termainal_win;
        termainal_win_list.removeLast();
    }

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Ter_MainWindow *termainal_win;

    termainal_win = new Ter_MainWindow(this);
    termainal_win_list.append(termainal_win);
    termainal_win = termainal_win_list.last();
    termainal_win->show();
}
