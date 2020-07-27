#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::createChart()
{ //创建图表
    QChartView * chartView = new QChartView(this);  //创建 ChartView

    QChart * chart = new QChart();  //创建 Chart

    chart->setTitle("简单函数曲线");

    chartView->setChart(chart); //Chart添加到ChartView

    this->setCentralWidget(chartView);

//创建曲线序列
    QLineSeries * series0 = new QLineSeries();

    QLineSeries * series1 = new QLineSeries();

    series0->setName("Sin曲线");

    series1->setName("Cos曲线");

    chart->addSeries(series0);  //序列添加到图表

    chart->addSeries(series1);

//    QPen    pen;
//    pen.setStyle(Qt::DotLine);//Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine
//    pen.setWidth(2);
//    pen.setColor(Qt::red);
//    series0->setPen(pen);

//    pen.setStyle(Qt::SolidLine);//Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine
//    pen.setColor(Qt::blue);
//    series1->setPen(pen);

//序列添加数值
    qreal t = 0, y1, y2, intv = 0.1;


    for (int i = 0; i < 100; i++)
    {
        y1 = qSin(t);

        series0->append(t,y1);

        y2 = qCos(t);

        series1->append(t,y2);

        t+= intv;
    }


//    chart->createDefaultAxes();
//    chart->axisX()->setTitleText("time(secs)");
//    chart->axisY()->setTitleText("value");

     //创建坐标轴

    QValueAxis * axisX = new QValueAxis; //X 轴

    axisX->setRange(0,10);  //设置坐标轴范围

    axisX->setTitleText("time(secs)");  //标题


    //Y 轴

    QValueAxis * axisY = new QValueAxis; //X 轴

    axisY->setRange(-2, 2);  //设置坐标轴范围

    axisY->setTitleText("value");   //标题
//    axisY->setTickCount(5);
//    axisY->setMinorTickCount(4);
//    axisY->setLabelFormat("%.2f"); //标签格式
//    axisY->setGridLineVisible(false);

 //为序列设置坐标轴
    chart->setAxisX(axisX, series0);

    chart->setAxisY(axisY, series0);
 //为序列设置坐标轴
    chart->setAxisX(axisX, series1);

    chart->setAxisY(axisY, series1);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createChart();
}

MainWindow::~MainWindow()
{
    delete ui;
}
