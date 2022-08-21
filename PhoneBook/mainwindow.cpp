#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "adddialog.h"
#include "editdialog.h"
#include "deletedialog.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QList>
#include <QDebug>
#include <QList>

#define MAGICNUMBER 0XAA55AA55

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BTNAdd_clicked()
{
     AddDialog AD;

     AD.exec();
}


void MainWindow::on_BTNEdit_clicked()
{
    QString name = MainWindow::selectedName();
    QString phonenumber = MainWindow::selectedName();



    EditDialog ED;
    ED.exec();
}


void MainWindow::on_BTNDelete_clicked()
{
    QList<QList<QString>> MyList;
    QList<QString> MyItem;

    QFile rfile("file.dat");
    rfile.open(QIODevice::ReadOnly);
    QDataStream rout(&rfile);
    QString rName,rPhoneNumber;
    qint32 Magicnumber;
    while (!rfile.atEnd()) {
        rout >> Magicnumber;

        rout >> rName;
        MyItem.append(rName);

        rout >> rPhoneNumber;
        MyItem.append(rPhoneNumber);

        MyList.append(MyItem);
        MyItem.clear();
    }

    rfile.close();



    QModelIndex index = mModel->index(ui->TableView->selectionModel()->currentIndex().row(), 0, QModelIndex());
    QString name = ui->TableView->model()->data(index).toString();


    QFile wfile("file.dat");
    wfile.open(QIODevice::WriteOnly);
    QDataStream wout(&wfile);

    for (auto item : MyList) {

        if(item.first() != name){
            wout << MAGICNUMBER;
            wout << item[0];
            wout << item[1];
            qDebug()<<item[0]<<item[1]<<"\n";
        }
        else{
            QFile Tempfile("Temp.dat");
            Tempfile.open(QIODevice::WriteOnly);
            QDataStream TempOut(&Tempfile);

            TempOut << MAGICNUMBER;
            TempOut << item.first();
            TempOut << item.last();

            Tempfile.close();
        }
    }
    wfile.close();

    DeleteDialog DD;
    DD.exec();

}

QString MainWindow::selectedName(){

    QModelIndex index = mModel->index(ui->TableView->selectionModel()->currentIndex().row(), 0, QModelIndex());
    QString name = ui->TableView->model()->data(index).toString();
    return name;
}

QString MainWindow::selectedPhoneNumber(){

    QModelIndex index = mModel->index(ui->TableView->selectionModel()->currentIndex().row(), 1, QModelIndex());
    QString phonenumber = ui->TableView->model()->data(index).toString();
    return phonenumber;
}


void MainWindow::on_BTNReload_clicked()
{
    mModel = new QStandardItemModel();

    QList<QStandardItem *> items;

    QFile rfile("file.dat");
    rfile.open(QIODevice::ReadOnly);
    QDataStream rout(&rfile);
    QString rName,rPhoneNumber;
    qint32 Magicnumber;
    while (!rfile.atEnd()) {
        rout >> Magicnumber;

        rout >> rName;
        auto name = new QStandardItem(rName);

        rout >> rPhoneNumber;
        auto phonenumber = new QStandardItem(rPhoneNumber);

        items << name << phonenumber;

        mModel->appendRow(items);
        items.clear();
    }

    ui->TableView->setModel(mModel);

    rfile.close();
}


void MainWindow::on_BTNExport_clicked()
{


    QFile rfile("file.dat");
    rfile.open(QIODevice::ReadOnly);
    QDataStream rout(&rfile);
    QString rName,rPhoneNumber;
    qint32 Magicnumber;


    QFile wfile("file.csv");
    wfile.open(QIODevice::WriteOnly);
    QTextStream wout(&wfile);


    while (!rfile.atEnd()) {
        rout >> Magicnumber;
        rout >> rName;
        wout << rName << ",";

        rout >> rPhoneNumber;
        wout << rPhoneNumber << "\n";
    }
    rfile.close();
    wfile.close();
}

