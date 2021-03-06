﻿#include    "mainwindow.h"
#include    "ui_mainwindow.h"
#include    <QMenu>


void MainWindow::setActionsForButton()
{//为QToolButton按钮设置Action
    ui->tBtnListIni->setDefaultAction(ui->actListIni);  //设置初始化列表action

    ui->tBtnListClear->setDefaultAction(ui->actListClear);  //设置清除列表action

    ui->tBtnListInsert->setDefaultAction(ui->actListInsert);    //设置插入项action

    ui->tBtnListAppend->setDefaultAction(ui->actListAppend);    //设置添加项action

    ui->tBtnListDelete->setDefaultAction(ui->actListDelete);    //设置删除当前项action

    ui->tBtnSelALL->setDefaultAction(ui->actSelALL);    //设置全选action

    ui->tBtnSelNone->setDefaultAction(ui->actSelNone);  //设置全部选action

    ui->tBtnSelInvs->setDefaultAction(ui->actSelInvs);  //设置反选action
}

void MainWindow::createSelectionPopMenu()
{
    //创建选择弹出式菜单
    QMenu * menu = new QMenu(this); //创建QMenu类对象

    menu->addAction(ui->actSelALL);  //设置全选action

    menu->addAction(ui->actSelNone);  //设置全不选action

    menu->addAction(ui->actSelInvs);  //设置反选action

    //listWidget上方的tBtnSelectItem按钮
    ui->tBtnSelectItem->setDefaultAction(ui->actSelPopMenu);    //关联Action

    ui->tBtnSelectItem->setPopupMode(QToolButton::MenuButtonPopup);   //菜单弹出模式，执行按钮的Action

    ui->tBtnSelectItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);   //按钮样式

    ui->tBtnSelectItem->setMenu(menu);  //设置下拉菜单

    //工具栏上的 下拉式菜单按钮
    QToolButton * button = new QToolButton(this);

    button->setPopupMode(QToolButton::MenuButtonPopup);  //button's own action is not triggered.

    button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);//按钮样式

    button->setDefaultAction(ui->actSelPopMenu);    //设置Action,获取图标、标题等设置

    button->setMenu(menu);  //设置下拉菜单

    ui->mainToolBar->addWidget(button);//工具栏添加按钮

    //工具栏添加分隔条，和“退出”按钮
    ui->mainToolBar->addSeparator();    //增加分隔条

    ui->mainToolBar->addAction(ui->actQuit);    //增加退出按钮
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->splitter); //设置中心组件
    setActionsForButton();  //为QToolButton按钮设置Action
    createSelectionPopMenu();   //创建下拉菜单
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actListClear_triggered()
{
    ui->listWidget->clear(); //清除项
}

void MainWindow::on_actListIni_triggered()
{ //初始化项
    QListWidgetItem * aItem;    //创建一个QListWidgetItem类对象指针

    QIcon Icon(":/images/icons/check2.ico");    //创建一个按键图标

    bool chk = ui->chkBoxListEditable->isChecked(); //创建chk变量判断是否可编辑

    ui->listWidget->clear();    //清空列表

    for (int i = 0; i < 10; i++)
    {
        aItem = new QListWidgetItem();  //新建一个QListWidgetItem类对象

        QString str = QString::asprintf("Item %d", i);  //创建字符串用于显示

        aItem->setText(str);    //设置文字

        aItem->setIcon(Icon);   //设置按键

        aItem->setCheckState(Qt::Checked);  //设置可选状态

        if(chk)
        {
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        }
        else
        {
            aItem->setFlags(Qt::ItemIsSelectable |  Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        }

        ui->listWidget->addItem(aItem); //添加到列表中
    }
}

void MainWindow::on_chkBoxListEditable_clicked(bool checked)
{ //可编辑 QCheckBox的响应代码， 设置所有项是否可编辑
    int i, cnt;

    QListWidgetItem * aItem;

    cnt = ui->listWidget->count();

    for (i = 0; i < cnt; i++)
    {
        aItem = ui->listWidget->item(i);

        if(checked)
        {
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        }
        else
        {
            aItem->setFlags(Qt::ItemIsSelectable |  Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        }
    }
}

void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{ //listWidget当前选中项发生变化
    QString str;

    if (current != NULL)
    {
        if (previous == NULL)
        {
            str = "当前：" + current->text();
        }
        else
        {
            str="前一项："+previous->text()+"; 当前项："+current->text();
        }

        ui->editCutItemText->setText(str);
    }
}

void MainWindow::on_actListInsert_triggered()
{   //插入一个项
    QIcon icon(":/images/icons/check2.ico");    //创建一个按键图标

    QListWidgetItem * item = new QListWidgetItem("New Inserted Item");

    bool chk = ui->chkBoxListEditable->isChecked();

    item->setIcon(icon);

    item->setCheckState(Qt::Checked);

    if(chk)
    {
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    }
    else
    {
        item->setFlags(Qt::ItemIsSelectable |  Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    }

    ui->listWidget->insertItem(ui->listWidget->currentRow(), item);
}

void MainWindow::on_actListAppend_triggered()
{//增加一个项
    QIcon icon(":/images/icons/check2.ico");    //创建一个按键图标

    QListWidgetItem * item = new QListWidgetItem("New Added Item");

    bool chk = ui->chkBoxListEditable->isChecked();

    item->setIcon(icon);

    item->setCheckState(Qt::Checked);

    if(chk)
    {
        item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    }
    else
    {
        item->setFlags(Qt::ItemIsSelectable |  Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    }

    ui->listWidget->addItem(item);
}

void MainWindow::on_actListDelete_triggered()
{ //删除当前项
    int row = ui->listWidget->currentRow(); //获取当前选中的项

    QListWidgetItem * item = ui->listWidget->takeItem(row); //移除当前项，但不delete

    delete item;

//    QListWidgetItem *QListWidget::takeItem(int row)
//    Removes and returns the item from the given row in
//            the list widget; otherwise returns 0.
//    Items removed from a list widget will not be managed by Qt,
//            and will need to be deleted manually.
}

void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{ //创建右键快捷菜单
    Q_UNUSED(pos);

    QMenu * menuList = new QMenu(this); //创建菜单

    menuList->addAction(ui->actListIni);

    menuList->addAction(ui->actListClear);

    menuList->addAction(ui->actListInsert);

    menuList->addAction(ui->actListAppend);

    menuList->addAction(ui->actListDelete);

    menuList->addSeparator();

    menuList->addAction(ui->actSelALL);

    menuList->addAction(ui->actSelInvs);

    menuList->addAction(ui->actSelNone);

    menuList->exec(QCursor::pos());

    delete menuList;
}

void MainWindow::on_toolBox_currentChanged(int index)
{
    ui->tabWidget->setCurrentIndex(index);//ToolBox当前页与tabWidget的当前页联动
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->toolBox->setCurrentIndex(index);
}

void MainWindow::on_actSelALL_triggered()
{ //项全选
    int cnt=ui->listWidget->count();//项个数
    for (int i=0; i<cnt; i++)
    {
        QListWidgetItem *aItem=ui->listWidget->item(i);//获取一个项
        aItem->setCheckState(Qt::Checked);//设置为选中
    }
}

void MainWindow::on_actSelNone_triggered()
{ //全不选
    int i,cnt;
    QListWidgetItem *aItem;

    cnt=ui->listWidget->count();//项个数
    for (i=0; i<cnt; i++)
    {
        aItem=ui->listWidget->item(i);//获取一个项
        aItem->setCheckState(Qt::Unchecked);//不选
    }
}

void MainWindow::on_actSelInvs_triggered()
{//反选
    int i,cnt;
    QListWidgetItem *aItem;

    cnt=ui->listWidget->count();//项个数
    for (i=0; i<cnt; i++)
    {
        aItem=ui->listWidget->item(i);//获取一个项
        if (aItem->checkState()!=Qt::Checked)
            aItem->setCheckState(Qt::Checked);
        else
            aItem->setCheckState(Qt::Unchecked);
    }

}
