#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitCustomPlot();
    m_ptimer= new QTimer(this);
    connect(m_ptimer, SIGNAL(timeout()), this, SLOT(sigHandleTimeout()));
    m_ptimer->start(1000);
    thread.start();

    m_begin=0;
    m_lastPointKey=0;


}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::InitCustomPlot()
{


       m_elapsedTimer.restart();

    //ui->graph_widget->axisRect()->setupFullAxesBox(true);
   /// 1.����ͼ������ɫ
    ui->graph_widget->setBackground(QColor(197,197,197));
    ui->graph_widget->yAxis->setRange(-70000,70000);

    // �±�ĸ�ʽ������ ���� ʱ��
    ui->graph_widget->xAxis->setTickLabelType(QCPAxis::ltNumber);
    // ����ʱ���±��ʽ
//    ui->customPlot->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->graph_widget->xAxis->setRange(0, 8);
    // �Ƿ������Զ��±�
    ui->graph_widget->xAxis->setAutoTickStep(false);
    // �ֶ������±꣬Ҫ�Ƚ�ֹ�Զ��±꣬�����ټ����ʾ�±�
    ui->graph_widget->xAxis->setTickStep(1);
    // ����steps֮��ļ����
    ui->graph_widget->xAxis->setAutoSubTicks(false);
    ui->graph_widget->xAxis->setSubTickCount(4); // 9+1
    ui->graph_widget->addGraph();
     // ����ͼ�㷴��ݣ��ر�
    ui->graph_widget->graph(0)->setPen(QPen(Qt::blue));

}

void MainWindow::GetRealtimeData(RT_CTL *rtCtl, INT16 chData[16][10000])
{

    int i, j;

    //�Ӳ�����������ȡ����
    int pntbegin = rtCtl->CurSmpPntPos;
    pntbegin = (pntbegin + (rtCtl->CycCnt - 6) * rtCtl->SmpCntPerCyc) % rtCtl->SmpPntCnt;
    if(pntbegin > rtCtl->SmpPntCnt - 10 * rtCtl->SmpCntPerCyc )
    {
        pntbegin -= 10 * rtCtl->SmpCntPerCyc;
    }
    unsigned short *pDataSrc = (unsigned short *)(rtCtl->SmpBufAddr + pntbegin * rtCtl->SmpDataLenPerPnt + sizeof(YHFtimeval));

  for(j=0; j<g_rtCtl->SmpCntPerCyc; j++)
    {
    for(i=0; i<g_rtCtl->AnChCnt; i++)
        {
             chData[i][j] = *(pDataSrc + i) - 32768 ;	//ctm
        }

        pDataSrc += (rtCtl->SmpDataLenPerPnt / 2);
    }


}

void MainWindow::sigHandleTimeout()
{

   GetRealtimeData(g_rtCtl,chData);
    double key = (double)(m_elapsedTimer.elapsed() + m_begin)/1000 ;
    // 10ms����һ����
    if (key-m_lastPointKey > 0.001)
    {
     for(int i=0;i<200;i++){
      //qDebug()<<i<<chData[7][i];
      ui->graph_widget->graph(0)->addData(key,chData[7][i] );
        }
    }
    qDebug()<<"key:"<<key;
    // ����ʾ��X�ᳬ��8��ʱ��X���귶Χ��ʼ�ƶ�
    if(key > 8)
    {
        ui->graph_widget->xAxis->setRange(key+0.001, 8, Qt::AlignRight);
    }
    ui->graph_widget->replot();


}
