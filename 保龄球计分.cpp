#include <stdio.h>
int calculate(int a1,int a2,int b1,int b2,int c1,int c2,int j);
int main()
{
    int n,i,j,a1=0,a2=0,b1=0,b2=0,c1=0,c2=0,count10,Rank[20]={0},H=0;
    struct stu{
        int count1[12]={0};//一轮中第一次滚球
        int count2[12]={0};//一轮中第二次滚球
        int score=0;
    }Ball[20];//最大参赛人数20人 
    printf("请输入参赛人数：");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        for(j=0;j<10;j++)
        {
        printf("%d号选手第%d轮第一次滚球次数：",i+1,j+1);
        scanf("%d",&Ball[i].count1[j]);
        if (Ball[i].count1[j]<10)
        {
            printf("%d号选手第%d轮第二次滚球次数：",i+1,j+1);
            scanf("%d",&Ball[i].count2[j]);
        }
        }
        if (Ball[i].count1[9]+Ball[i].count2[9]==10&&Ball[i].count2[9]!=0)
        {
            printf("%d号选手第10轮奖励第一次滚球次数：",i+1);
            scanf("%d",&Ball[i].count1[10]);
        }
        if (Ball[i].count1[9]==10)
        {
            printf("%d号选手第10轮奖励第一次滚球次数：",i+1);
            scanf("%d",&Ball[i].count1[10]);//将奖励滚球当作第11次滚球 
            printf("%d号选手第10轮奖励第二次滚球次数：",i+1);
            scanf("%d",&Ball[i].count1[11]);
        }
    }//读入选手成绩
    for (i=0;i<n;i++)
    {   
    
        for (j=0;j<10;j++)
        {   
		a1=Ball[i].count1[j];a2=Ball[i].count2[j];
		b1=Ball[i].count1[j+1];b2=Ball[i].count2[j+1];
		c1=Ball[i].count1[j+2];c2=Ball[i].count2[j+2];
		printf("%d号选手第%d轮得分:%d\n",i+1,j+1,calculate(a1,a2,b1,b2,c1,c2,j));
        Ball[i].score+=calculate(a1,a2,b1,b2,c1,c2,j);
        }
        printf("%d号选手最终得分：%d\n",i+1,Ball[i].score);
    }//计算选手得分 
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (Ball[i].score<Ball[j].score) Rank[i]++;
            if (Ball[i].score==Ball[j].score&&i<=j) Rank[i]++;
        }
    }//计算名次 
    printf("选手\t得分\t名次\t\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (Rank[j]==i+1)
            {
            	H++;
        printf("%d号选手\t",j+1);
        printf("%4d\t",Ball[j].score);
        printf("%4d\t\n",Rank[j]);
            }
        }
    }//制表 
    return 0;   
}
int calculate(int a1,int a2,int b1,int b2,int c1,int c2,int j)
{
    if (j!=9)
	{
    if (a1==10&&b1==10) return (20+c1);
    else if (a1==10&&b1!=10) return (10+b1+b2);
    else if (a1+a2==10) return (10+b1);
    else return (a1+a2);
    }
    else 
    {
    	return (a1+a2+b1+b2+c1+c2);
	}
}

