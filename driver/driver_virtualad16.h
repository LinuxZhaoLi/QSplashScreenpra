#ifndef DRIVER_VIRTUALAD16_H
#define DRIVER_VIRTUALAD16_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QObject>
#include "driver_adcard16.h"
namespace driver {
class VirtualAD16 : public QObject,public ADCard16
{
  Q_OBJECT
public:
  VirtualAD16(QObject *parent = 0);

  /***********************************************************************************
   * ����: virtual bool init(int an, int dn, int sample=200000)=0
   * ����: ��ʼ��ad��
   * ����: int an: ģ��ͨ����
   * ����: int dn: ����ͨ����
   * ����: int sample: ������
   * ����: �ɹ�����true������false
   * *********************************************************************************/
  virtual bool init(int an, int dn, int sample=200000);//���豸

  virtual bool hasData(){//����Ƿ�������
    return m_flag;
  }

  virtual void next(){//�ɼ���һ����
    m_flag=false;
  }

  virtual const QVector<quint16> &getData(){
    return m_data;
  }

  void toggle();//��ת����λ

private slots:

  void timerSlot(){
    if(m_flag) {
      return;
    }
    m_flag=true;
  }

private:

  bool m_flag;//�Ƿ������ݵı�־
  QTimer m_timer;
  QVector<quint16> m_data;
  int m_an;//ģ��ͨ����
  int m_count;//�ܵ�����
  int m_sample;//��������

  void log(const QString &str){
    qDebug()<<"VirtualAD16: "<<str;
  }
};
}
#endif // VIRTUALAD16_H
