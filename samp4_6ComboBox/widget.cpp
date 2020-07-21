#include "widget.h"
#include "ui_widget.h"

#include    <QTextDocument>
#include    <QTextBlock>
#include    <QMenu>

#include    <QMap>
#include    <QVariant>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnIniItems_clicked()
{ //"初始化列表"按键
    QIcon icon;

    icon.addFile(":/images/icons/aim.ico");

    ui->comboBox->clear();  //清除列表

    for (uint i = 0; i < 20; i++)
    {
        ui->comboBox->addItem(icon,QString::asprintf("item %d", i));
    }
}

void Widget::on_btnClearItems_clicked()
{
    ui->comboBox->clear(); //清除条目
}

void Widget::on_chkBoxEditable_clicked(bool checked)
{ //设置comboBox是否可编辑
    ui->comboBox->setEditable(checked);
}

void Widget::on_comboBox_currentIndexChanged(const QString &arg1)
{ //comboBox选择一个条目时，文本添加到 plainTextEdit
    if (!arg1.isEmpty())
    {//用来排除"初始化列表"按键产生的空白内容
        ui->plainTextEdit->appendPlainText(arg1);
    }
}

void Widget::on_btnClearText_clicked()
{ //清除文本框
    ui->plainTextEdit->clear();
}

void Widget::on_chkBoxReadonly_clicked(bool checked)
{//设置 plainTextEdit 的 ReadOnly 属性
    ui->plainTextEdit->setReadOnly(checked);
}

void Widget::on_btnToComboBox_clicked()
{ //plainTextEdit 的内容逐行添加为 comboBox 的条目
    QTextDocument *doc = ui->plainTextEdit->document();    //QPlainTextEdit 的内容保存在一个 QTextDocument 里

     int cnt = doc->blockCount();    //QTextDocument分块保存内容，文本文件就是硬回车符是一个block,

     QIcon icon;

     icon.addFile(":/images/icons/aim.ico");

     ui->comboBox->clear(); //清除条目

     for (int i = 0; i < cnt; i++) //扫描所有 blobk
     {
         QTextBlock text = doc->findBlockByNumber(i); //用blobk编号获取block，就是获取一行

         QString str = text.text();//转换为文本

         ui->comboBox->addItem(icon,str);    //添加一个条目到comboBox
     }
}

void Widget::on_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{ //创建并显示标准弹出式菜单
    QMenu* menu=ui->plainTextEdit->createStandardContextMenu(); //创建标准右键菜单
//    menu->exec(QCursor::pos());//在鼠标光标位置显示右键快捷菜单
    menu->exec(pos);//在鼠标光标位置显示右键快捷菜单
}

void Widget::on_btnIni2_clicked()
{//初始化具有自定义数据的comboBox
//QMap自动根据 key排序
    QMap<QString, int> City_Zone;

    City_Zone.insert("北京",10);

    City_Zone.insert("上海",21);

    City_Zone.insert("天津",22);

    City_Zone.insert("大连",411);

    City_Zone.insert("锦州",416);

    City_Zone.insert("徐州",516);

    City_Zone.insert("福州",591);

    City_Zone.insert("青岛",532);

    ui->comboBox2->clear();

    foreach (const QString &str, City_Zone.keys())
    {//City_Zone.keys()返回了一个按升序包含映射中所有键的列表，所以与初始化列表顺序不同
        ui->comboBox2->addItem(str,City_Zone.value(str));
    }
}

void Widget::on_comboBox2_currentIndexChanged(const QString &arg1)
{ //条目有用户数据
    QString zone=ui->comboBox2->currentData().toString();

    if (!zone.isEmpty())
    {//用来排除初始化具有自定义数据的comboBox产生的空白内容
        ui->plainTextEdit->appendPlainText(arg1+":区号="+zone);
    }
}
