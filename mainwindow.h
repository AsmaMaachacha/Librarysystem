#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "library.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddBookClicked();
    void onAddUserClicked();
    void onBorrowClicked();
    void onReturnClicked();

private:
    Ui::MainWindow *ui;
    Library library;

    void updateResourceTable();
    void updateUsersTable();
    void updateLoansTable();
};

#endif // MAINWINDOW_H
