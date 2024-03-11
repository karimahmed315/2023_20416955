#include "optiondialog.h"
#include "ui_optiondialog.h"
#include <QMessageBox>


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

void OptionDialog::on_lineEdit_textEdited(const QString &arg1)
{

}


void OptionDialog::on_buttonBox_accepted()
{
    QString part = ui->lineEdit->text(); // Assuming you have a QLineEdit widget named "lineEdit"
    QColor partco = ui->comboBox->currentColor(); // Assuming you have a QColorDialog widget
    bool isVisible = ui->checkBox->isChecked(); // Assuming you have a checkbox for visibility

}

