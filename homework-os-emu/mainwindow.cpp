#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9 ]*")));
    ui->spinBox->setMinimum(1);

    act = new QAction(this);
    connect(act, &QAction::triggered, [this] {
        QStringList sl = ui->lineEdit->text().split(' ', QString::SkipEmptyParts);
        vector<int> pages;
        for (const auto &i : sl) {
            pages.push_back(i.toInt());
            if (pages.back() >= sl.size()) {
                QMessageBox::warning(this, "错误", "有过大的页面号");
                return;
            }
        }
        const int block_num = ui->spinBox->value();
        show_values(block_num, pages, op, ui->label_op, ui->tableWidget_op);
        show_values(block_num, pages, fifo, ui->label_fifo, ui->tableWidget_fifo);
        show_values(block_num, pages, lru, ui->label_lru, ui->tableWidget_lru);
    });

    connect(ui->pushButton, &QPushButton::clicked, act, &QAction::trigger);
    connect(ui->lineEdit, &QLineEdit::returnPressed, ui->pushButton, &QPushButton::click);

    clear = new QAction(this);
    connect(clear, &QAction::triggered, [this] {
        ui->label_op->clear();
        ui->label_fifo->clear();
        ui->label_lru->clear();
        ui->tableWidget_op->setRowCount(0);
        ui->tableWidget_fifo->setRowCount(0);
        ui->tableWidget_lru->setRowCount(0);
    });

    connect(ui->lineEdit, &QLineEdit::textChanged, clear, &QAction::trigger);
    connect(ui->spinBox, qOverload<int>(&QSpinBox::valueChanged), clear, &QAction::trigger);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::show_values(const int block_num, const pages_t &pages, std::function<blocks_log(const int, const pages_t &)> f, QLabel *msg, QTableWidget *table) {
    if (pages.size() == 0) return;
    auto log = f(block_num, pages);
    auto calc = missing_and_displacement(log);
    msg->setText(QString("缺页率: %1%, 置换率: %2%").arg(calc.first * 100).arg(calc.second * 100));

    table->setColumnCount(block_num + 1);
    table->setRowCount(pages.size());
    for (size_t i = 0; i < pages.size(); i++)
        table->setItem(i, 0, new QTableWidgetItem(QString("(%1)").arg(pages[i])));

    QFont blod_font;
    blod_font.setBold(true);
    for (size_t i = 0; i < log.size(); i++)
        for (size_t j = 0; j < log[i].size(); j++)
            if (log[i][j] != NOPAGE) {
                table->setItem(i, j + 1, new QTableWidgetItem(QString::number(log[i][j])));
                if (i > 0 && log[i][j] == log[i - 1][j])
                    table->item(i, j + 1)->setTextColor(Qt::GlobalColor::gray);
                else {
                    table->item(i, j + 1)->setFont(blod_font);
                }
            }
}
