#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "kruskal.h"
#include "prim.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_addEdge_clicked() {
    QString a = ui->lineEdit_cityA->text();
    QString b = ui->lineEdit_cityB->text();
    int distance = ui->lineEdit_distance->text().toInt();
    int weight = ui->lineEdit_cost->text().toInt();
    addEdge(a, b, distance, weight);
}

void MainWindow::on_pushButton_clearEdge_clicked() {
    edges.clear();
    cityNameToNum.clear();
    cityNumToName.clear();
    cityCnt = 0;
    refresh_edge();
    on_pushButton_clearRes_clicked();
}

void MainWindow::on_pushButton_clearRes_clicked() {
    ui->textBrowser_path->clear();
    ui->lineEdit_sumCost->clear();
    ui->lineEdit_sumDistance->clear();
}

void MainWindow::on_pushButton_calc_clicked() {
    refresh_edge();
    Mst *mst;
    if (ui->radioButton_kruskal->isChecked())
        mst = new Kruskal(edges);
    else if (ui->radioButton_prim->isChecked())
        mst = new Prim(edges);
    else
        return;
    QStringList show;
    for (const auto &i : mst->result()) {
        show << QString("%1(%2) -- %3(%4), distance:%5, cost:%6").arg(cityNumToName[i.s]).arg(i.s).arg(cityNumToName[i.t]).arg(i.t).arg(i.d).arg(i.w);
    }
    if (mst->result().size() == cityNameToNum.size() - 1) {
        ui->textBrowser_path->setText(show.join('\n'));
        ui->lineEdit_sumCost->setText(QString::number(mst->sumweight()));
        ui->lineEdit_sumDistance->setText(QString::number(mst->sumdistance()));
    } else {
        ui->textBrowser_path->setText("not connected");
    }
    delete mst;
}

void MainWindow::refresh_edge() {
    QStringList show;
    for (const auto &i : edges) {
        show << QString("%1(%2) -- %3(%4), distance:%5, cost:%6").arg(cityNumToName[i.s]).arg(i.s).arg(cityNumToName[i.t]).arg(i.t).arg(i.d).arg(i.w);
    }
    ui->textBrowser_edges->setText(show.join('\n'));
}

void MainWindow::addEdge(QString a, QString b, int d, int w) {
    for (auto i : {a, b})
        if (!cityNameToNum.contains(i)) {
            cityNameToNum[i] = cityCnt;
            cityNumToName[cityCnt] = i;
            cityCnt++;
        }
    edges.push_back(edge(cityNameToNum[a], cityNameToNum[b], d, w));
    refresh_edge();
}

void MainWindow::on_actionOpenFromFile_triggered() {
    QFile f(QFileDialog::getOpenFileName(this));
    f.open(QIODevice::ReadOnly);
    QTextStream ts(f.readAll());
    f.close();

    on_pushButton_clearEdge_clicked();
    while (!ts.atEnd()) {
        QString a, b;
        int d, w;
        ts >> a >> b >> d >> w;
        addEdge(a, b, d, w);
    }
}
