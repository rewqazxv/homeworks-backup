#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "searchbox.h"
#include "editbox.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QColor>
#include <QCloseEvent>
#include <string>
#include <assert.h>

extern "C" {
#include "contacts.h"
#include "list.h"
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::file_new);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::file_open);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::file_save);
    connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::file_saveas);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionAdd, &QAction::triggered, this, &MainWindow::add);
    connect(ui->actionDelete, &QAction::triggered, this, &MainWindow::del);
    connect(ui->actionEdit, &QAction::triggered, this, &MainWindow::edit);
    connect(ui->actionFind, &QAction::triggered, this, &MainWindow::search);
    connect(ui->actionAbout, &QAction::triggered, [&] {
        QMessageBox::about(this, tr("About"), tr("Data structure curriculum design."));
    });
    connect(ui->actionAbout_QT, &QAction::triggered, [&] {QMessageBox::aboutQt(this, tr("About QT"));});

    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::_checkSelection);
    connect(ui->tableWidget, &QTableWidget::itemDoubleClicked, this, &MainWindow::edit);

    refresh();
    _checkSelection();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::refresh() {
    ui->tableWidget->setRowCount(list_size(contacts));
    int i = 0;
    list_PtrToNode p = list_begin(contacts);
    for (; p != list_end(contacts); i++, p = p->next) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString(list_getdata_ref(p, PersonInfo).name)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString(list_getdata_ref(p, PersonInfo).street)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString(list_getdata_ref(p, PersonInfo).city)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString(list_getdata_ref(p, PersonInfo).eip)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString(list_getdata_ref(p, PersonInfo).state)));
    }
}

bool MainWindow::_ask_save_file() {
    if (isWindowModified()) {
        switch (QMessageBox::question(
                    this,
                    tr("Save file"),
                    tr("Contacts has been modified. Do you want to save it before close file?"),
                    QMessageBox::StandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel),
                    QMessageBox::Save)) {
        case QMessageBox::Save:
            return file_save();
        case QMessageBox::Discard:
            return true;
        case QMessageBox::Cancel:
            return false;
        default:
            assert(0);
            return false;
        }
    } else return true;
}

void MainWindow::file_new() {
    if (_ask_save_file()) {
        list_clear(contacts);
        setWindowFilePath(QString());
        setWindowModified(false);
        refresh();
    }
}

void MainWindow::file_open() {
    if (_ask_save_file()) {
        QString path = QFileDialog::getOpenFileName(this);
        if (path.isEmpty()) return;
        if (contacts_load(path.toUtf8().constData()) != CONTACTS_OK) {
            setWindowFilePath(QString());
            QMessageBox::warning(this, tr("Open Error"), tr("Can not open file: '%1'").arg(path));
        } else setWindowFilePath(path);
        setWindowModified(false);
        refresh();
    }
}

bool MainWindow::_file_saveto(QString file_path) {
    return contacts_save(file_path.toUtf8().constData()) == CONTACTS_OK;
}

bool MainWindow::file_save() {
    if (windowFilePath().isEmpty()) return file_saveas();
    if (_file_saveto(windowFilePath())) {
        setWindowModified(false);
        return true;
    } else {
        QMessageBox::warning(this, tr("Save Error"), tr("Can not save file: '%1'").arg(windowFilePath()));
        return false;
    }
}

bool MainWindow::file_saveas() {
    QString path = QFileDialog::getSaveFileName(this);
    if (!path.isEmpty()) {
        if (_file_saveto(path)) {
            setWindowFilePath(path);
            setWindowModified(false);
            return true;
        } else {
            QMessageBox::warning(this, tr("Save Error"), tr("Can not save file: '%1'").arg(path));
            return false;
        }
    } else return false;
}

void MainWindow::_checkSelection() {
    bool valid = ui->tableWidget->selectedRanges().size() != 0;
    ui->actionDelete->setEnabled(valid);
    ui->actionEdit->setEnabled(valid);
}

void MainWindow::add() {
    PersonInfo pI = {};
    editbox e(&pI, tr("Create a new contact"), this);
    if (e.exec() == QDialog::Accepted) {
        contacts_add(&pI);
        setWindowModified(true);
        refresh();
    }
}

void MainWindow::del() {
    QString name = ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text();
    switch (QMessageBox::question(
                this,
                tr("Delete confirm"),
                tr("Do you confirm to remove contact '%1'?").arg(name),
                QMessageBox::StandardButtons(QMessageBox::Yes | QMessageBox::No),
                QMessageBox::No)) {
    case QMessageBox::Yes:
        contacts_delete(ui->tableWidget->currentRow());
        setWindowModified(true);
        refresh();
        break;
    default:
        break;
    }
}

void MainWindow::edit() {
    int n = ui->tableWidget->currentRow();
    assert((size_t) n < list_size(contacts));
    editbox e((PersonInfo *) contacts_getnptr(n)->data, tr("Edit contact"), this);
    if (e.exec() == QDialog::Accepted) {
        setWindowModified(true);
        refresh();
    }
}

void MainWindow::search() {
    auto _setRowColor = [&](int row, const QColor & color) {
        for (int col = 0; col < ui->tableWidget->columnCount(); col++)
            ui->tableWidget->item(row, col)->setBackgroundColor(color);
    };
    for (int row = 0; row < ui->tableWidget->rowCount(); row++)
        _setRowColor(row, Qt::white);

    SearchBox s(this);
    connect(&s, &SearchBox::acceptedSearch, [&](const QString & name) {
        size_t *a = contacts_search(name.toUtf8().constData());
        if (*a == (size_t) -1) {
            QMessageBox::warning(this, tr("Not found"), tr("Name '%1' not found").arg(name));
        } else {
            for (int i = 0; a[i] != (size_t) -1; i++)
                _setRowColor(a[i], Qt::green);
            ui->tableWidget->setCurrentCell(*a, 0);
        }
    });
    s.exec();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (_ask_save_file()) QMainWindow::closeEvent(event);
    else event->ignore();
}
