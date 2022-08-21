#include "deletedialog.h"
#include "ui_deletedialog.h"

#include <QFile>
#define MAGICNUMBER 0xAA55AA55

DeleteDialog::DeleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}

void DeleteDialog::on_buttonBox_rejected()
{
    QFile rfile("Temp.dat");
    rfile.open(QIODevice::ReadOnly);
    QDataStream rout(&rfile);
    QString rName,rPhoneNumber;
    qint32 Magicnumber;

    rout >> Magicnumber;
    rout >> rName;
    rout >> rPhoneNumber;

    QFile wfile("file.dat");
    wfile.open(QIODevice::Append);
    QDataStream wout(&wfile);
    wout << MAGICNUMBER;
    wout << rName;
    wout << rPhoneNumber;


    rfile.remove();
    wfile.close();
}


void DeleteDialog::on_buttonBox_accepted()
{
    QFile rfile("Temp.dat");
    rfile.open(QIODevice::ReadOnly);

    rfile.remove();
}

