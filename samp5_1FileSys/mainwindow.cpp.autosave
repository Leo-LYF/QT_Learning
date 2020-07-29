#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QFileSystemModel;   //QFileSystemModel提供单独线程，推荐使用

    model->setRootPath(QDir::currentPath());    //设置根目录

    ui->treeView->setModel(model);  //设置数据模型

    ui->listView->setModel(model);  //设置数据模型

    ui->tableView->setModel(model); //设置数据模型

//信号与槽关联，treeView单击时，其目录设置为listView和tableView的根节点
    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), ui->listView, SLOT(setRootIndex(QModelIndex)));

    connect(ui->treeView, SIGNAL(clicked(QModelIndex)), ui->tableView, SLOT(setRootIndex(QModelIndex)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    ui->chkIsDir->setChecked(model->isDir(index));   // 判断节点是否为目录

    ui->LabPath->setText(model->filePath(index));   //设置节点路径信息

    ui->LabType->setText(model->type(index));   //设置节点类型信息

    ui->LabFileName->setText(model->fileName(index));   //设置节点文件名

    int sz = model->size(index) / 1024.0;    //获取节点大小

    if (sz < 1024)
    {
        ui->LabFileSize->setText(QString("%1 KB").arg(sz));
    }
    else
    {
        ui->LabFileSize->setText(QString::asprintf("%.1f MB",sz / 1024.0));
    }
}
