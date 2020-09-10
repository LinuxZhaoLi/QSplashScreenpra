#ifndef _SPLASHSCREEN_H_
#define _SPLASHSCREEN_H_

#include <QSplashScreen>
#include <QMovie>

class QPixmap;
class QPainter;
// 自启动界面
class MySplashScreen : public QSplashScreen
{

public:
    MySplashScreen(const QPixmap & pixmap);  // 构造函数
    MySplashScreen(const QString gifname); // 构造函数
    void setGif(QString filename);   // 设置图片

protected:
     void drawContents(QPainter *painter);  // 画图

private slots:
    void slot_update();  // 槽函数  ，

private:
    QMovie *m_move;  // 视频
    int m_rotate;

};

#endif // _SPLASHSCREEN_H_
