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
/***限幅滤波**/
#define A 10 //设置两次采样允许的最大偏差值
char value;  //上次采用后的有效值变量
char filter_1(void){
    char  new_value;  //本次采样值变量
    new_value=get_ad();  //读入本次采样值
    if((new_value-value>A)||(value-new_value>A)) //比较是否超出最大偏差值
        return  value; //如果超出，返回上次的有效值作为本次的有效值
    return  new_value;// 如果没有超出，返回本次的采样值作为本次的有效值
}
/***中位值滤波法***/
#define N 11 //设置连续采样的次数

char filter_2(void){
    char  value_buf[N]; //缓存N次采样值的存储变量
    char  count,i,j,temp; //i，j是冒泡排序的下标变量，count是采样数据读入的下标变量
                      //temp是临时变量
    for(count=0;count<N;count++) //连续读入N个采样值
    {
      value_buf[count]=get_ad();
      delay();
    }
    for(j=0;j<N;j++) //气泡排序，由小到大
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
     return value_buf[(N-1)/2]; //将排序后N个采样值的中间值作为最后结果返回
}
/**算数平均滤波法**/
/* N为进行平均运算的每组采样值的数量，依据实际情况可以改变*/
#undef N
#define N 12 //设置每组参与平均运算的采样值个数

char filter_3(){
    int  sum=0; //求和变量，用于存储采样值的累加值
    char count;//采样数据读入的下标变量
    for(count=0;count<N;count++) //连续读入N个采样值，并累加
    {
      sum+=get_ad();
      delay();
    }
    return (char)(sum/N); //讲累加值进行平均计算作为返回值
}
/**递推平均滤波法**/
#undef N
#define N 12 //设置FIFO队列的长度
char  value_buf[N];//FIFO队列变量
char  i=0; //队列的下标变量

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

/**中位值平均滤波法**/
/* 采样值N为每组采样值的数量，依据实际情况可以改变*/
#undef N
#define N 12 //设置每组采样值的数量
char filter_5()
{
   char count,i,j,temp; //i，j是冒泡排序的下标变量，count是采样数据读入的下标变量
   char value_buf[N]; // 缓冲N个采样值的存储变量
   int  sum=0; //求和变量，用于存储采样值的累加值
   for  (count=0;count<N;count++) //连续读入N个采样值
   {
      value_buf[count] = get_ad();
      delay();
   }
   for (j=0;j<N-1;j++) //气泡排序，由小到大
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
    sum += value_buf[count]; //去掉两端的最小和最大采样值，对中间的N-2个采样值求和
   return (char)(sum/(N-2));// 返回中间N-2个采样值的平均值
}
/**限幅平均滤波法**/
/* A值可以根据实际情况调整，value为上次采样的有效值，new_value为当前采样值 */
/* N为进行平均运算的每组采样值的数量，依据实际情况可以改变*/
#undef A
#undef N
#define A 10 //设置两次采样允许的最大偏差值
#define N 12 //设置每组参与平均运算的采样值个数
char value;  //上次采用后的有效值变量

char filter_6()
{
    char  new_value;  //本次采样值变量
    int  sum=0; //求和变量，用于存储采样值的累加值
    char count;//采样数据读入的下标变量
	for(count=0;count<N;count++)
    {
		new_value=get_ad();  //读入本次采样值
      	if((new_value-value>A)||(value-new_value>A)) //比较是否超出最大偏差值
      		new_value=value; //如果超出，返回上次的有效值作为本次的有效值
      	sum+=new_value; //累加采样的有效值
      	value=new_value;
      	delay();
    }
    return (char)(sum/N); //将累加值进行平均计算作为返回值
}
/**一阶滞后滤波法**/
/* 为加快程序处理速度假定基数为100，a=0~100 */
#define COE 50 //定义加权系数
char value; //上一个采样值变量
char filter_7()
{
   char  new_value; //本次采样值变量
   new_value = get_ad();
   return (100-COE)*value + COE*new_value; //返回的本次滤波结果
}


/**加权递推平均滤波法**/
/* coe数组为加权系数表，存在程序存储区。*/
#undef N
#define N 12  //设置FIFO队列的长度

char code coe[N] = {1,2,3,4,5,6,7,8,9,10,11,12}; //加权系数
char code sum_coe = 1+2+3+4+5+6+7+8+9+10+11+12;
char filter_8()
{
   char count; //采样数据读入的下标变量
   char value_buf[N]; //缓存N个采样值的存储变量
   int  sum=0; //求和变量，用于存储采样值的累加值
   for (count=0;count<N;count++)
   {
      value_buf[count] = get_ad(); //读入采样值
      delay();
   }
   for (count=0;count<N;count++)
      sum += value_buf[count]*coe[count]; //累加采样值和系数的乘积
   return (char)(sum/sum_coe); //累加值与系数和相除作为返回结果
}

/**消抖滤波法**/
#undef N
#define N 12 //设置计数器溢出值
char filter_9()
{
   char count=0; //计数变量
   char new_value; //本次采样值变量
   new_value = get_ad(); //读入本次采样值
   while (value !=new_value);
   {
      count++; //计数器加1
      if (count>=N)   return new_value; //如果本次采样值与当前有效值不相等，
//且计数器溢出，返回本次采样值
       delay();
      new_value = get_ad();
   }
   return value; //如果本次采样值与当前有效值相等，则返回当前有效值
}


/**限幅消抖滤波法**/

/* A值可以根据实际情况调整，value为上次采样的有效值，new_value为当前采样值 */
/* N为计数器的溢出值*/
#undef A
#undef N
#define A 10 //设置两次采样允许的最大偏差值
#define N 12 //设置计数器溢出值
char value;  //有效值变量

char filter_10()
{
   char count=0; //计数变量
   char new_value; //本次采样值变量
   new_value = get_ad(); //读入本次采样值
	if((new_value-value>A)||(value-new_value>A)) //比较是否超出最大偏差值
		new_value=value; //如果超出，返回有效值作为本次的采样有效值
   while (value !=new_value);
   {
      count++; //计数器加1
      if (count>=N)   return new_value; //如果本次采样值与当前有效值不相等，
										//且计数器溢出，返回本次采样值
       delay();
      new_value = get_ad();
   }
   return value; //如果本次采样值与当前有效值相等，则返回当前有效值
}












