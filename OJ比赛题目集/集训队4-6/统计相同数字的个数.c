#include "stdio.h"
#include "stdlib.h"
#define MAX_LEN 200001
//qsortĬ�ϴ�С��������
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
void main()
{
    int ans_arr[MAX_LEN];
    int cnt=0,s=0;
    int i=0;
    int T=0;
    int n;
    int temp;
    scanf("%d",&n);
    T=n;
    while(T--)
    {
        scanf("%d",&ans_arr[T]);
    }
    qsort(ans_arr,n,sizeof(int),cmp);
    for(i=0;i<n;i++)  //�Ѿ����մ�С�����˳������ �൱���������ظ���������ȥ���ظ�Ԫ�� �����ͱȽϼ���
    {
        if(i==0)
        {
            s=ans_arr[i];
            cnt++;
            continue;
        }
        if(s!=ans_arr[i])
        {
            printf("%d %d\n",s,cnt);
            s=ans_arr[i];
            cnt=1;
        }
        else if(s==ans_arr[i])
        {
            cnt++;
        }
    }
    printf("%d %d\n",s,cnt);

}
