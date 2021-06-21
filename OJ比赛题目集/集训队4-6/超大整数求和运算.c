#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#define N 100	//最大可以处理二十位以内的数字的运算
typedef struct bigint{
	char *num;	//大整数数据域
	int sign;	//大整数符号位
	int digit;	//大整数位数

};
BIGINT ScanfBigInt();	//大整数的读取处理函数
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
