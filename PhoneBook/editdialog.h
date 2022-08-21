#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QModelIndex>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = nullptr);
    ~EditDialog();

private:
    Ui::EditDialog *ui;
    QModelIndex row;
};

#endif // EDITDIALOG_H
