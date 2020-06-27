#ifndef EDITBOX_H
#define EDITBOX_H

#include <QDialog>

extern "C" {
#include "contacts.h"
}

namespace Ui {
class editbox;
}

class editbox : public QDialog {
    Q_OBJECT

  public:
    explicit editbox(PersonInfo *pI, const QString &title, QWidget *parent = 0);
    ~editbox();

  private:
    Ui::editbox *ui;
    PersonInfo *pI;
    void checkSubmit();
};

#endif // EDITBOX_H
