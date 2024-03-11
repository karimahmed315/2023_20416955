#include "optiondialog.h"
#include "ui_optiondialog.h"
#include "mainwindow.h"

OptionDialog::OptionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OptionDialog)
{
    ui->setupUi(this);

}

OptionDialog::~OptionDialog()
{
    delete ui;
}





