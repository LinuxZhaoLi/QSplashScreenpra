#ifndef DRIVER_T9342_H
#define DRIVER_T9342_H

#include <QVector>
#include <QProcess>
#include <QtNetwork>
#include <QDebug>
#include <QTimer>
#include "driver_adcard16.h"
#include "driver_t9342thread.h"

namespace driver {

class T9342 :public QObject, public ADCard16
{
  Q_OBJECT
public:
  static T9342 *instance(){
    static T9342 *p=0;
    if(p == 0){
      p = new T9342();
    }
    return p;
  }

  virtual ~T9342(){
    release();
    if(m_process[0]){
      delete m_process[0];
    }
    if(m_process[1]){
      delete m_process[1];
    }
  }

  virtual bool init(int an, int dn, int sample=200000);//���豸

  //�ͷ��豸
  virtual bool release();

  virtual bool hasData();//����Ƿ�������

  virtual void next(){//�ɼ���һ����
  }

  virtual const QVector<quint16> &getData();//��ȡ����

private slots:
//  void readSlot();
//  void timeoutSlot();

protected:
  T9342();

private:
  QVector<quint16> m_data;
  QProcess *m_process[2];
  T9342thread m_thread;
  int m_sample;//������
  int m_an;//ģ��ͨ����


private:

  void log(const QString &str){
    qDebug()<<"T9342: "<<str;
  }

//  /*******************************************************************************************
//   * ����: qint64 send(const QByteArray &byteArray)
//   * ����: �������ݻ�����ɼ���
//   * ����: const QByteArray &byteArray: Ҫ���͵����ݻ�����
//   * ����: ���͵��ֽ���
//   * *****************************************************************************************/
//  qint64 send(const QByteArray &byteArray);

//  /*******************************************************************************************
//   * ����:  void start(quint32 sample_number, quint16 begin_channel, quint16 channel_number,
//             quint32 sample_rate, quint32 freq_filter,quint16 ampgain)
//   * ����: ��ʼ�ɼ�����
//   * ����: quint32 sample_number: ÿ��ͨ���Ĳ�������
//   * ����: quint16 begin_channel: ��ʼͨ��
//   * ����: quint16 channel_number: Ҫ������ͨ����
//   * ����: quint32 sample_rate: ������
//   * ����: quint32 freq_filter:????
//   * ����: quint16 ampgain:????
//   * *****************************************************************************************/
//  void start(quint32 sample_number, quint16 begin_channel, quint16 channel_number,
//             quint32 sample_rate, quint32 freq_filter,quint16 ampgain);

//  void stop();//ֹͣ�ɼ�����

//  void keep();//��������
};

}
#endif // DRIVER_T9342_H
