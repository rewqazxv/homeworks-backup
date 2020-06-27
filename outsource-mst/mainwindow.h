#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pch.hpp"
#include "edge.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_addEdge_clicked();
    void on_pushButton_clearEdge_clicked();
    void on_pushButton_clearRes_clicked();
    void on_pushButton_calc_clicked();
    void on_actionOpenFromFile_triggered();

    void refresh_edge();

private:
    Ui::MainWindow *ui;
    std::vector<edge> edges;
    QHash<QString, int> cityNameToNum;
    QHash<int, QString> cityNumToName;
    int cityCnt = 0;
    void addEdge(QString a, QString b, int d, int w);
};

#endif // MAINWINDOW_H
