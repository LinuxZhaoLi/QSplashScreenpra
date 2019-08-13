#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "BasicAlgorithm.h"
#endif

//#include <Experts.h>
#include <BasicAlgorithm.h>

#include "stdio.h"
#include "math.h"
#include "time.h"
//#include <QDebug>
#include "yhftypes.h"





BOOL BasicAlgorithm::SHGetSequence( FLOAT32 * pData[3], INT32 perCycPoints, FLOAT32 * pSequence )
{
	
	FLOAT32 *temp;
	INT32 i, k;
	FLOAT64 sum, imag[3], real[3], sequ[6];

	//��ڲ������
	if (pData==NULL || perCycPoints<8|| pSequence==NULL)
	{
		return FALSE;
	}

	//����ʸ��
	for (i=0; i<3; i++)
	{
		temp = pData[i];
		sum = 0;
		for (k=0; k<perCycPoints; k++)
		{
			sum += *(temp+k) * cos(2*PI*k/perCycPoints);
		}
		imag[i] = 2 * sum / perCycPoints;	//�鲿

		sum = 0;
		for (k=0; k<perCycPoints; k++)
		{
			sum += *(temp+k) * sin(2*PI*k/perCycPoints);
		}
		real[i] = 2 * sum / perCycPoints;
	}

	//���������
	sequ[0] = (real[0] - (real[1]+real[2])*0.5 - (imag[1]-imag[2])*SQRT_3/2) / 3;	//����ʵ��
	sequ[1] = (imag[0] - (imag[1]+imag[2])*0.5 + (real[1]-real[2])*SQRT_3/2) / 3;
	sequ[2] = (real[0] - (real[2]+real[1])*0.5 - (imag[2]-imag[1])*SQRT_3/2) / 3;	//����ʵ��
	sequ[3] = (imag[0] - (imag[2]+imag[1])*0.5 + (real[2]-real[1])*SQRT_3/2) / 3;
	sequ[4] = (real[0] + real[1] + real[2]) / 3;									//����ʵ��
	sequ[5] = (imag[0] + imag[1] + imag[2]) / 3;

	for (i=0; i<3; i++)
	{
		//Rms��ֵ
		*(pSequence+2*i) = (FLOAT32)(sqrt(sequ[2*i]*sequ[2*i] + sequ[2*i+1]*sequ[2*i+1]) / SQRT_2);

		//���
		*(pSequence+2*i+1) = (FLOAT32)(((sequ[2*i+1]<0)? 2*PI + atan2(sequ[2*i+1], sequ[2*i])
								: atan2(sequ[2*i+1], sequ[2*i])) / PI * 180);
	}

	//���㲻ƽ���
	*(pSequence+6) = (FLOAT32)(*pSequence<0.00001 ? 0 : *(pSequence+2) / (*pSequence));

	return TRUE;	
}

BOOL BasicAlgorithm::SHGetSequence( INT16 * pData[3], FLOAT32 * multiplier, INT32 perCycPoints, FLOAT32 * pSequence )
{
	INT16 *temp;
	INT32 i, k;
	FLOAT64 sum, imag[3], real[3], sequ[6];

	//��ڲ������
	if (pData==NULL || perCycPoints<8|| pSequence==NULL)
	{
		return FALSE;
	}

	//����ʸ��
	for (i=0; i<3; i++)
	{
		temp = pData[i];
		sum = 0;
		for (k=0; k<perCycPoints; k++)
		{
			sum += *(temp+k) * cos(2*PI*k/perCycPoints);
		}
		imag[i] = 2 * sum / perCycPoints * multiplier[i];	//�鲿

		sum = 0;
		for (k=0; k<perCycPoints; k++)
		{
			sum += *(temp+k) * sin(2*PI*k/perCycPoints);
		}
		real[i] = 2 * sum / perCycPoints * multiplier[i];
	}

	//���������
	sequ[0] = (real[0] - (real[1]+real[2])*0.5 - (imag[1]-imag[2])*SQRT_3/2) / 3;	//����ʵ��
	sequ[1] = (imag[0] - (imag[1]+imag[2])*0.5 + (real[1]-real[2])*SQRT_3/2) / 3;
	sequ[2] = (real[0] - (real[2]+real[1])*0.5 - (imag[2]-imag[1])*SQRT_3/2) / 3;	//����ʵ��
	sequ[3] = (imag[0] - (imag[2]+imag[1])*0.5 + (real[2]-real[1])*SQRT_3/2) / 3;
	sequ[4] = (real[0] + real[1] + real[2]) / 3;									//����ʵ��
	sequ[5] = (imag[0] + imag[1] + imag[2]) / 3;

	for (i=0; i<3; i++)
	{
		//Rms��ֵ
		*(pSequence+2*i) = (FLOAT32)(sqrt(sequ[2*i]*sequ[2*i] + sequ[2*i+1]*sequ[2*i+1]) / SQRT_2);

		//���
		*(pSequence+2*i+1) = (FLOAT32)(((sequ[2*i+1]<0)? 2*PI + atan2(sequ[2*i+1], sequ[2*i])
								: atan2(sequ[2*i+1], sequ[2*i])) / PI * 180);
	}

	//���㲻ƽ���
	*(pSequence+6) = (FLOAT32)(*pSequence<0.00001 ? 0 : *(pSequence+2) / (*pSequence));

	return TRUE;	
}

BOOL BasicAlgorithm::SHGetHarmonic( FLOAT32 * pData, INT32 maxNum, INT32 perCycPoints, FLOAT32 * pHarmonic )
{
	
	FLOAT64 imag, real, sum = 0;
	INT32 h, k;
	INT32 maxNumber;	//����ܼ������

	//��ڲ������
	if (pData==NULL || maxNum<0 || pHarmonic==NULL || perCycPoints<8)
	{
		return FALSE;
	}

	//����ֱ��
	for (k=0; k<perCycPoints; k++)
	{
		sum += *(pData + k);
	}
	*(pHarmonic) = (FLOAT32)(sum / perCycPoints);

	//�ܼ����������
       // maxNumber = minmy(maxNum, perCycPoints / 2 - 1);

	//����1->maxNumber��г��
	for (h=1; h<=maxNumber; h++)
	{
		//��h��г������
		sum = 0;
		for (k=0; k<perCycPoints; k++)
		{
			sum += *(pData + k) * cos(h * 2 * PI * k / perCycPoints);
		}
		imag = sum / perCycPoints;	//�鲿

		sum = 0;
		for (k=0; k<perCycPoints; k++)
		{
			sum += *(pData + k) * sin(h * 2 * PI * k / perCycPoints);
		}
		real = sum / perCycPoints;

		//г����Чֵ
		*(pHarmonic+2*h) = (FLOAT32)(sqrt(imag * imag + real * real) * SQRT_2);
		
		//���
		*(pHarmonic+2*h+1) = (FLOAT32)(180*((imag<0) ? 2*PI + atan2(imag, real) : atan2(imag, real)) / PI);
	}

	//����THD
	*(pHarmonic+1) = 0;
	if (maxNumber > 1)
	{
		sum = 0;
		for (h=2; h<=maxNumber; h++)
		{
			sum += *(pHarmonic + 2 * h) * *(pHarmonic + 2 * h);
		}
		*(pHarmonic+1) = (FLOAT32)((*(pHarmonic+2) > 0.00001)? (sqrt(sum) / *(pHarmonic+2)) : 0);
	}

	//����Чг��������0
	for (h=maxNumber+1; h<=maxNum; h++)
	{
		*(pHarmonic+2*h) = 0;
		*(pHarmonic+2*h+1) = 0;
	}

	return TRUE;
	
}

BOOL BasicAlgorithm::SHGetHarmonic( /*INT16 **/ unsigned short *pData, FLOAT32 multiplier, INT32 perCycPoints, INT32 beginNum, INT32 maxNum, FLOAT32 * pHarmonic )//8-30
{
    FLOAT64 imag, real, sum[2] = {0};
    INT32 h, k;
    INT32 maxNumber;	//����ܼ������

    //��ڲ������
    if (pData==NULL || maxNum<0 || pHarmonic==NULL || perCycPoints<8 || beginNum<1)
    {
        return FALSE;
    }

    //�ܼ����������
        //maxNumber = minmy(maxNum, perCycPoints / 2 - 1);

    //����beginNum->maxNumber��г��
    for (h=beginNum; h<=maxNumber; h++)
    {
        //��h��г������
        sum[0] = 0;
        sum[1] = 0;
        for (k=0; k<perCycPoints; k++)
        {
            sum[0] += *(pData + k) * cos(h * 2 * PI * k / perCycPoints);
            sum[1] += *(pData + k) * sin(h * 2 * PI * k / perCycPoints);
        }
        imag = sum[0] / perCycPoints;	//�鲿
        real = sum[1] / perCycPoints;

        //г����Чֵ
        *(pHarmonic+2*(h-beginNum)) = (FLOAT32)(sqrt(imag * imag + real * real) * SQRT_2) * multiplier;
		
        //���
        *(pHarmonic+2*(h-beginNum)+1) = (FLOAT32)(180*((imag<0) ? 2*PI + atan2(imag, real) : atan2(imag, real)) / PI);
    }

    //����Чг��������0
    for (h=maxNumber+1; h<=maxNum; h++)
    {
        *(pHarmonic+2*(h-beginNum)) = 0;
        *(pHarmonic+2*(h-beginNum)+1) = 0;
    }

    return TRUE;
	
}

BOOL BasicAlgorithm::SHGetHarmonic( FLOAT32 * pData, INT32 perCycPoints, INT32 beginNum, INT32 maxNum, FLOAT32 * pHarmonic )
{	
	FLOAT64 imag, real, sum[2] = {0};
	INT32 h, k;
	INT32 maxNumber;	//����ܼ������

	//��ڲ������
	if (pData==NULL || maxNum<0 || pHarmonic==NULL || perCycPoints<8 || beginNum<1)
	{
		return FALSE;
	}

	//�ܼ����������
        //maxNumber = minmy(maxNum, perCycPoints / 2 - 1);

	//����beginNum->maxNumber��г��
	for (h=beginNum; h<=maxNumber; h++)
	{
		//��h��г������
		sum[0] = 0;
		sum[1] = 0;
		for (k=0; k<perCycPoints; k++)
		{
			sum[0] += *(pData + k) * cos(h * 2 * PI * k / perCycPoints);
			sum[1] += *(pData + k) * sin(h * 2 * PI * k / perCycPoints);
		}
		imag = sum[0] / perCycPoints;	//�鲿
		real = sum[1] / perCycPoints;

		//г����Чֵ
		*(pHarmonic+2*(h-beginNum)) = (FLOAT32)(sqrt(imag * imag + real * real) * SQRT_2);
		
		//���
		*(pHarmonic+2*(h-beginNum)+1) = (FLOAT32)(180*((imag<0) ? 2*PI + atan2(imag, real) : atan2(imag, real)) / PI);
	}

	//����Чг��������0
	for (h=maxNumber+1; h<=maxNum; h++)
	{
		*(pHarmonic+2*(h-beginNum)) = 0;
		*(pHarmonic+2*(h-beginNum)+1) = 0;
	}

	return TRUE;
}

BOOL BasicAlgorithm::SHGetPower( FLOAT32 * pDataU, FLOAT32 * pDataI, FLOAT32 Channel_Skew, INT32 perCycPoints, FLOAT32 * pPower )
{
    FLOAT32 *pDATA;
    FLOAT64 EffectiveValue[2], angle[2], sum, imag[2], real[2]
        , RealPower, ReactivePower, ApparentPower, PowerFactor, PowerAngle;
    INT32 i, k;

    //��ڲ������
    if (pDataU==NULL || pDataI==NULL || perCycPoints<8 || pPower==NULL)
    {
        return FALSE;
    }

    //�й�����
    RealPower = 0;
    for (i=0 ; i<perCycPoints ; i++)
    {
        RealPower += *(pDataU+i) * *((pDataI+i));
    }
    RealPower = RealPower / perCycPoints;

    //ʸ������
    for (i=0; i<2; i++)
    {
        pDATA = i? pDataI: pDataU;

        sum = 0;
        for (k=0; k<perCycPoints; k++)
        {
            sum += *(pDATA+k) * cos(2*PI*k/perCycPoints);
        }
        imag[i] = 2 * sum / perCycPoints;//�鲿

        sum = 0;
        for (k=0; k<perCycPoints; k++)
        {
            sum += *(pDATA+k) * sin(2*PI*k/perCycPoints);
        }
        real[i] = 2 * sum / perCycPoints;//ʵ��

        angle[i] = atan2(imag[i], real[i]);
		
        //��Чֵ
        sum = 0;
        for (INT32 k=0; k<perCycPoints; k++)
        {
            sum += *(pDATA+k) * *(pDATA+k);
        }
        sum = sqrt(sum / perCycPoints);
        EffectiveValue[i] = sum;
    }

    PowerAngle = angle[0] - angle[1]  - Channel_Skew / 10000 * PI;			//����
    RealPower = EffectiveValue[0] * EffectiveValue[1] * cos(PowerAngle);	//�й�
    ReactivePower = EffectiveValue[0] * EffectiveValue[1] * sin(PowerAngle);	//�޹�
    ApparentPower = EffectiveValue[0] * EffectiveValue[1];						//���ڹ���
    PowerFactor = (ApparentPower > 0.00001) ? RealPower / ApparentPower : 0;	//��������

    //����
    *(pPower+0) = (FLOAT32)RealPower;
    *(pPower+1) = (FLOAT32)ReactivePower;
    *(pPower+2) = (FLOAT32)ApparentPower;
    *(pPower+3) = (FLOAT32)PowerFactor;
    *(pPower+4) = (FLOAT32)(PowerAngle * 180 / PI);

    //�������Ƿ�ΧΪ(-180, 180)
    if (*(pPower+4) > 180)
    {
        *(pPower+4) -= 360;
    }
    else if ( *(pPower+4) < -180)
    {
        *(pPower+4) += 360;
    }

    return TRUE;
}

BOOL BasicAlgorithm::SHGetPower( INT16 * pDataU, INT16 * pDataI, FLOAT32 Channel_Skew, INT32 perCycPoints, FLOAT32 * pPower )
{
	INT16 *pDATA;
	FLOAT64 EffectiveValue[2], angle[2], sum[3], imag[2], real[2]
		, RealPower, ReactivePower, ApparentPower, PowerFactor, PowerAngle;
	INT32 i, k;

	//��ڲ������
	if (pDataU==NULL || pDataI==NULL || perCycPoints<8 || pPower==NULL)
	{
		return FALSE;
	}

	//�й�����
	RealPower = 0;
	for (i=0 ; i<perCycPoints ; i++)
	{
		RealPower += *(pDataU+i) * *((pDataI+i));
	}
	RealPower = RealPower / perCycPoints;

	//ʸ������
	for (i=0; i<2; i++)
	{
		pDATA = i? pDataI: pDataU;

		sum[0] = 0;
		sum[1] = 0;
		sum[2] = 0;
		for (k=0; k<perCycPoints; k++)
		{
			sum[0] += *(pDATA+k) * cos(2*PI*k/perCycPoints);
			sum[1] += *(pDATA+k) * sin(2*PI*k/perCycPoints);
			sum[2] += *(pDATA+k) * *(pDATA+k);
		}
		imag[i] = 2 * sum[0] / perCycPoints;	//�鲿
		real[i] = 2 * sum[1] / perCycPoints;	//ʵ��
		angle[i] = atan2(imag[i], real[i]);

		EffectiveValue[i] = sqrt(sum[2] / perCycPoints);	//��Чֵ
	}

	PowerAngle = angle[0] - angle[1]  - Channel_Skew / 10000 * PI;			//����
	RealPower = EffectiveValue[0] * EffectiveValue[1] * cos(PowerAngle);	//�й�
	ReactivePower = EffectiveValue[0] * EffectiveValue[1] * sin(PowerAngle);	//�޹�
	ApparentPower = EffectiveValue[0] * EffectiveValue[1];						//���ڹ���
	PowerFactor = (ApparentPower > 0.00001) ? RealPower / ApparentPower : 0;	//��������

	//����
	*(pPower+0) = (FLOAT32)RealPower;
	*(pPower+1) = (FLOAT32)ReactivePower;
	*(pPower+2) = (FLOAT32)ApparentPower;
	*(pPower+3) = (FLOAT32)PowerFactor;
	*(pPower+4) = (FLOAT32)(PowerAngle * 180 / PI);

	//�������Ƿ�ΧΪ(-180, 180)
	if (*(pPower+4) > 180)
	{
		*(pPower+4) -= 360;
	}
	else if ( *(pPower+4) < -180)
	{
		*(pPower+4) += 360;
	}

	return TRUE;	
}

FLOAT32 BasicAlgorithm::SHGetFrequency( FLOAT32 * pData, INT32 smpRate )
{
	FLOAT64 sum, imag[2], real[2], angle[2], deltAng, deltFreq, tempfreq = 50;
	INT32 i, k, tempPCount = smpRate / 50;

	//��ڲ������
	if (pData==NULL || smpRate<400)
	{
		return 0;
	}

	//����ʸ��
	for (i=0; i<2; i++)
	{
		sum = 0;
		for (k=0; k<tempPCount; k++)
		{
			sum += *(pData+i*tempPCount+k) * cos(2*PI*k/tempPCount);
		}
		imag[i] = 2 * sum / tempPCount;//�鲿

		sum = 0;
		for (k=0; k<tempPCount; k++)
		{
			sum += *(pData+i*tempPCount+k) * sin(2*PI*k/tempPCount);
		}
		real[i] = 2 * sum / tempPCount;//ʵ��

		angle[i] = (imag[i]<0) ? 2*PI+atan2(imag[i],real[i]) : atan2(imag[i],real[i]);
	}

	//����ǲ�
	deltAng = angle[1] - angle[0];
	deltAng = 1 / (1 + ((deltAng>PI)?(deltAng-2*PI) : ((deltAng<-PI) ? (deltAng+2*PI):deltAng)) / (2*PI));

	//�����ǲ�
	deltFreq = atan2(imag[1]*deltAng, real[1]) - atan2(imag[0]*deltAng, real[0]);
	deltFreq = (deltFreq>PI) ? (deltFreq-2*PI) : ((deltFreq<-PI) ? (deltFreq+2*PI) : deltFreq);

	tempfreq += tempfreq * deltFreq / (2 * PI);

	//�ٴμ���
	if ((tempfreq>49.2 && tempfreq<50.8) || tempfreq>62 || tempfreq<35)
	{
		return (FLOAT32)tempfreq;
	}

	tempPCount = (INT32)(smpRate / tempfreq+0.5);
	tempfreq = smpRate * 1.0 / tempPCount;

	for (i=0; i<2; i++)
	{
		sum = 0;
		for (k=0; k<tempPCount; k++)
		{
			sum += *(pData+i*tempPCount+k) * cos(2*PI*k/tempPCount);
		}
		imag[i] = 2 * sum / tempPCount;//�鲿

		sum = 0;
		for (k=0; k<tempPCount; k++)
		{
			sum += *(pData+i*tempPCount+k) * sin(2*PI*k/tempPCount);
		}
		real[i] = 2 * sum / tempPCount;//ʵ��

		angle[i] = (imag[i]<0) ? 2*PI+atan2(imag[i],real[i]) : atan2(imag[i],real[i]);
	}

	//����ǲ�
	deltAng = angle[1] - angle[0];
	deltAng = 1 / (1 + ((deltAng>PI)?(deltAng-2*PI) : ((deltAng<-PI) ? (deltAng+2*PI):deltAng)) / (2*PI));

	//�����ǲ�
	deltFreq = atan2(imag[1]*deltAng, real[1]) - atan2(imag[0]*deltAng, real[0]);
	deltFreq = (deltFreq>PI) ? (deltFreq-2*PI) : ((deltFreq<-PI) ? (deltFreq+2*PI) : deltFreq);

	tempfreq += tempfreq * deltFreq / (2 * PI);

	return (FLOAT32)tempfreq;
}

FLOAT32 BasicAlgorithm::SHGetFrequency( INT16 * pData, INT32 smpRate )
{
	FLOAT64 sum, imag[2], real[2], angle[2], deltAng, deltFreq, tempfreq = 50;
	INT32 i, k, tempPCount = smpRate / 50;

	//��ڲ������
	if (pData==NULL || smpRate<400)
	{
		return 0;
	}

	//����ʸ��
	for (i=0; i<2; i++)
	{
		sum = 0;
		for (k=0; k<tempPCount; k++)
		{
			sum += *(pData+i*tempPCount+k) * cos(2*PI*k/tempPCount);
		}
		imag[i] = 2 * sum / tempPCount;//�鲿

		sum = 0;
		for (k=0; k<tempPCount; k++)
		{
			sum += *(pData+i*tempPCount+k) * sin(2*PI*k/tempPCount);
		}
		real[i] = 2 * sum / tempPCount;//ʵ��

		angle[i] = (imag[i]<0) ? 2*PI+atan2(imag[i],real[i]) : atan2(imag[i],real[i]);
	}

	//����ǲ�
	deltAng = angle[1] - angle[0];
	deltAng = 1 / (1 + ((deltAng>PI)?(deltAng-2*PI) : ((deltAng<-PI) ? (deltAng+2*PI):deltAng)) / (2*PI));

	//�����ǲ�
	deltFreq = atan2(imag[1]*deltAng, real[1]) - atan2(imag[0]*deltAng, real[0]);
	deltFreq = (deltFreq>PI) ? (deltFreq-2*PI) : ((deltFreq<-PI) ? (deltFreq+2*PI) : deltFreq);

	tempfreq += tempfreq * deltFreq / (2 * PI);

	//�ٴμ���
	if ((tempfreq>49.2 && tempfreq<50.8) || tempfreq>62 || tempfreq<35)
	{
		return (FLOAT32)tempfreq;
	}

	tempPCount = (INT32)(smpRate / tempfreq+0.5);
	tempfreq = smpRate * 1.0 / tempPCount;

	for (i=0; i<2; i++)
	{
		sum = 0;
		for (k=0; k<tempPCount; k++)
		{
			sum += *(pData+i*tempPCount+k) * cos(2*PI*k/tempPCount);
		}
		imag[i] = 2 * sum / tempPCount;//�鲿

		sum = 0;
		for (k=0; k<tempPCount; k++)
		{
			sum += *(pData+i*tempPCount+k) * sin(2*PI*k/tempPCount);
		}
		real[i] = 2 * sum / tempPCount;//ʵ��

		angle[i] = (imag[i]<0) ? 2*PI+atan2(imag[i],real[i]) : atan2(imag[i],real[i]);
	}

	//����ǲ�
	deltAng = angle[1] - angle[0];
	deltAng = 1 / (1 + ((deltAng>PI)?(deltAng-2*PI) : ((deltAng<-PI) ? (deltAng+2*PI):deltAng)) / (2*PI));

	//�����ǲ�
	deltFreq = atan2(imag[1]*deltAng, real[1]) - atan2(imag[0]*deltAng, real[0]);
	deltFreq = (deltFreq>PI) ? (deltFreq-2*PI) : ((deltFreq<-PI) ? (deltFreq+2*PI) : deltFreq);

	tempfreq += tempfreq * deltFreq / (2 * PI);

	return (FLOAT32)tempfreq;
}

FLOAT32 BasicAlgorithm::SHGetRmsAmp( INT16 * pData, FLOAT32 multiplier, FLOAT32 offset, INT32 perCycPoints )
{
	INT32 i;
    FLOAT64 tempValue, sum;
        unsigned short *temp;

	//��ڲ������
	if (pData==NULL || perCycPoints<8)
	{
		return 0;
	}

	//������Чֵ
	sum = 0;
        temp=(unsigned short *)pData;

	for (i=0; i<perCycPoints; i++)
	{
//                qDebug()<<"pData["<<i<<"]="<<*pData<<'\n';//2018-10-11
                printf("pData[ %d ]= %d\n",i,*(/*pData*/temp+i));
                tempValue = multiplier * *(/*pData*/temp+i) + offset;
                 //qDebug()<<"   tempValue="<<tempValue<<'\n';
//                 printf(" tempValue== %f\n",tempValue);//2018-10-11
		sum += tempValue * tempValue;
	}
	sum = sqrt(sum / perCycPoints);

        if (sum < 0.08 )	//ctm
        {
                FLOAT32 pHarmonic[4];
//                SHGetHarmonic( pData, multiplier, perCycPoints, 1, 1, pHarmonic );
//                pHarmonic[2] = SHGetMeanValue( pData, multiplier, offset, perCycPoints);
                                SHGetHarmonic( temp, multiplier, perCycPoints, 1, 1, pHarmonic );
                                pHarmonic[2] = SHGetMeanValue( temp, multiplier, offset, perCycPoints);
                sum = sqrt(pHarmonic[0]*pHarmonic[0] + pHarmonic[2]*pHarmonic[2]);
        }

	return (FLOAT32)sum;
}

FLOAT32 BasicAlgorithm::SHGetRmsAmp( FLOAT32 * pData, INT32 perCycPoints, INT32 nChType)
{
	FLOAT64 sum = 0;
	FLOAT32 pHarmonic[6];

	//��ڲ������
	if (pData == NULL || perCycPoints <= 0)
	{
		return 0;
	}

	//������Чֵ
	for (INT32 i=0; i<perCycPoints; i++)
	{
		sum += *(pData+i) * *(pData+i);
	}
	sum = sqrt(sum / perCycPoints);

	//����SHDFR���ø���Ŵ�������Ư���ޣ��빢����·��Э�� - 090930
	//return ֱ���ͻ���������
	if (sum < 0.07 && (nChType == 1 || nChType == 2))
	{
		SHGetHarmonic( pData, 1, perCycPoints, pHarmonic );
		sum = sqrt(pHarmonic[0]*pHarmonic[0] + pHarmonic[2]*pHarmonic[2]);
	}
	else if (sum < 0.2 && nChType == 4)
	{
		SHGetHarmonic( pData, 1, perCycPoints, pHarmonic );
		sum = fabs(pHarmonic[0]) * 0.5;	//ctm
	}
	return (FLOAT32)sum;
}

void BasicAlgorithm::SHGetAnotherTime( YHFTmStruct srcTime, FLOAT64 relativeTime, YHFTmStruct & destTime )
{
	FLOAT64 result;
	struct tm tm0, *tm1;
	time_t t0;

	//�õ�ms��
	result = srcTime.Millisecond / 1000.0 + srcTime.Microsecond / 1000000.0;

	//ת��ʱ��srcTime
	tm0.tm_year = srcTime.Year - 1900;
	tm0.tm_mon = srcTime.Month - 1;
	tm0.tm_mday = srcTime.Day;
	tm0.tm_hour = srcTime.Hour;
	tm0.tm_min = srcTime.Minute;
	tm0.tm_sec = srcTime.Second;
	tm0.tm_isdst = 0;

	//�õ�s��
	t0 = mktime(&tm0);	//tm->time_t
	result += t0 + relativeTime / 1000;
	t0 = (INT32)result;

	result = (result - t0) * 1000;
	destTime.Millisecond = (WORD)(result);	//ms
	result *= 1000;
	destTime.Microsecond = (WORD)(((INT32)result) % 1000);	//us

	//tm1 = gmtime(&t0);
	tm1 = localtime(&t0);

	//�õ�ʱ��destTime
	destTime.Year = tm1->tm_year + 1900;
	destTime.Month = tm1->tm_mon + 1;
	destTime.Day = tm1->tm_mday;
	destTime.Hour = tm1->tm_hour;
	destTime.Minute = tm1->tm_min;
	destTime.Second = tm1->tm_sec;
}

FLOAT32 BasicAlgorithm::SHGetMeanValue( /*INT16 **/unsigned short * pData, FLOAT32 multiplier, FLOAT32 offset, INT32 perCycPoints )
{
	INT32 i;
	FLOAT64 sum = 0;

	//��ڲ������
	if (pData==NULL || perCycPoints<8)
	{
		return 0;
	}

	//����ƽ��ֵ
	for (i=0; i<perCycPoints; i++)
	{
		sum += *(pData + i);
	}
	sum /= perCycPoints;

	return (FLOAT32)(multiplier * sum + offset);
}

FLOAT32 BasicAlgorithm::SHGetMeanValue( FLOAT32 * pData, INT32 perCycPoints )
{
	INT32 i;
	FLOAT64 sum = 0;

	//��ڲ������
	if (pData==NULL || perCycPoints<8)
	{
		return 0;
	}

	//����ƽ��ֵ
	for (i=0; i<perCycPoints; i++)
	{
		sum += *(pData + i);
	}
	sum /= perCycPoints;

	return (FLOAT32)sum;
}

FLOAT32 BasicAlgorithm::SHGetDecayTimeConstant(FLOAT32 *pData, INT32 length, INT32 smpRate)
{
	INT32 i, j, step, availableCount;	//��Ч���ݸ��� availableCount
	INT32 perCycPoints, twoCycPoint, maxPoint;
	FLOAT64 sum, value[30], DecayTimeConstant, maxValue, CycCount, fTemp;
	
	//��ڲ������
	perCycPoints = smpRate / 50;
	CycCount = length * 50.0 / smpRate;
	if (pData==NULL || perCycPoints<8 || CycCount<3.5)
	{
		return -1;
	}
	
	//�����ֵ��
	maxValue = 0;
	j = perCycPoints / 5;
	twoCycPoint = perCycPoints + perCycPoints / 5;
	for (i=perCycPoints / 5; i<=twoCycPoint; i++)
	{
		if (fabs(pData[i]) > maxValue && fabs(pData[i]) > fabs(pData[i-2]))
		{
			j = i;
			maxValue = fabs(pData[j]);
		}
	}

	//��ʼ������ÿ�μ���ܲ�
	step = (INT32)(((length - j) * 1.0 / perCycPoints - 0.125) / 2);

	//�����ڷ���������
	if (fabs(pData[j]) < fabs(pData[j+step*perCycPoints]) + 0.01
		|| fabs(pData[j+step*perCycPoints]) < fabs(pData[j+2*step*perCycPoints]) + 0.01)
	{
		return -1;
	}
	
	sum = 0;
	availableCount = 0;
	maxPoint = j + perCycPoints / 8;
	for (j-=3; j<maxPoint; j++)
	{
		if ((fTemp = (pData[j] - pData[j + step*perCycPoints])
			/ (pData[j + step*perCycPoints] - pData[j + 2*step*perCycPoints])) > 0 )
		{
			DecayTimeConstant = 0.02 * step / log(fTemp);	//��˥������
			if (DecayTimeConstant>0.01 && DecayTimeConstant<1) 
			{
        if(availableCount>=30){
          return -1.0;
        }
					value[availableCount++] = DecayTimeConstant;
					sum += DecayTimeConstant;
			}
		}
	}

	//ƽ��ֵ�˲�
	maxPoint = availableCount;
	maxValue = 0;
	if (availableCount != 0)
	{
		DecayTimeConstant = sum / availableCount;
	}
	for (i=0; i<maxPoint; i++)
	{
			if (value[i] > DecayTimeConstant * 1.1 || value[i] < DecayTimeConstant * 0.88)
			{
				sum -= value[i];
				availableCount--;
			}
			else if (value[i] > maxValue)
			{
				maxValue = value[i];
			}
	}
	
	if (availableCount != 0)
	{
		DecayTimeConstant = maxValue * 0.1 + sum / availableCount * 0.9;
	}
	else
	{
		DecayTimeConstant = -1;
	}

	return (FLOAT32)DecayTimeConstant;
}
