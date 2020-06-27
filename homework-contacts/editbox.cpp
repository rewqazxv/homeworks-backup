#include "editbox.h"
#include "ui_editbox.h"

#include "string.h"

extern "C" {
#include "contacts.h"
}

editbox::editbox(PersonInfo *pI, const QString &title, QWidget *parent) :
    QDialog(parent), ui(new Ui::editbox), pI(pI) {
    ui->setupUi(this);
    setFixedSize(size());
    setWindowTitle(title);

    ui->lineEdit_1->setText(pI->name);
    ui->lineEdit_2->setText(pI->street);
    ui->lineEdit_3->setText(pI->city);
    ui->lineEdit_4->setText(pI->eip);
    ui->lineEdit_5->setText(pI->state);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &editbox::checkSubmit);
    connect(ui->lineEdit_1, &QLineEdit::textChanged, [&] {ui->lineEdit_1->setPlaceholderText("");});
    connect(ui->lineEdit_2, &QLineEdit::textChanged, [&] {ui->lineEdit_2->setPlaceholderText("");});
    connect(ui->lineEdit_3, &QLineEdit::textChanged, [&] {ui->lineEdit_3->setPlaceholderText("");});
    connect(ui->lineEdit_4, &QLineEdit::textChanged, [&] {ui->lineEdit_4->setPlaceholderText("");});
    connect(ui->lineEdit_5, &QLineEdit::textChanged, [&] {ui->lineEdit_5->setPlaceholderText("");});
}

editbox::~editbox() {
    delete ui;
}

void editbox::checkSubmit() {
    bool ignore = false;
    if (ui->lineEdit_1->text().isEmpty()) {
        ui->lineEdit_1->setPlaceholderText(tr("Require this!"));
        ignore = true;
    }
    if (ui->lineEdit_2->text().isEmpty()) {
        ui->lineEdit_2->setPlaceholderText(tr("Require this!"));
        ignore = true;
    }
    if (ui->lineEdit_3->text().isEmpty()) {
        ui->lineEdit_3->setPlaceholderText(tr("Require this!"));
        ignore = true;
    }
    if (ui->lineEdit_4->text().isEmpty()) {
        ui->lineEdit_4->setPlaceholderText(tr("Require this!"));
        ignore = true;
    }
    if (ui->lineEdit_5->text().isEmpty()) {
        ui->lineEdit_5->setPlaceholderText(tr("Require this!"));
        ignore = true;
    }
    if (ignore) return;

    strncpy(pI->name,    ui->lineEdit_1->text().toUtf8().constData(), MAX_CSTR_SIZE - 1);
    strncpy(pI->street,  ui->lineEdit_2->text().toUtf8().constData(), MAX_CSTR_SIZE - 1);
    strncpy(pI->city,    ui->lineEdit_3->text().toUtf8().constData(), MAX_CSTR_SIZE - 1);
    strncpy(pI->eip,     ui->lineEdit_4->text().toUtf8().constData(), MAX_CSTR_SIZE - 1);
    strncpy(pI->state,   ui->lineEdit_5->text().toUtf8().constData(), MAX_CSTR_SIZE - 1);

    pI->name    [MAX_CSTR_SIZE - 1] = 0;
    pI->street  [MAX_CSTR_SIZE - 1] = 0;
    pI->city    [MAX_CSTR_SIZE - 1] = 0;
    pI->eip     [MAX_CSTR_SIZE - 1] = 0;
    pI->state   [MAX_CSTR_SIZE - 1] = 0;

    this->accept();
}
