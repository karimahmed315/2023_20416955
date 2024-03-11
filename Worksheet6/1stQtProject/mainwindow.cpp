#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "optiondialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Create and allocate the ModelList
    this->partList = new ModelPartList("Parts List");

    // Link it to the tree view in the GUI
    ui->treeView->setModel(this->partList);

    // Manually create a model tree (quick example)
    ModelPart* rootItem = this->partList->getRootItem();

    // Add 3 top-level items
    for (int i = 0; i < 3; i++) {
        QString name = QString("TopLevel %1").arg(i);
        QString visible = "true";
        ModelPart* childItem = new ModelPart({name, visible});
        rootItem->appendChild(childItem);

        // Add 5 sub-items
        for (int j = 0; j < 5; j++) {
            QString subName = QString("Item %1,%2").arg(i).arg(j);
            ModelPart* subChildItem = new ModelPart({subName, visible});
            childItem->appendChild(subChildItem);
        }
    }
    connect(ui->treeView, &QTreeView::clicked, this, &MainWindow::handleTreeClicked);
    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::handleButton);
    connect(this, &MainWindow::statusUpdateMessage, ui ->statusbar, &QStatusBar::showMessage);
    connect(ui->pushButton_2, &QPushButton::released, this, &MainWindow::handleButton2);
    ui -> treeView ->addAction(ui->actionItem_Options);


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton()
{
    emit statusUpdateMessage(QString("Add button was clicked"), 0);
}

void MainWindow::handleTreeClicked()
{
    emit statusUpdateMessage(QString("TreeView was clicked"), 0);
    // Get the currently selected item index
    QModelIndex index = ui->treeView->currentIndex();

    // Retrieve the name string from the internal QVariant data
    QString text = static_cast<ModelPart*>(index.internalPointer())->data(0).toString();

    // Emit a status update message
    emit statusUpdateMessage("The selected item is: " + text, 0);

}

void MainWindow::on_actionOpen_File_triggered()
{
    emit statusUpdateMessage( QString("Open File action triggered"),0);
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"),"C:\\",tr("STL Files(*.stl);;Text Files(*.txt)"));
        // Handle the selected file (e.g., open it)
        emit statusUpdateMessage("The selected file to open is: " + filename
            , 0);
 
}


void MainWindow::handleButton2()
{
    OptionDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        emit statusUpdateMessage(QString("Dialog accepted"), 0);
    } else {
        emit statusUpdateMessage(QString("Dialog rejected"), 0);
    }

}


void MainWindow::on_actionItem_Options_triggered()
{
    emit statusUpdateMessage( QString("Options Context Menu Opened"),0);

}

