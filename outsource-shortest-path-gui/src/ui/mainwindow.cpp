#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "pch.hpp"
#include "core/demo.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    zoom(0);
    connect(ui->zoomArea, &ZoomArea::zoomin, [this] {zoom(100);});
    connect(ui->zoomArea, &ZoomArea::zoomout, [this] {zoom(-100);});

    connect(ui->pushButton_start, &QPushButton::clicked, [this] {isStart = true;});
    connect(ui->pushButton_end, &QPushButton::clicked, [this] {isStart = false;});
    connect(ui->actionAboutQt, &QAction::triggered, [this] {QMessageBox::aboutQt(this);});
    connect(ui->actionAbout, &QAction::triggered, [this] {
        QString content = tr(
            "<h1>Shortest Path GUI</h1>"
            "<i>Author: xxx</i>"
        );
        QMessageBox::about(this, tr("About"), content);
    });

    for (int i = 0; i <= 16; i++) {
        QString num = num.asprintf("%02d", i);
        connect(ui->frame->findChild<QPushButton *>("pushButton_p" + num), &QPushButton::clicked, [this, i] {
            set_point(i);
        });
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_calculate_clicked() {
    if (ui->radioButton_dijkstra->isChecked()) {
        ui->textBrowser_path->setText(QString::fromStdString(dij(start, end)));
    } else if (ui->radioButton_floyd->isChecked()) {
        ui->textBrowser_path->setText(QString::fromStdString(floyd(start, end)));
    } else
        throw std::runtime_error("no algo select");
}

void MainWindow::set_point(int n) {
    if (isStart) {
        start = n;
        ui->pushButton_start->setText(tr("Start: %1").arg(QString::fromStdString(getName(n))));
    } else {
        end = n;
        ui->pushButton_end->setText(tr("End: %1").arg(QString::fromStdString(getName(n))));
    }
}

void MainWindow::zoom(int addWidth) {
    using namespace std;
    static bool first = true;
    static vector<QPushButton *> buttons;
    static vector<pair<double, double>> points;
    static double raw_width, raw_height;
    if (first) {
        raw_width = ui->label_img->pixmap()->width();
        raw_height = ui->label_img->pixmap()->height();
        ui->label_img->setGeometry(0, 0, raw_width, raw_height);
        ui->label_img->setScaledContents(true);
        ui->frame->setMinimumSize(ui->label_img->width(), ui->label_img->height());
        for (int i = 0; i <= 16; i++) {
            QString num = num.asprintf("%02d", i);
            buttons.push_back(ui->frame->findChild<QPushButton *>("pushButton_p" + num));
            points.push_back(make_pair(
                                 buttons.back()->x() + buttons.back()->width() / 2,
                                 buttons.back()->y() + buttons.back()->height() / 2
                             ));
        }
        first = false;
    }

    double new_width = ui->label_img->width() + addWidth;
    double new_height = raw_height * new_width / raw_width;
    ui->label_img->setGeometry(0, 0, new_width, new_height);
    ui->frame->setMinimumSize(ui->label_img->width(), ui->label_img->height());
    for (size_t i = 0; i < buttons.size(); i++) {
        buttons[i]->setGeometry(
            points[i].first / raw_width * new_width - buttons[i]->width() / 2,
            points[i].second / raw_height * new_height - buttons[i]->height() / 2,
            buttons[i]->width(),
            buttons[i]->height()
        );
    }
}

void MainWindow::on_pushButton_bus1_clicked() {

}

void MainWindow::on_pushButton_bus2_clicked() {

}

void MainWindow::on_pushButton_bus3_clicked() {

}
