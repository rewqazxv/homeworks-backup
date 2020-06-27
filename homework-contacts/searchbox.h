#ifndef SEARCHBOX_H
#define SEARCHBOX_H

#include <QDialog>

namespace Ui {
class SearchBox;
}

class SearchBox : public QDialog {
    Q_OBJECT

  signals:
    void acceptedSearch(const QString &name);

  public:
    explicit SearchBox(QWidget *parent = 0);
    ~SearchBox();

  private:
    Ui::SearchBox *ui;

  private slots:
    void checkSubmit();
};

#endif // SEARCHBOX_H
