#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ModelPart.h"
#include "ModelPartList.h"
#include "optiondialog.h"
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void handleButton();
    void handleTreeClicked();
    void handleButton2();
    void on_actionItem_Options_triggered();


signals:
    void statusUpdateMessage(const QString & message, int timeout);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_File_triggered();



private:
    Ui::MainWindow *ui;
    ModelPartList* partList;
};
#endif // MAINWINDOW_H
