#include "stdio.h"
void main()
{
    int n;//大厦的宽度 积木的数量
    int hi,hi_pre=0;//第I块最终的高度
    int i;
    int times=0;  //次数
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&hi);
        if(hi>=hi_pre)
        {
            times+=hi-hi_pre;
            hi_pre=hi;
        }
        else
            hi_pre=hi;
    }
    printf("%d",times);
}
