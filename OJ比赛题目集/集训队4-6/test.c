#include "stdio.h"
#include "string.h"
#define INF 1000000
#define MAX_NODE 10
/**
 *@brief 迪杰斯特拉算法求最短路径
 *@param 邻接矩阵 节点个数 起始节点 最短路径数组(保存起始点到各个节点的最短距离)
 *@return 最短距离
 */
void dijkstra(int edges[][MAX_NODE], int numOfVexs, int v,int distance[])
{
    int w=0;
    int i,j;
    int min=INF;
    int index=-1;  //索引顶点
    int st[numOfVexs];
    for(i=0;i<numOfVexs;i++)  //默认为false
    {
        st[i]=0;
    }
    st[v]=1;  //本身不作为自己的索引顶点   为1则表示找到源点到j顶点的最短路径
    if(v<0||v>numOfVexs)
    {
        printf("起始节点越界！\n");
        return ;
    }
    for(i=0;i<numOfVexs;i++)
    {
        for(j=i+1;j<numOfVexs;j++)  //不对重复项进行数据处理 时间复杂度减少一半
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
    //处理从源点到其余顶点的最短路径
    for(i=0;i<numOfVexs;++i)
    {
        min=INF;
        index=-1;
        for(j=0;j<numOfVexs;j++)
        {
            if(st[j]==0)  //未找到最短路径
            {
                if(distance[j]<min)
                {
                    min=distance[j];
                    index=j;
                }
            }
        }
        if(index!=-1)  //找到最短路径
        {
            st[index]=1;  //做标记
        }
        else
            continue;
        //更新当前最短路径与距离
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
    int n,m;   //景点个数 景点之间的线段个数
    int a,b,c; //景点 景点之间线段的长度
    int x,y;   //x y景点求最短距离
    int i,j;

    int distance[MAX_NODE];         //记录源点到各个顶点的最短距离
    int matrix[MAX_NODE][MAX_NODE];       //保存图结构数据
    for(i=0;i<MAX_NODE;i++)        //初始化
    {
        for(j=0;j<MAX_NODE;j++)
        {
            if(j==i)
                matrix[i][j]=0;
            else
                matrix[i][j]=INF;
        }
    }
    //实现多组输入 直至输入ctrl+z
    while(scanf("%d %d",&n,&m)!=EOF){
    while(m--) //两个景点 线段的长度
    {
        scanf("%d %d %d",&a,&b,&c);
        matrix[a-1][b-1]=c;
        matrix[b-1][a-1]=c;    //记录图结构数据

    }
    scanf("%d %d",&x,&y);   //起始点 终止点
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
