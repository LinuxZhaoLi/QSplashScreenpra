#include "driver_t9342.h"
#include <QtNetwork/QtNetwork>
#include <QDebug>

#ifndef SERVER_IP
#define SERVER_IP         "192.168.0.200"
#endif
#ifndef SERVER_PORT
#define SERVER_PORT        9411
#endif

using namespace driver;

T9342::T9342()
{
  m_process[0]=0;
  m_process[1]=0;
}


const QVector<quint16> &T9342::getData(){
  const QVector<uint16_t> &data=m_thread.getData();
  for(int i=0,index=0,base; i<m_sample; ++i){
    base=i*(m_an+1);
    for(int j=0; j<m_an; ++j){
      m_data[index++]=data[1+j+base];
    }
    m_data[index++]=data[base];
  }
  return m_data;
}


bool T9342::init(int an, int dn, int sample){//���豸
  if(an != 16 || (dn != 8 && dn != 16)){
    log(QString().sprintf("channel is error.\nan:%d dn:%d",an,dn));
    return false;
  }
  QString ip;
  QList<QHostAddress>listAddress = QNetworkInterface::allAddresses();//����һ����������װ��IP��ַ
  for(int j = 0; j < listAddress.size(); j++){//����ѭ��,ѭ������ΪlistAddress�ĳ���
    if(!listAddress.at(j).isNull() && listAddress.at(j).protocol() ==
       QAbstractSocket::IPv4Protocol && listAddress.at(j) != QHostAddress::LocalHost){
      ip = listAddress.at(j).toString();//��IP��ַת��ΪString����,����װ���Ǳ�����IP��ַ
      break;
    }
  }
  if(ip != "192.168.0.106"){//ip��ַû���޸ģ�����ip��ַ��dns
    QString program = "cmd";
    QStringList arguments;
    arguments << "/c"<<"netsh interface ip set address name=\"��������\" source=static addr=192.168.0.106 mask=255.255.255.0 gateway=192.168.0.1";
    //qDebug()<<arguments;
    m_process[0]=new QProcess();
    m_process[0]->start(program, arguments);


    arguments.clear();
    arguments << "/c"<< "netsh interface ip set dns name=\"��������\" source=static addr=192.168.0.10";
    //qDebug()<<arguments;
    m_process[1]=new QProcess();
    m_process[1]->start(program, arguments);
  }
  m_sample=sample;
  m_an=an;
  m_data.resize(sample*(an+1));

  return m_thread.init(an,dn,sample,5*sample);

//  connect(&m_udp,SIGNAL(readyRead()),this,SLOT(readSlot()));
//  for(int i=8899; i<60000; ++i){
//    if(m_udp.bind(i)){
//      break;
//    }
//  }
//  stop();
//  start(sample,0,an,sample,0,1);
//  connect(&m_timer,SIGNAL(timeout()),this,SLOT(timeoutSlot()));
//  m_timer.start(1000);
  return true;
}

//�ͷ��豸
bool T9342::release(){
  m_thread.release();;
  //stop();
  return true;
}

bool T9342::hasData(){
  int sample=m_thread.getSampleSize();
  //log(QString().sprintf("sample=%d",sample));
  return m_sample<= sample;
}


//qint64 T9342::send(const QByteArray &byteArray){
//  QHostAddress addr;
//  addr.setAddress(SERVER_IP);
//  return m_udp.writeDatagram(byteArray, addr,SERVER_PORT);
//}


//void T9342::readSlot(){
//  QByteArray byte;
//  if(m_udp.hasPendingDatagrams()){
//      byte.resize(m_udp.pendingDatagramSize());
//     //�������ݱ��������ŵ�datagram��
//     if(m_udp.readDatagram( byte.data(), byte.size()) <0 ){//û�ж�������
//       return;
//     }
//     //log(QString().sprintf("%.2X",byte.at(0)));
////     quint16 num;
////     num=byte.at(3);
////     num<<=8;
////     num += byte.at(2)&0xff;
////     log(QString().sprintf("num:%d",num));
//     static int size=0;
//     size += (byte.size()-6)/16/2;
//     if(size>=50000){
//       log(QString().sprintf("size:%d",size));
//       size=0;
//     }
//     //log(QString().sprintf("read size:%d",byte.size()));
//   }
//}


//void T9342::start(quint32 sample_number, quint16 begin_channel, quint16 channel_number,
//           quint32 sample_rate, quint32 freq_filter,quint16 ampgain){
//  QByteArray byte;
//  quint16 cmd=1;//������
//  quint16 cmd_len=18;//�����
//  byte[0]=0xaa;//���ʼ��ʶ
//  byte[1]=cmd>>8;
//  byte[2]=cmd&0xff;
//  byte[3]=cmd_len>>8;
//  byte[4]=cmd_len&0xff;

//  byte[5]=sample_number>>24;
//  byte[6]=sample_number>>16;
//  byte[7]=sample_number>>8;
//  byte[8]=sample_number&0xff;

//  byte[9]=begin_channel>>8;
//  byte[10]=begin_channel&0xff;

//  byte[11]=channel_number>>8;
//  byte[12]=channel_number&0xff;

//  byte[13]=sample_rate>>24;
//  byte[14]=sample_rate>>16;
//  byte[15]=sample_rate>>8;
//  byte[16]=sample_rate&0xff;

//  byte[17]=freq_filter>>24;
//  byte[18]=freq_filter>>16;
//  byte[19]=freq_filter>>8;
//  byte[20]=freq_filter&0xff;

//  byte[21]=ampgain>>8;
//  byte[22]=ampgain&0xff;

//  quint8 sum,value;
//  sum=0;
//  for(int i=0; i<18; ++i){
//    value=byte.at(i+5);
//    sum += value;
//  }
//  byte[23]=sum;
//  send(byte);
//}


//void T9342::stop(){
//  QByteArray byte;
//  quint16 cmd=0xaa;//������
//  quint16 cmd_len=0;//�����
//  byte[0]=0xaa;//���ʼ��ʶ
//  byte[1]=cmd>>8;
//  byte[2]=cmd&0xff;
//  byte[3]=cmd_len>>8;
//  byte[4]=cmd_len&0xff;
//  byte[5]=0;//У���
//  send(byte);
//}

//void T9342::keep(){
//  QByteArray byte;
//  quint16 cmd=0;//������
//  quint16 cmd_len=0;//�����
//  byte[0]=0xaa;//���ʼ��ʶ
//  byte[1]=cmd>>8;
//  byte[2]=cmd&0xff;
//  byte[3]=cmd_len>>8;
//  byte[4]=cmd_len&0xff;
//  byte[5]=0;//У���
//  send(byte);
//  //log("keep");
//}


//void T9342::timeoutSlot(){
//  keep();
//}
