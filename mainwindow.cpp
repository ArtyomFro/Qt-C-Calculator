#include "mainwindow.h"
#include "./ui_mainwindow.h"

double num_first;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pb_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pb_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pb_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pb_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pb_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pb_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pb_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pb_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pb_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pb_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pb_plmn,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pb_modulus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pb_divide,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pb_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pb_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pb_multiplie,SIGNAL(clicked()),this,SLOT(math_operations()));
    ui->pb_divide->setCheckable(true);
    ui->pb_plus->setCheckable(true);
    ui->pb_minus->setCheckable(true);
    ui->pb_multiplie->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
QPushButton * button = (QPushButton *)sender();
double all_numbers;
QString new_label;
if(ui->result_show->text().contains(".")&&button->text()=="0")
{
    new_label = ui->result_show->text()+button->text();
}else{
all_numbers = (ui->result_show->text()+button->text()).toDouble();
new_label= QString::number(all_numbers,'g', 15);
}
ui->result_show->setText(new_label);
}

void MainWindow::on_pb_point_clicked()
{
    if(!ui->result_show->text().contains('.'))
    ui->result_show->setText(ui->result_show->text()+'.');
}

void MainWindow::operations()
{
QPushButton * button = (QPushButton *)sender();
double all_numbers;
QString new_label;
if(button->text()=="+/-"){
    all_numbers = (ui->result_show->text()).toDouble();
    all_numbers = all_numbers * -1;
    new_label= QString::number(all_numbers,'g', 15);
    ui->result_show->setText(new_label);
}else if(button->text()=="%"){
    all_numbers = (ui->result_show->text()).toDouble();
    all_numbers = all_numbers * 0.01;
    new_label= QString::number(all_numbers,'g', 15);
    ui->result_show->setText(new_label);
}
}

void MainWindow::math_operations()
{
    QPushButton * button = (QPushButton *)sender();
    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true);

}

void MainWindow::on_pb_AC_clicked()
{
 ui->pb_plus->setChecked(false);
 ui->pb_minus->setChecked(false);
 ui->pb_divide->setChecked(false);
 ui->pb_multiplie->setChecked(false);
 ui->result_show->setText("0");
}


void MainWindow::on_pb_equal_clicked()
{
    QString new_label;
    double labelNumber, num_second;
    num_second = ui->result_show->text().toDouble();
    if(ui->pb_plus->isChecked()){
            labelNumber=num_first + num_second;
            new_label = QString::number(labelNumber,'g',15);
            ui->result_show->setText(new_label);
            ui->pb_plus->setChecked(false);
    }else if(ui->pb_divide->isChecked()){
        if(num_second == 0){
        ui->result_show->setText("0");
        }
        labelNumber=num_first / num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->pb_divide->setChecked(false);
    }else if(ui->pb_minus->isChecked()){
        labelNumber=num_first - num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->pb_minus->setChecked(false);
    }else if(ui->pb_multiplie->isChecked()){
        labelNumber=num_first * num_second;
        new_label = QString::number(labelNumber,'g',15);
        ui->result_show->setText(new_label);
        ui->pb_multiplie->setChecked(false);
    }
}

