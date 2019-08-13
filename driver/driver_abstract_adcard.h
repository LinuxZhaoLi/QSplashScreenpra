#ifndef DRIVER_ABSTRACT_ADCARD_H
#define DRIVER_ABSTRACT_ADCARD_H

#include <QVector>

namespace driver {

template <typename T>
class AbstractADCard
{
public:
  explicit AbstractADCard(){}

  virtual ~AbstractADCard(){}
/***********************************************************************************
 * ����: virtual bool init(int an, int dn, int sample=200000)=0
 * ����: ��ʼ��ad��
 * ����: int an: ģ��ͨ����
 * ����: int dn: ����ͨ����
 * ����: int sample: ������
 * ����: �ɹ�����true������false
 * *********************************************************************************/
  virtual bool init(int an, int dn, int sample=10000)=0;//���豸

  //�ͷ��豸
  virtual bool release(){//�ͷ��豸
    return true;
  }

  virtual bool hasData()=0;//����Ƿ�������


  virtual void next()=0;//�ɼ���һ����


  //�������з�ʽΪ����ģ��ͨ����Ȼ��������ͨ��
  virtual const QVector<T> &getData()=0;


};
}
#endif // ADCARD_H
