#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  private:
    Ui::MainWindow *ui;
    void refresh();
    void file_new();
    void file_open();
    bool file_save();
    bool file_saveas();
    void add();
    void del();
    void edit();
    void search();
    bool _ask_save_file();
    bool _file_saveto(QString file_path);
    void _checkSelection();

  protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // MAINWINDOW_H
