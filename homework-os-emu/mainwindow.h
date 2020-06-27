#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pch.hpp"
#include "emulations.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QAction *act;
    QAction *clear;

    void show_values(const int block_num, const pages_t &pages, std::function<blocks_log(const int, const pages_t &)> f, QLabel *msg, QTableWidget *table);
};

#endif // MAINWINDOW_H
