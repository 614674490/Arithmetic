#include "stdio.h"
#include "math.h"
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;//���Ǵ�С�����������ǴӴ�С�ĳɣ� return *(int *)b-*(int *)a;
}
//����ʵ����С���� ���߻��Ѵ�С����
void main()
{
    int ai[10][10000],bi[10][10000],ci[10][10000];
    int T,n,m;
    int i,j,k;
    int min_val=-1;
    int sum_val=0;
    int val[10];
    int flag=1;
    int num=0;
    scanf("%d",&T);

    for(i=0;i<T;i++)
    {
        scanf("%d %d",&n,&m);   //�� ����
        for(j=0;j<n;j++)
        {
           scanf("%d",&ai[i][j]);  //����ս����
        }
        for(j=0;j<m;j++)
        {
            scanf("%d %d",&bi[i][j],&ci[i][j]);  //���ߵ�ս���� ��Ӷ��
        }
        qsort(ai[i],n,4,cmp);  //�����ַ ���� �ֽڴ�С ����ʽ
        for(k=0;k<n;k++)
        {
            for(j=0;j<m;j++)
            {
                if(bi[i][j]>=ai[i][k])
                {
                    num++;
                    if(num==1)
                    {
                        min_val=ci[i][j];
                    }
                    else
                    {
                        if(ci[i][j]<min_val)
                            min_val=ci[i][j];
                    }
                }
            }
            num=0;
            if(min_val>0)
                sum_val+=min_val;
            else
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            val[i]=sum_val;
        }
        else
            val[i]=-1;
        sum_val=0;
        min_val=-1;
        flag=1;


    }
    for(i=0;i<T;i++)
    {
        if(i!=T-1)
        {
            if(val[i]>0) printf("%d\n",val[i]);
            else printf("Kingdom fall\n");
        }
        else
        {
            if(val[i]>0) printf("%d",val[i]);
            else printf("Kingdom fall");
        }
    }

}
