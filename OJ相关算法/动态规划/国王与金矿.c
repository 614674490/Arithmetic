#include "stdio.h"

#define max_people 11  //矿工总数 实际为10
#define max_n 5        //金矿总数

/*
  有一个国家发现了 5 座金矿，每座金矿的黄金储量不同，需要参与挖掘的工人数也不同。参与挖矿工人的总数是 10 人。
  每座金矿要么全挖，要么不挖，不能派出一半人挖取一半金矿。要求用程序求解出，要想得到尽可能多的黄金，
  应该选择挖取哪几座金矿？
  1、400金/5人   2、500金/5人   3、200金/3人    4、300金/4人    5、350金/3人
*/
int maxGold[max_people][max_n];  //用于存储计算过的金矿价值 遇到重复子问题直接调用 =-1则为未计算过
int gold[max_n]={200,300,350,400,500};  //每个金矿的总价值 0 1 2 3 4 5
int peopleNeed[max_n]={3,4,3,5,5};      //每个金矿所需的人数
/* -------------------------- */
/* 求最值                     */
/* -------------------------- */
int max(int x,int y)
{
    int z;
    z=x>y ? x:y;
    return z;
}
/* -------------------------- */
/* people:员工数              */
/* mineNum:金矿数             */
/* return 最多金钱            */
/* -------------------------- */
int GetMaxGold(int people , int mineNum)
{
    int retMaxGold;                          //用于返回金额数
    maxGold[people][mineNum]=-1;      //动态规划时顺便初始化
    //如果这个问题曾经计算过
    if(maxGold[people][mineNum]!=-1)
    {
        retMaxGold=maxGold[people][mineNum];
    }
    else if(mineNum==0)   //只有一个金矿
    {
        if(people>=peopleNeed[mineNum])  //如果人数足够开发该金矿 则获得该金矿的金子数
        {
             retMaxGold=gold[mineNum];
        }
        else
        {
            retMaxGold=0;            //人数不足 则金子数为零
        }
    }
    else if(people>=peopleNeed[mineNum])   //如果人数足够开发该金矿
    {
        //分两种情况 当前人继续开采该金矿 其他人开采另一个金矿/全都去开采另一个金矿
        retMaxGold=max( GetMaxGold((people-peopleNeed[mineNum]),mineNum-1)+gold[mineNum] , GetMaxGold(people,mineNum-1));
    }
    else  //人数不够开采该金矿
    {
        retMaxGold= GetMaxGold(people,mineNum-1);  //开采下一个金矿
        maxGold[people][mineNum]=retMaxGold;  //记录此次金子数
    }
    return retMaxGold;
}
int main()
{
    int people=0,mineNum=0;
    int max_money=0;   //记录最大金额
    printf("请输入矿工数目和金矿数目:\r\n");
    scanf("%d %d",&people,&mineNum);
    mineNum-=1;            //调整为数组下角标
    max_money=GetMaxGold(people,mineNum);
    printf("max_money = %d\n",max_money);
}
