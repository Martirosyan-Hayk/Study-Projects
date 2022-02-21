#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_num; /* global member */


MainWindow::MainWindow(QWidget *parent)  /* canstructor whit parametors */
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers())); /* button (number) 0 */
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers())); /* button (number) 1 */
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers())); /* button (number) 2 */
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers())); /* button (number) 3 */
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers())); /* button (number) 4 */
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers())); /* button (number) 5 */
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers())); /* button (number) 6 */
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers())); /* button (number) 7 */
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers())); /* button (number) 8 */
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers())); /* button (number) 9 */
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(math_operations())); /* button (mul) * */
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operations())); /* button (div) / */
    connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(math_operations())); /* button (sub) - */
    connect(ui->pushButton_sum, SIGNAL(clicked()), this, SLOT(math_operations())); /* button (sum) + */
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(operations())); /* button (modul) % */
    connect(ui->pushButton_pos_neg, SIGNAL(clicked()), this, SLOT(operations())); /* button  (math operations) +, -, *, /  */
    connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(on_pushButton_AC_clicked())); /* button (clean) AC */

    /* are clicked */
    ui->pushButton_mul->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
    ui->pushButton_sub->setCheckable(true);
    ui->pushButton_sum->setCheckable(true);

}

MainWindow::~MainWindow() /* destructor */
{
    delete ui;
}

/* private slots of member functions */
void MainWindow::digits_numbers() /* to reade entered numbers */
{
    QPushButton* button = (QPushButton*)sender();

    double all_numbers;
    QString new_label;

    if(ui->result_show->text().contains(".") && button->text() == "0")
    {
        ui->result_show->text() + button->text();
    }
    else
    {
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g',15);
    }
    ui->result_show->setText(new_label);

}
void MainWindow::on_pushButton_dot_clicked()  /* to reade dota */
{
    if(!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text() + ".");
}
void MainWindow::operations()  /* operation (negativ/positive) and modul */
{
    QPushButton* button = (QPushButton*) sender();

    double all_numbers;
    QString new_label;

    if(button->text() == "+/-")
    {
       all_numbers = (ui->result_show->text()).toDouble();
       all_numbers *= -1;
       new_label = QString::number(all_numbers, 'g',15);

       ui->result_show->setText(new_label);
    }
    else if(button->text() == "%")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g',15);

        ui->result_show->setText(new_label);
    }
}
void MainWindow::math_operations() /* math operations (+,-,*,/) */
{
    QPushButton* button = (QPushButton*) sender();

    first_num = ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true);
}
void MainWindow::on_pushButton_AC_clicked() /* clean */
{
    ui->pushButton_sum->setCheckable(false);
    ui->pushButton_sub->setCheckable(false);
    ui->pushButton_mul->setCheckable(false);
    ui->pushButton_div->setCheckable(false);

    ui->result_show->setText("0");
}
void MainWindow::on_pushButton_equal_clicked() /* operation equal */
{
    double labelNumber, second_num;
    QString new_label;

    second_num = ui->result_show->text().toDouble();


    if(ui->pushButton_sum->isChecked())
    {
        labelNumber = first_num + second_num;
        new_label = QString::number(labelNumber, 'g',15);

        ui->result_show->setText(new_label);
        ui->pushButton_sum->setCheckable(false);

    }
    else if(ui->pushButton_sub->isChecked())
    {
        labelNumber = first_num - second_num;
        new_label = QString::number(labelNumber, 'g',15);

        ui->result_show->setText(new_label);
        ui->pushButton_sub->setCheckable(false);

    }
    else if(ui->pushButton_mul->isChecked())
    {
        labelNumber = first_num * second_num;
        new_label = QString::number(labelNumber, 'g',15);

        ui->result_show->setText(new_label);
        ui->pushButton_mul->setCheckable(false);

    }
    else if(ui->pushButton_div->isChecked())
    {
        if(second_num == 0)
        {
            ui->result_show->setText("0");
        }
        else
        {
            labelNumber = first_num / second_num;
            new_label = QString::number(labelNumber, 'g',15);
            ui->result_show->setText(new_label);
        }
         ui->pushButton_div->setCheckable(false);

    }
}













