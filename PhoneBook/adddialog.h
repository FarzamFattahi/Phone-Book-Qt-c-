#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QFile>
#include <QDataStream>
#include <QFileInfo>
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();



private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
