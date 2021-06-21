#include "stdio.h"

#define max_people 11  //������ ʵ��Ϊ10
#define max_n 5        //�������

/*
  ��һ�����ҷ����� 5 �����ÿ�����Ļƽ�����ͬ����Ҫ�����ھ�Ĺ�����Ҳ��ͬ�������ڿ��˵������� 10 �ˡ�
  ÿ�����Ҫôȫ�ڣ�Ҫô���ڣ������ɳ�һ������ȡһ����Ҫ���ó���������Ҫ��õ������ܶ�Ļƽ�
  Ӧ��ѡ����ȡ�ļ������
  1��400��/5��   2��500��/5��   3��200��/3��    4��300��/4��    5��350��/3��
*/
int maxGold[max_people][max_n];  //���ڴ洢������Ľ���ֵ �����ظ�������ֱ�ӵ��� =-1��Ϊδ�����
int gold[max_n]={200,300,350,400,500};  //ÿ�������ܼ�ֵ 0 1 2 3 4 5
int peopleNeed[max_n]={3,4,3,5,5};      //ÿ��������������
/* -------------------------- */
/* ����ֵ                     */
/* -------------------------- */
int max(int x,int y)
{
    int z;
    z=x>y ? x:y;
    return z;
}
/* -------------------------- */
/* people:Ա����              */
/* mineNum:�����             */
/* return ����Ǯ            */
/* -------------------------- */
int GetMaxGold(int people , int mineNum)
{
    int retMaxGold;                          //���ڷ��ؽ����
    maxGold[people][mineNum]=-1;      //��̬�滮ʱ˳���ʼ��
    //�������������������
    if(maxGold[people][mineNum]!=-1)
    {
        retMaxGold=maxGold[people][mineNum];
    }
    else if(mineNum==0)   //ֻ��һ�����
    {
        if(people>=peopleNeed[mineNum])  //��������㹻�����ý�� ���øý��Ľ�����
        {
             retMaxGold=gold[mineNum];
        }
        else
        {
            retMaxGold=0;            //�������� �������Ϊ��
        }
    }
    else if(people>=peopleNeed[mineNum])   //��������㹻�����ý��
    {
        //��������� ��ǰ�˼������ɸý�� �����˿�����һ�����/ȫ��ȥ������һ�����
        retMaxGold=max( GetMaxGold((people-peopleNeed[mineNum]),mineNum-1)+gold[mineNum] , GetMaxGold(people,mineNum-1));
    }
    else  //�����������ɸý��
    {
        retMaxGold= GetMaxGold(people,mineNum-1);  //������һ�����
        maxGold[people][mineNum]=retMaxGold;  //��¼�˴ν�����
    }
    return retMaxGold;
}
int main()
{
    int people=0,mineNum=0;
    int max_money=0;   //��¼�����
    printf("���������Ŀ�ͽ����Ŀ:\r\n");
    scanf("%d %d",&people,&mineNum);
    mineNum-=1;            //����Ϊ�����½Ǳ�
    max_money=GetMaxGold(people,mineNum);
    printf("max_money = %d\n",max_money);
}
