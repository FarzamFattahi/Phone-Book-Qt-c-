#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString selectedName();
    QString selectedPhoneNumber();
private slots:
    void on_BTNAdd_clicked();

    void on_BTNEdit_clicked();

    void on_BTNDelete_clicked();

    void on_BTNReload_clicked();

    void on_BTNExport_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *mModel;
};
#endif // MAINWINDOW_H
