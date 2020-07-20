#include "widget.h"
#include "ui_widget.h"

#include    <QString>
#include    <QPalette>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setLayout(ui->horizontalLayout);  //读取布局

    QObject::connect(ui->SliderBlue, SIGNAL(valueChanged(int)), this, SLOT(on_SliderRed_valueChanged(int)));

    QObject::connect(ui->SliderGreen, SIGNAL(valueChanged(int)), this, SLOT(on_SliderRed_valueChanged(int)));

    QObject::connect(ui->SliderAlpha, SIGNAL(valueChanged(int)), this, SLOT(on_SliderRed_valueChanged(int)));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_SliderV_valueChanged(int value)
{ //垂直滑动条控制卷滚条和进度条
    ui->ScrollBarV->setValue(value);    //设置卷滚条数值

    ui->progBarV->setValue(value);  //设置进度条数值
}

void Widget::on_ScrollBarV_sliderMoved(int position)
{ //垂直卷滚条控制进度条
    ui->progBarV->setValue(position);  //设置进度条数值
}

void Widget::on_SliderH_valueChanged(int value)
{ //水平滑动条控制卷滚条和进度条
    ui->progBarH->setValue(value);  //设置进度条数值

    ui->ScrollBarH->setValue(value);    //设置卷滚条数值
}

void Widget::on_ScrollBarH_sliderMoved(int position)
{ //水平卷滚条控制进度条
    ui->progBarH->setValue(position);  //设置进度条数值
}

void Widget::on_dial_valueChanged(int value)
{  //设置LCD的显示值等于Dial的值
    ui->LCDDisplay->display(value);
}

void Widget::on_radioBtnDec_clicked()
{ //设置LCD显示十进制数
    ui->LCDDisplay->setDigitCount(3);
    ui->LCDDisplay->setDecMode();
}

void Widget::on_radioBtnBin_clicked()
{ //设置LCD显示二进制数
    ui->LCDDisplay->setDigitCount(8);
    ui->LCDDisplay->setBinMode();
}

void Widget::on_radioBtnOct_clicked()
{ //设置LCD显示八进制数
    ui->LCDDisplay->setDigitCount(4);
    ui->LCDDisplay->setOctMode();
}

void Widget::on_radioBtnHex_clicked()
{ //设置LCD显示十六进制数
    ui->LCDDisplay->setDigitCount(3);
    ui->LCDDisplay->setHexMode();
}

void Widget::on_SliderRed_valueChanged(int value)
{  //拖动Red、Green、Blue 颜色滑动条时设置textEdit的底色
    Q_UNUSED(value);

    QColor color;   //创建QColor对象

    int r = ui->SliderRed->value(); //读取SliderRed的当前值

    int g = ui->SliderGreen->value();   //读取 SliderGreen 的当前值

    int b = ui->SliderBlue->value();    //读取 SliderBlue 的当前值

    int a = ui->SliderAlpha->value();   //读取 SliderAlpha 的当前值

    color.setRgb(r, g, b, a);   //使用QColor的setRgb()函数 获得颜色

    QPalette palette = ui->textEdit->palette(); //获取textEdit原有的 palette

    palette.setColor(QPalette::Base, color);    //设置palette的基色（即背景色）

    ui->textEdit->setPalette(palette);  //设置为textEdit的palette,改变textEdit的底色
}
