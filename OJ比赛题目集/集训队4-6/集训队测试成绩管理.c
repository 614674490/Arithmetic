#include "stdio.h"
typedef struct
{
    int ID;
    int sorce;
}STUDENT;

int ctoi(char ch)
{
    switch(ch)
    {
        case '0': return 0;break;
        case '1': return 1;break;
        case '2': return 2;break;
        case '3': return 3;break;
        case '4': return 4;break;
        case '5': return 5;break;
        case '6': return 6;break;
        case '7': return 7;break;
        case '8': return 8;break;
        case '9': return 9;break;
    }
}
int find_max(STUDENT student[],int b,int e)
{
    int max=0;
    int i=0;
    max=student[b].sorce;
    for(i=b+1;i<=e;i++)
    {
        if(student[i].sorce>max)
            max=student[i].sorce;
    }
    return max;
}

void updata_sorce(STUDENT *student,int sorce)
{
    student->sorce=sorce;
}
void cmd_process(STUDENT student[],char cmd[])
{
    if(cmd[0]=='Q')  //查询操作
    {
        printf("%d\n",find_max(student,ctoi(cmd[2]),ctoi(cmd[4])));
    }
    else if(cmd[0]=='U')  //更新操作
    {
        updata_sorce(&student[ctoi(cmd[2])],ctoi(cmd[4]));
    }
}
/**
 *@sample   5 6
            1 2 3 4 5
            Q 1 5
            U 3 6
            Q 3 4
            Q 4 5
            U 2 9
            Q 1 5
*/
void main()
{
    char cmd[6];  //存储命令
    int A,B;
    int i;
    int N,M;      //学生数目 操作数目
    while(scanf("%d",&N)!=EOF){
    scanf("%d",&M);
    STUDENT student[N+1];
    for(i=1;i<=N;i++)
    {
        student[i].ID=i;            //初始化ID和分数
        scanf("%d",&student[i].sorce);
    }
    getchar();
    while(M--)
    {
        gets(cmd);
        cmd_process(student,cmd);
    }
    }
}
