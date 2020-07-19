#include "widget.h"
#include "ui_widget.h"

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

void Widget::on_pushButton_clicked()
{//append()函数
    QString str1, str2; //创建QString临时变量

    str1 = ui->comboBox1->currentText();    //读取comboBox1组件上的字符串

    str2 = ui->comboBox2->currentText();    //读取comboBox2组件上的字符串

    str1 = str1.append(str2);

    ui->edtResult->setText(str1);   //显示
}

void Widget::on_pushButton_2_clicked()
{//prepend()函数
    QString str1, str2; //创建QString临时变量

    str1 = ui->comboBox1->currentText();    //读取comboBox1组件上的字符串

    str2 = ui->comboBox2->currentText();    //读取comboBox2组件上的字符串

    str1 = str1.prepend(str2);

    ui->edtResult->setText(str1);   //显示
}

void Widget::on_pushButton_3_clicked()
{//contains()函数
    QString str1, str2; //创建QString类对象

    str1 = ui->comboBox1->currentText();    //读取comboBox1组件上的字符串

    str2 = ui->comboBox2->currentText();    //读取comboBox2组件上的字符串

    bool chk;

    chk = str1.contains(str2);  //将判读字符串的真假值返回到chk

    ui->checkBox->setChecked(chk);  //根据chk的值判断是否在checkbox上打钩

    ui->checkBox->setText("contains()");  //在checkbox组件上显示contains字符串

    ui->checkBox->sizeHint();   //设置默认大小
}

void Widget::on_pushButton_4_clicked()
{//count()函数
    QString str1 = ui->comboBox1->currentText();

    int val = str1.count();

    ui->spinBox->setValue(val); //将val的值更新到spinbox组件上

    ui->LabSpin->setText("count()");    //在LabSpin足尖上显示count()字符串
}

void Widget::on_pushButton_5_clicked()
{//size()函数
    QString str1 = ui->comboBox1->currentText();

    int val = str1.size();

    ui->spinBox->setValue(val); //将val的值更新到spinbox组件上

    ui->LabSpin->setText("size()");    //在LabSpin足尖上显示size()字符串

}

void Widget::on_pushButton_6_clicked()
{//endsWith()函数
    QString str1, str2;

    str1 = ui->comboBox1->currentText();    //读取comboBox1组件上的字符串

    str2 = ui->comboBox2->currentText();    //读取comboBox2组件上的字符串

    bool chk;

    chk = str1.endsWith(str2);

    ui->checkBox->setChecked(chk);

    ui->checkBox->setText("endsWith()");      //在checkbox组件上显示endsWith()字符串

    ui->checkBox->sizeHint();
}

void Widget::on_pushButton_7_clicked()
{//indexOf()函数
    QString str1, str2; //创建QString类对象

    str1 = ui->comboBox1->currentText();    //读取comboBox1组件上的字符串

    str2 = ui->comboBox2->currentText();    //读取comboBox2组件上的字符串

    int val = str1.indexOf(str2);

    ui->spinBox->setValue(val); //将val的值更新到spinbox组件上

    ui->LabSpin->setText("indexOf()");    //在LabSpin足尖上显示indexOf()字符串
}

void Widget::on_pushButton_8_clicked()
{//isEmpty()函数
    QString str1 = ui->comboBox1->currentText();

    bool chk;

    chk = str1.isEmpty();

    ui->checkBox->setChecked(chk);

    ui->checkBox->setText("isEmpty()");

    ui->checkBox->sizeHint();
}

void Widget::on_pushButton_9_clicked()
{//lastIndexOf()函数
    QString str1, str2; //创建QString类对象

    str1 = ui->comboBox1->currentText();    //读取comboBox1组件上的字符串

    str2 = ui->comboBox2->currentText();    //读取comboBox2组件上的字符串

    int val = str1.lastIndexOf(str2);

    ui->spinBox->setValue(val); //将val的值更新到spinbox组件上

    ui->LabSpin->setText("lastIndexOf()");    //在LabSpin足尖上显示lastIndexOf()字符串
}

void Widget::on_pushButton_10_clicked()
{//startsWith()函数
    QString str1, str2;

    str1 = ui->comboBox1->currentText();    //读取comboBox1组件上的字符串

    str2 = ui->comboBox2->currentText();    //读取comboBox2组件上的字符串

    bool chk;

    chk = str1.startsWith(str2);

    ui->checkBox->setChecked(chk);

    ui->checkBox->setText("startsWith()");      //在checkbox组件上显示startsWith()字符串

    ui->checkBox->sizeHint();
}

void Widget::on_pushButton_11_clicked()
{//toUpper()函数
    QString str1, str2;

    str1 = ui->comboBox1->currentText();

    str2 = str1.toUpper();

    ui->edtResult->setText(str2);
}

void Widget::on_pushButton_12_clicked()
{//toLower()函数
    QString str1, str2;

    str1 = ui->comboBox1->currentText();

    str2 = str1.toLower();

    ui->edtResult->setText(str2);

}

void Widget::on_pushButton_13_clicked()
{//trimmed()函数
    QString str1, str2;

    str1 = ui->comboBox1->currentText();

    str2 = str1.trimmed();

    ui->edtResult->setText(str2);
}

void Widget::on_pushButton_14_clicked()
{//section()函数
    QString str1, str2, str3;

    int i = ui->spinBox->value();

    str1 = ui->comboBox1->currentText();

    str2 = ui->comboBox2->currentText();

    if (QString::compare(str2, "\\",Qt::CaseSensitive) == 0)
    {
        str3 = str1.section("\\", i, i+1);
    }
    else
    {
        str3 = str1.section(str2, i, i+1);
    }

    ui->edtResult->setText(str3);
}

void Widget::on_pushButton_15_clicked()
{//left()函数
    QString str1, str2;

    int i = ui->spinBox->value();

    str1 = ui->comboBox1->currentText();

    str2 = str1.left(i);

    ui->edtResult->setText(str2);
}

void Widget::on_pushButton_16_clicked()
{//right()函数
    QString str1, str2;

    uint i = ui->spinBox->value();

    str1 = ui->comboBox1->currentText();

    str2 = str1.right(i);

    ui->edtResult->setText(str2);
}

void Widget::on_pushButton_17_clicked()
{//simplified()函数
    QString str1, str2;

    str1 = ui->comboBox1->currentText();

    str2 = str1.simplified();

    ui->edtResult->setText(str2);
}

void Widget::on_pushButton_18_clicked()
{//isNull()函数
    QString str1 = ui->comboBox1->currentText();

    bool chk = str1.isNull();

    ui->checkBox->setChecked(chk);

    ui->checkBox->setText("isNull()");

    ui->checkBox->sizeHint();
}
