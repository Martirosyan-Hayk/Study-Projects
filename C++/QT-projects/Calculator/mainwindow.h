#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); /* canstructor whit parametors */
    ~MainWindow(); /* destructor */
private slots:
    /* private slots of member functions */
    void digits_numbers();  /* to reade entered numbers */
    void on_pushButton_dot_clicked(); /* to reade dota */
    void operations(); /* operation (negativ/positive) and modul */
    void math_operations(); /* math operations (+,-,*,/) */
    void on_pushButton_AC_clicked(); /* clean */
    void on_pushButton_equal_clicked(); /* operation equal */

private:
    Ui::MainWindow *ui; /* private member pointer */
};

#endif /* MAINWINDOW_H */
