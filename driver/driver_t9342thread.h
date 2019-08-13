#ifndef DRIVER_T9342THREAD_H
#define DRIVER_T9342THREAD_H

#include <QThread>
#include <QtNetwork>
#include "./libuv/uv.h"
#include <stdint.h>


namespace driver {


class T9342thread: public QThread
{
public:
  explicit T9342thread(QObject *parent = 0);

  /***********************************************************************************
   * ����: virtual bool init(int an, int dn, int sample=200000)=0
   * ����: ��ʼ��ad��
   * ����: int an: ģ��ͨ����
   * ����: int dn: ����ͨ����
   * ����: int sample: ������
   * ����: int size: ��󻺴��������
   * ����: �ɹ�����true������false
   * *********************************************************************************/
  bool init(int an, int dn, int sample, int size);//���豸
  void release();

  //��ȡ�������������ظ�����ʾ����
  int getSampleSize();

  //��ȡ1��ʱ�������
  const QVector<uint16_t> &getData();

  static void log(const QString &str){
    static int cnt=0;
    qDebug()<<"T9342thread "<<cnt++<<": "<<str;
  }



protected:
  void run();

private:
  QVector<uint16_t> m_data;

};

}

#endif // DRIVER_T9342THREAD_H
