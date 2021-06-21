#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#define N 1001

void selection_sort(int array[],int num_size)
{
        int index = 0,i = 0,j = 0,temp = 0;
        for(i = 0;i < num_size-1;i++)
        {
                index = i;
                for(j = i+1;j < num_size ;j++)
                {
                        if(array[index] > array[j])
                        {
                                index = j;
                        }
                }
                if(index != i)
                {
                        temp = array[i];
                        array[i] = array[index];
                        array[index] = temp;
                }
        }
}
void main()
{
    int K;
    int i;
    int num=0;
    int temp=0;
    int flag[N];
    int arr[N];

    while(scanf("%d",&K)!=EOF){
    for(i=0;i<N;i++)
    {
        flag[i]=0;
        arr[i]=0;
    }
    for(i=0;i<K;i++)
    {
        scanf("%d",&temp);
        if(flag[temp]==0)  //输入的不是相同的数字
        {

            arr[num++]=temp;
            flag[temp]=1;
        }
    }
    printf("%d\n",num);
    selection_sort(arr,num);
    for(i=0;i<num-1;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("%d\n",arr[i]);
    num=0;
    }
}
