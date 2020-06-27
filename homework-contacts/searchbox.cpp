#include "searchbox.h"
#include "ui_searchbox.h"

SearchBox::SearchBox(QWidget *parent) :
    QDialog(parent), ui(new Ui::SearchBox) {
    ui->setupUi(this);
    setFixedSize(size());

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SearchBox::checkSubmit);
    connect(ui->lineEdit, &QLineEdit::textChanged, [&] {ui->lineEdit->setPlaceholderText("");});
}

SearchBox::~SearchBox() {
    delete ui;
}

void SearchBox::checkSubmit() {
    if (ui->lineEdit->text().isEmpty())
        ui->lineEdit->setPlaceholderText(tr("Require name!"));
    else {
        this->accept();
        emit acceptedSearch(ui->lineEdit->text());
    }
}
