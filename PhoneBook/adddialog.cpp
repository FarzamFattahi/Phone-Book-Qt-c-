#include "adddialog.h"
#include "ui_AddDialog.h"

#include <QFile>
#include <QDataStream>
#include <QFileInfo>
#include <QStandardItem>
#include <QStandardItemModel>

#define MAGICNUMBER (qint32)0xAA55AA55

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_buttonBox_accepted()
{
    QString wName = ui->NameLineEdit->text();
    QString wPhoneNumber = ui->PhoneNumberLineEdit->text();

    QFile wfile("file.dat");
    wfile.open(QIODevice::Append);
    QDataStream wout(&wfile);
    wout << MAGICNUMBER;
    wout << wName;
    wout << wPhoneNumber;
    wfile.close();

}


void AddDialog::on_buttonBox_rejected()
{

}

