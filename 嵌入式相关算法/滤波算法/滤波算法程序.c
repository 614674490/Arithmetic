#include <stdio.h>
#include <absacc.h>
#include <intrins.h>
#include <./Atmel/at89x52.h>
#include "source.h"
main()
{
    filter_1();
	filter_2();
	filter_3();
	filter_4();
    filter_5();
	filter_6();
	filter_7();
	filter_8();
    filter_9();
	filter_10();
}
unsigned char get_ad(void){
	static unsigned char i;
	return i++;
}
void delay(void){
	unsigned char i=0;
	while(1){
		i++;
		if(i>20) return;
	}
}
/***�޷��˲�**/
#define A 10 //�������β�����������ƫ��ֵ
char value;  //�ϴβ��ú����Чֵ����
char filter_1(void){
    char  new_value;  //���β���ֵ����
    new_value=get_ad();  //���뱾�β���ֵ
    if((new_value-value>A)||(value-new_value>A)) //�Ƚ��Ƿ񳬳����ƫ��ֵ
        return  value; //��������������ϴε���Чֵ��Ϊ���ε���Чֵ
    return  new_value;// ���û�г��������ر��εĲ���ֵ��Ϊ���ε���Чֵ
}
/***��λֵ�˲���***/
#define N 11 //�������������Ĵ���

char filter_2(void){
    char  value_buf[N]; //����N�β���ֵ�Ĵ洢����
    char  count,i,j,temp; //i��j��ð��������±������count�ǲ������ݶ�����±����
                      //temp����ʱ����
    for(count=0;count<N;count++) //��������N������ֵ
    {
      value_buf[count]=get_ad();
      delay();
    }
    for(j=0;j<N;j++) //����������С����
    {
        for(i=0;i<N-j;i++)
        {
           if(value_buf[i]>value_buf[i+1])
         {
           temp=value_buf[i];
           value_buf[i]=value_buf[i+1];
           value_buf[i+1]=temp;
           }
         }
     }
     return value_buf[(N-1)/2]; //�������N������ֵ���м�ֵ��Ϊ���������
}
/**����ƽ���˲���**/
/* NΪ����ƽ�������ÿ�����ֵ������������ʵ��������Ըı�*/
#undef N
#define N 12 //����ÿ�����ƽ������Ĳ���ֵ����

char filter_3(){
    int  sum=0; //��ͱ��������ڴ洢����ֵ���ۼ�ֵ
    char count;//�������ݶ�����±����
    for(count=0;count<N;count++) //��������N������ֵ�����ۼ�
    {
      sum+=get_ad();
      delay();
    }
    return (char)(sum/N); //���ۼ�ֵ����ƽ��������Ϊ����ֵ
}
/**����ƽ���˲���**/
#undef N
#define N 12 //����FIFO���еĳ���
char  value_buf[N];//FIFO���б���
char  i=0; //���е��±����

char filter_4(){
    char count;
	int  sum=0;
	value_buf[i++]=get_ad();
	if(i==N)  i=0;
    for(count=0;count<N;count++)
      sum+=value_buf[count];
    return(char)(sum/N);
}

#include "stdio.h"
#define N 10

int buf[N]={0};
int i=0,j=0;
int filter()
{
	int sum=0,a;
	int k;
	scanf("%d",&a);
	buf[i++]=a;
	if(i==N) i=0;
	j++;
	if(j<=N)
	{
		for(k=0;k<j;k++)
		{
			sum+=buf[k];
		}
		return (sum/j);
	}
	else
	{
		for(k=0;k<N;k++)
		{
			sum+=buf[k];
		}
		return (sum/N);
	}
}
int main()
{
	int avreage=0;
	while(1)
	{
		avreage=filter();
		printf("%d\n",avreage);
	}
}

/**��λֵƽ���˲���**/
/* ����ֵNΪÿ�����ֵ������������ʵ��������Ըı�*/
#undef N
#define N 12 //����ÿ�����ֵ������
char filter_5()
{
   char count,i,j,temp; //i��j��ð��������±������count�ǲ������ݶ�����±����
   char value_buf[N]; // ����N������ֵ�Ĵ洢����
   int  sum=0; //��ͱ��������ڴ洢����ֵ���ۼ�ֵ
   for  (count=0;count<N;count++) //��������N������ֵ
   {
      value_buf[count] = get_ad();
      delay();
   }
   for (j=0;j<N-1;j++) //����������С����
   {
      for (i=0;i<N-j;i++)
      {
         if ( value_buf[i]>value_buf[i+1] )
         {
            temp = value_buf[i];
            value_buf[i] = value_buf[i+1];
             value_buf[i+1] = temp;
         }
      }
   }
   for(count=1;count<N-1;count++)
    sum += value_buf[count]; //ȥ�����˵���С��������ֵ�����м��N-2������ֵ���
   return (char)(sum/(N-2));// �����м�N-2������ֵ��ƽ��ֵ
}
/**�޷�ƽ���˲���**/
/* Aֵ���Ը���ʵ�����������valueΪ�ϴβ�������Чֵ��new_valueΪ��ǰ����ֵ */
/* NΪ����ƽ�������ÿ�����ֵ������������ʵ��������Ըı�*/
#undef A
#undef N
#define A 10 //�������β�����������ƫ��ֵ
#define N 12 //����ÿ�����ƽ������Ĳ���ֵ����
char value;  //�ϴβ��ú����Чֵ����

char filter_6()
{
    char  new_value;  //���β���ֵ����
    int  sum=0; //��ͱ��������ڴ洢����ֵ���ۼ�ֵ
    char count;//�������ݶ�����±����
	for(count=0;count<N;count++)
    {
		new_value=get_ad();  //���뱾�β���ֵ
      	if((new_value-value>A)||(value-new_value>A)) //�Ƚ��Ƿ񳬳����ƫ��ֵ
      		new_value=value; //��������������ϴε���Чֵ��Ϊ���ε���Чֵ
      	sum+=new_value; //�ۼӲ�������Чֵ
      	value=new_value;
      	delay();
    }
    return (char)(sum/N); //���ۼ�ֵ����ƽ��������Ϊ����ֵ
}
/**һ���ͺ��˲���**/
/* Ϊ�ӿ�������ٶȼٶ�����Ϊ100��a=0~100 */
#define COE 50 //�����Ȩϵ��
char value; //��һ������ֵ����
char filter_7()
{
   char  new_value; //���β���ֵ����
   new_value = get_ad();
   return (100-COE)*value + COE*new_value; //���صı����˲����
}


/**��Ȩ����ƽ���˲���**/
/* coe����Ϊ��Ȩϵ�������ڳ���洢����*/
#undef N
#define N 12  //����FIFO���еĳ���

char code coe[N] = {1,2,3,4,5,6,7,8,9,10,11,12}; //��Ȩϵ��
char code sum_coe = 1+2+3+4+5+6+7+8+9+10+11+12;
char filter_8()
{
   char count; //�������ݶ�����±����
   char value_buf[N]; //����N������ֵ�Ĵ洢����
   int  sum=0; //��ͱ��������ڴ洢����ֵ���ۼ�ֵ
   for (count=0;count<N;count++)
   {
      value_buf[count] = get_ad(); //�������ֵ
      delay();
   }
   for (count=0;count<N;count++)
      sum += value_buf[count]*coe[count]; //�ۼӲ���ֵ��ϵ���ĳ˻�
   return (char)(sum/sum_coe); //�ۼ�ֵ��ϵ���������Ϊ���ؽ��
}

/**�����˲���**/
#undef N
#define N 12 //���ü��������ֵ
char filter_9()
{
   char count=0; //��������
   char new_value; //���β���ֵ����
   new_value = get_ad(); //���뱾�β���ֵ
   while (value !=new_value);
   {
      count++; //��������1
      if (count>=N)   return new_value; //������β���ֵ�뵱ǰ��Чֵ����ȣ�
//�Ҽ�������������ر��β���ֵ
       delay();
      new_value = get_ad();
   }
   return value; //������β���ֵ�뵱ǰ��Чֵ��ȣ��򷵻ص�ǰ��Чֵ
}


/**�޷������˲���**/

/* Aֵ���Ը���ʵ�����������valueΪ�ϴβ�������Чֵ��new_valueΪ��ǰ����ֵ */
/* NΪ�����������ֵ*/
#undef A
#undef N
#define A 10 //�������β�����������ƫ��ֵ
#define N 12 //���ü��������ֵ
char value;  //��Чֵ����

char filter_10()
{
   char count=0; //��������
   char new_value; //���β���ֵ����
   new_value = get_ad(); //���뱾�β���ֵ
	if((new_value-value>A)||(value-new_value>A)) //�Ƚ��Ƿ񳬳����ƫ��ֵ
		new_value=value; //���������������Чֵ��Ϊ���εĲ�����Чֵ
   while (value !=new_value);
   {
      count++; //��������1
      if (count>=N)   return new_value; //������β���ֵ�뵱ǰ��Чֵ����ȣ�
										//�Ҽ�������������ر��β���ֵ
       delay();
      new_value = get_ad();
   }
   return value; //������β���ֵ�뵱ǰ��Чֵ��ȣ��򷵻ص�ǰ��Чֵ
}












