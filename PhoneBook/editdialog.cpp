#include "editdialog.h"
#include "ui_editdialog.h"
#include "mainwindow.h"

#include <QDebug>

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    MainWindow myMain;
    myMain.selectedName();
    //ui->lineEdit->setText(myMain.selectedName());
    //ui->lineEdit_2->setText(myMain.selectedPhoneNumber());
}

EditDialog::~EditDialog()
{
    delete ui;
}
