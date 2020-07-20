#include    "widget.h"
#include    "ui_widget.h"
#include    <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QObject::connect(ui->spinNum, SIGNAL(valueChanged(int)), this, SLOT(on_btnCal_clicked()));

    QObject::connect(ui->spinPrice, SIGNAL(valueChanged(double)), this, SLOT(on_btnCal_clicked()));

    QObject::connect(ui->spinBin, SIGNAL(valueChanged(int)), this, SLOT(on_btnBin_clicked()));

    QObject::connect(ui->spinDec, SIGNAL(valueChanged(int)), this, SLOT(on_btnDec_clicked()));

    QObject::connect(ui->spinHex, SIGNAL(valueChanged(int)), this, SLOT(on_btnHex_clicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnCal_clicked()
{ //计算按键
    int num = ui->spinNum->value(); //获取数量

    double price = ui->spinPrice->value();  //获取单价

    double total = price * num; //计算总价

    ui->spinTotal->setValue(total);
}


void Widget::on_btnDec_clicked()
{ //读取十进制，以其他进制显示
    int val = ui->spinDec->value(); //读取十进制

    ui->spinBin->setValue(val); //二进制显示

    ui->spinHex->setValue(val); //十六进制显示
}

void Widget::on_btnBin_clicked()
{ //读取二进制，以其他进制显示
    int val = ui->spinBin->value(); //读取二进制

    ui->spinDec->setValue(val); //十进制显示

    ui->spinHex->setValue(val); //十六进制显示
}

void Widget::on_btnHex_clicked()
{ //读取十六进制，以其他进制显示
    int val = ui->spinHex->value(); //读取十六进制

    ui->spinDec->setValue(val); //十进制显示

    ui->spinBin->setValue(val); //二进制显示
}

