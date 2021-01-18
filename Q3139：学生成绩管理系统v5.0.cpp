#include <stdio.h>
#include <string.h>
#define   MAX_LEN  10                	   /* 字符串最大长度 */
#define   STU_NUM 30                       /* 最多的学生人数 */
#define   COURSE_NUM 6                     /* 最多的考试科目数 */
typedef struct student
{
    long num;	/* 每个学生的学号 */
    char name[MAX_LEN];            	/* 每个学生的姓名 */
    float score[COURSE_NUM];	/* 每个学生COURSE_NUM门功课的成绩 */
    float sum;                       /* 每个学生的总成绩 */
    float aver;                   /* 每个学生的平均成绩 */
}STU;
int   Menu(void);
void  ReadScore(STU stu[], int n, int m);
void  AverSumofEveryStudent(STU stu[], int n, int m);
void  AverSumofEveryCourse(STU stu[], int n, int m);
void  SortbyScore(STU stu[],int n,int m,int (*compare)(float a,float b));
int   Ascending(float a, float b);
int   Descending(float a, float b);
void  AsSortbyNum(STU stu[], int n, int m);
void  SortbyName(STU stu[], int n, int m);
void  SearchbyNum(STU stu[], int n, int m);
void  SearchbyName(STU stu[], int n, int m);
void  StatisticAnalysis(STU stu[], int n, int m);
void  PrintScore(STU stu[], int n, int m);
int main()
{
 	int i,j,n,m=3,c;
 	STU stu[30]={
	{11003001,"lisi",{87,82,89},0,0},
	{11003005,"heli",{98,92,90},0,0},
	{11003003,"ludi",{75,78,80},0,0},
	{11003002,"dumo",{48,50,67},0,0},
	{11003004,"zuma",{65,69,72},0,0},
	{11003006,"suyu",{100,95,94},0,0},
	};
 	printf("Input student number(n<=30):\n");
 	scanf("%d",&n);
 	do {
 		c=Menu();
 		switch (c)
 		{
 			case 0:printf("End of program!");break;
 			case 1:ReadScore(stu,n,m);break;
 			case 2:AverSumofEveryCourse(stu,n,m);break;
 			case 3:AverSumofEveryStudent(stu,n,m);break;
 			case 4:printf("Sort in descending order by score:\n");SortbyScore(stu,n,m,Ascending);break;
 			case 5:printf("Sort in ascending order by score:\n");SortbyScore(stu,n,m,Descending);break;
 			case 6:AsSortbyNum(stu,n,m);break;
 			case 7:SortbyName(stu,n,m);break;
 			case 8:SearchbyNum(stu,n,m);break;
 			case 9:SearchbyName(stu,n,m);break;
 			case 10:StatisticAnalysis(stu,n,m);break;
 			case 11:PrintScore(stu,n,m);break;
 			default:printf("Input error!\n");
		 }
	 }while(c);
 	return 0;
 }
 int Menu(void)
 {
 	int a;
 	printf("Management for Students' scores\n");
    printf("1.Input record\n");
    printf("2.Caculate total and average score of every course\n");
    printf("3.Caculate total and average score of every student\n");
    printf("4.Sort in descending order by score\n");
	printf("5.Sort in ascending order by score\n");
	printf("6.Sort in ascending order by number\n");
	printf("7.Sort in dictionary order by name\n");
	printf("8.Search by number\n");
	printf("9.Search by name\n");
	printf("10.Statistic analysis\n");
	printf("11.List record\n");
	printf("0.Exit\n");
	printf("Please Input your choice:\n");
	scanf("%d",&a);
	return a;
 }
 void  ReadScore(STU stu[], int n, int m)
{
	int i,j;
	printf("Input course number(m<=6):\n");
	scanf("%d",&m);
	printf("Input student's ID, name and score:\n");
	for (i=0;i<n;i++)
	{
		scanf("%ld",&stu[i].num);
		getchar();
		gets(stu[i].name);
		for (j=0;j<m;j++)
		{
			scanf("%f",&stu[i].score[j]);
		}
	}
}
void  AverSumofEveryStudent(STU stu[], int n, int m)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			stu[i].sum+=stu[i].score[j];
		}
		stu[i].aver=stu[i].sum/m;
		printf("student %d: sum=%.0f,aver=%.0f\n",i+1,stu[i].sum,stu[i].aver);
	}
	
}
void  AverSumofEveryCourse(STU stu[], int n, int m)
{
	int i,j;
	float sum1[10]={0},aver1[10]={0};
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			sum1[i]+=stu[j].score[i];
		}
		aver1[i]=sum1[i]/n;
		printf("course %d:sum=%.0f,aver=%.0f\n",i+1,sum1[i],aver1[i]);
	}
}
void  SortbyScore(STU stu[],int n,int m,int (*compare)(float a,float b))
{
	int i,j;
	STU temp;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			if ((*compare)(stu[j].sum,stu[j+1].sum)) 
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
	for (i=0;i<n;i++)
	{
		printf("%ld\t%s\t",stu[i].num,stu[i].name);
		for (j=0;j<m;j++)
		{
			printf("%.0f\t",stu[i].score[j]);
		}
		printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
	}
}
int   Ascending(float a, float b)
{
	return a<b;
}
int   Descending(float a, float b)
{
	return a>b;
}
void  AsSortbyNum(STU stu[], int n, int m)
{
	int i,j;
	STU temp;
	printf("Sort in ascending order by number:\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			if (stu[j].num>stu[j+1].num) 
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
	for (i=0;i<n;i++)
	{
		printf("%ld\t%s\t",stu[i].num,stu[i].name);
		for (j=0;j<m;j++)
		{
			printf("%.0f\t",stu[i].score[j]);
		}
		printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
	}
}
void  SortbyName(STU stu[], int n, int m)
{
	int i,j;
	STU temp;
	printf("Sort in dictionary order by name:\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			if (strcmp(stu[j].name,stu[j+1].name)>0) 
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
	for (i=0;i<n;i++)
	{
		printf("%ld\t%s\t",stu[i].num,stu[i].name);
		for (j=0;j<m;j++)
		{
			printf("%.0f\t",stu[i].score[j]);
		}
		printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
	}
}
void  SearchbyNum(STU stu[], int n, int m)
{
	int i,j;
	long num3;
	printf("Input the number you want to search:\n");
	scanf("%d",&num3);
	for (i=0;i<n;i++)
	{
		if (stu[i].num==num3) 
		{
		printf("%ld\t%s\t",stu[i].num,stu[i].name);
		for (j=0;j<m;j++)
		{
			printf("%.0f\t",stu[i].score[j]);
		}
		printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
		break;
	    }
	}
	if (i==n) printf("Not found!\n");
}
void  SearchbyName(STU stu[], int n, int m)
{
	int i,j;
	char a[10];
	printf("Input the name you want to search:\n");
	getchar();
	gets(a);
	for (i=0;i<n;i++)
	{
		if (strcmp(stu[i].name,a)==0)
		{
		printf("%ld\t%s\t",stu[i].num,stu[i].name);
		for (j=0;j<m;j++)
		{
			printf("%.0f\t",stu[i].score[j]);
		}
		printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
	    }
	    break;
	}
	if (i==n) printf("Not found!\n");
}
void  StatisticAnalysis(STU stu[], int n, int m)
{
    int i,j,count[6]={0};
	float aver[6]={0};
	for (i=0;i<m;i++)
	{
		for (j=0;j<6;j++)
		{
			count[j]=0;
		}
		for (j=0;j<n;j++)
		{
			if (stu[j].score[i]<60) count[0]++;
			if (stu[j].score[i]>=60&&stu[j].score[i]<70) count[1]++;
			if (stu[j].score[i]>=70&&stu[j].score[i]<80) count[2]++;
			if (stu[j].score[i]>=80&&stu[j].score[i]<90) count[3]++;
			if (stu[j].score[i]>=90&&stu[j].score[i]<100) count[4]++;
			if (stu[j].score[i]==100) count[5]++;
		}
		for (j=0;j<6;j++)
		{
			aver[j]=(float)count[j]/n;
		}
		printf("For course %d:\n",i+1);
		printf("<60\t%d\t%.2f%%\n",count[0],100*aver[0]);
		for (j=60;j<100;j+=10)
		{
			printf("%d-%d\t%d\t%.2f%%\n",j,j+9,count[(j-60)/10+1],100*aver[(j-60)/10+1]);
		}
		printf("%d\t%d\t%.2f%%\n",100,count[5],100*aver[5]);
	}
}
void  PrintScore(STU stu[], int n, int m)
{
	int i,j;
	STU temp;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			if (strcmp(stu[j].name,stu[j+1].name)>0) 
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
	for (i=0;i<n;i++)
	{
		printf("%ld\t%s\t",stu[i].num,stu[i].name);
		for (j=0;j<m;j++)
		{
			printf("%.0f\t",stu[i].score[j]);
		}
		printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
	}
}
