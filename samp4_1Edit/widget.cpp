#include "widget.h"
#include "ui_widget.h"
#include    <QString>

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

void Widget::on_btnCal_clicked()
{
    QString str = ui->editNum->text();  //创建一个QString类的对象str，读取QLineEdit类的对象editNum中的值后赋值给str

    int num = str.toInt();  //创建一个临时int型变量num，通过QString类公有函数toInt(),将str内容转换为整型

    str = ui->editPrice->text();    //读取QLineEdit类的对象editPrice中的值后赋值给str

    float price = str.toFloat();    //创建一个临时int型变量price，通过QString类公有函数toFloat(),将str中的价格字符串转换为浮点型

    float total = num * price;  //数量乘单价得到总价

    str = str.sprintf("%.2f", total);    //将浮点型变量总价通过str成员函数sprintf转换成字符串并赋值给str

    ui->editTotal->setText(str);    //通过QString类成员函数函数setText()更新editTotal的内容，再在ui上的editTotal总价框上显示str字符串的内容
}

void Widget::on_btnDec_clicked()
{
    int val = ui->editDec->text().toInt();  //读取十进制数

    QString str = QString::number(val,2);   //将val转换为二进制字符串

    ui->editBin->setText(str);   //在UI显示

    str = QString::number(val,16);   //将val转换为十六进制字符串

    str = str.toUpper();    //大写显示

    ui->editHex->setText(str);   //在UI显示
}

void Widget::on_btnBin_clicked()
{
    bool ok;    //创建布尔变量

    int val = ui->editBin->text().toInt(&ok, 2);   //读取字符串并转为为二进制数

    QString str = QString::number(val, 10); //数字显示十进制文件

    ui->editDec->setText(str);  //显示10进制数字符串

    str = QString::number(val, 16); //数字显示十六进制文件

    str = str.toUpper();   //全大写字母显示

    ui->editHex->setText(str);  //显示十六进制数字符串
}

void Widget::on_btnHex_clicked()
{
    bool ok;    //创建布尔变量

    int val = ui->editHex->text().toInt(&ok, 16);   //以十六进制数读入

    QString str = QString::number(val, 10); //数字显示十进制文件

    ui->editDec->setText(str);  //显示10进制数字符串

    str = QString::number(val, 2); //数字显示二进制文件

    ui->editBin->setText(str);  //显示十六进制数字符串
}
