#include "stdio.h"
#include "string.h"
#define INF 1000000
#define MAX_NODE 10
/**
 *@brief �Ͻ�˹�����㷨�����·��
 *@param �ڽӾ��� �ڵ���� ��ʼ�ڵ� ���·������(������ʼ�㵽�����ڵ����̾���)
 *@return ��̾���
 */
void dijkstra(int edges[][MAX_NODE], int numOfVexs, int v,int distance[])
{
    int w=0;
    int i,j;
    int min=INF;
    int index=-1;  //��������
    int st[numOfVexs];
    for(i=0;i<numOfVexs;i++)  //Ĭ��Ϊfalse
    {
        st[i]=0;
    }
    st[v]=1;  //������Ϊ�Լ�����������   Ϊ1���ʾ�ҵ�Դ�㵽j��������·��
    if(v<0||v>numOfVexs)
    {
        printf("��ʼ�ڵ�Խ�磡\n");
        return ;
    }
    for(i=0;i<numOfVexs;i++)
    {
        for(j=i+1;j<numOfVexs;j++)  //�����ظ���������ݴ��� ʱ�临�Ӷȼ���һ��
        {
            if(edges[i][j]==0)
            {
                edges[i][j]=INF;
                edges[j][i]=INF;
            }
        }
    }
    for(i=0;i<numOfVexs;i++)
    {
        distance[i]=edges[v][i];
    }
    //�����Դ�㵽���ඥ������·��
    for(i=0;i<numOfVexs;++i)
    {
        min=INF;
        index=-1;
        for(j=0;j<numOfVexs;j++)
        {
            if(st[j]==0)  //δ�ҵ����·��
            {
                if(distance[j]<min)
                {
                    min=distance[j];
                    index=j;
                }
            }
        }
        if(index!=-1)  //�ҵ����·��
        {
            st[index]=1;  //�����
        }
        else
            continue;
        //���µ�ǰ���·�������
        for(w=0;w<numOfVexs;w++)
        {
            if(st[w]==0)
            {
                if(edges[index][w]!=INF&&((min+edges[index][w])<distance[w]))
                {
                    distance[w]=min+edges[index][w];
                }
            }
        }

    }
}
int main()
{
    int T;
    int n,m;   //������� ����֮����߶θ���
    int a,b,c; //���� ����֮���߶εĳ���
    int x,y;   //x y��������̾���
    int i,j;

    int distance[MAX_NODE];         //��¼Դ�㵽�����������̾���
    int matrix[MAX_NODE][MAX_NODE];       //����ͼ�ṹ����
    for(i=0;i<MAX_NODE;i++)        //��ʼ��
    {
        for(j=0;j<MAX_NODE;j++)
        {
            if(j==i)
                matrix[i][j]=0;
            else
                matrix[i][j]=INF;
        }
    }
    //ʵ�ֶ������� ֱ������ctrl+z
    while(scanf("%d %d",&n,&m)!=EOF){
    while(m--) //�������� �߶εĳ���
    {
        scanf("%d %d %d",&a,&b,&c);
        matrix[a-1][b-1]=c;
        matrix[b-1][a-1]=c;    //��¼ͼ�ṹ����

    }
    scanf("%d %d",&x,&y);   //��ʼ�� ��ֹ��
    dijkstra(matrix,n,x-1,distance);
    if(distance[y-1]!=INF)
    {
        printf("%d\n",distance[y-1]);
    }
    else
    {
        printf("unreachable\n");
    }
    }
    return 0;
}
