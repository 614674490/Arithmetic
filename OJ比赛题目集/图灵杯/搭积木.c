#include "stdio.h"
void main()
{
    int n;//���õĿ�� ��ľ������
    int hi,hi_pre=0;//��I�����յĸ߶�
    int i;
    int times=0;  //����
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
