#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#define N 100	//�����Դ����ʮλ���ڵ����ֵ�����
typedef struct bigint{
	char *num;	//������������
	int sign;	//����������λ
	int digit;	//������λ��

};
BIGINT ScanfBigInt();	//�������Ķ�ȡ������
void PrintBigInt(BIGINT BigInt);
void Add(BIGINT BigInt1,BIGINT BigInt2);
BIGINT AddTwoBigInt(BIGINT BigInt1,BIGINT BigInt2);
BIGINT SubTwoBigInt(BIGINT BigInt1,BIGINT BigInt2);
int CompareBigInt(BIGINT BigInt1,BIGINT BigInt2);
BIGINT Sum(BIGINT BigInt1,BIGINT BigInt2);

void main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {

    }
}
