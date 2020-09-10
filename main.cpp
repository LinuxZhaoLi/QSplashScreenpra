#include <QApplication>
#include <QApplication>
#include <QSplashScreen>
#include<QPainter>
#include<MySplashScreen.h>
#include <QDate>
#include <mainwindow.h>
#include <QDebug>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    QPixmap pix(":/timg.jpg");  // 图像对象
   // QSplashScreen  splash(pix);
    MySplashScreen splash(pix);   // 自定类
    splash.showMessage("Wait...");

//      Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
//      splash.showMessage(QObject::tr("Setting up the main window..."),topRight, Qt::white);
    splash.show();

    QDateTime n=QDateTime::currentDateTime();

    QDateTime now;

    do{

        now=QDateTime::currentDateTime();
        qDebug()<<now<<endl;
        qDebug()<<"n:---->"<<n<<endl;

    } while (n.secsTo(now)<=3);
  //  a.processEvents();


    MainWindow w;
    w.show();

    splash.finish(&w); // 使启动屏幕等待小部件mainWin显示后再对其本身调用close（）。

    return a.exec();
}
