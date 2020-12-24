#include <stdio.h>
void Scan(long int A[],float Score[],int n);
void Sum(float Score[],int n);
void Rank(long int A[],float Score[],int n);
void Search(long int A[],float Score[],int n);
void Percent(float Score[],int n);
void Print(long int A[],float Score[],int n);
int main()
{
	long int A[30]={11003001,11003005,11003003,11003002,11003004,11003006};//AÎªÑ§ºÅ 
	float Score[30]={87,98,75,48,65,100};
	int i,j,n=6,choosenum=1;
	printf("Input student number(n<30)\n");
    scanf("%d",&n);
    while(choosenum!=0)
    {
    	printf("Management for Students' scores\n");
        printf("1.Input record\n");
        printf("2.Caculate total and average score of course\n");
        printf("3.Sort in descending order by score\n");
        printf("4.Sort in ascending order by number\n");
        printf("5.Search by number\n");
        printf("6.Statistic analysis\n");
        printf("7.List record\n");
        printf("0.Exit\n");
        printf("Please Input your choice:\n");
        scanf("%d",&choosenum);
        switch(choosenum)
            {
	    case 1:
                Scan(A,Score,n);
                break;
            case 2:
                Sum(Score,n);
                break;
            case 3:
                Rank(A,Score,n);
                break;
            case 4:
            	printf("Sort in ascending order by number:\n");
                Print(A,Score,n);
                break;
            case 5:
                Search(A,Score,n);
                break;
            case 6:
                Percent(Score,n);
                break;
            case 7:
                Print(A,Score,n);
                break;
            case 0:
                printf("End of program!\n");
                break;
            default:
                printf("Input error!\n");
                continue;
        }
    }
}
void Scan(long int A[],float Score[],int n)
{
    int i;
    printf("Input student's ID, name and score:\n");
    for(i=0;i<n;i++)
    scanf("%ld%f",&A[i],&Score[i]);
}
void Sum(float Score[],int n)
{
    int i;
    float total=0,aver=0;
    for(i=0;i<n;i++)
    {
        total+=Score[i];
    }
    aver = total/n;
    printf("sum=%.0f,aver=%.2f\n",total,aver);
}
void Rank(long int A[],float Score[],int n)
{
	int i,j,count[30]={0};
	printf("Sort in descending order by score:\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (Score[i]>=Score[j]) count[i]++;
		}
	}
	 for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (count[j]==n-i)
            {
             printf("%ld\t%.0f\n",A[j],Score[j]);
            }
        }
    }
}
void Search(long int A[],float Score[],int n)
{
	int i,j;
	long int r;
	printf("Input the number you want to search:\n");
	scanf("%ld",&r);
	for (i=0;i<n;i++)
	{
		if (A[i]==r) {printf("%ld\t%.0f\n",A[i],Score[i]);break;}
	}
	if (i==n) printf("Not found!\n");
}
void Percent(float Score[],int n)
{
	int i,D[6]={0};
	for (i=0;i<n;i++)
	{
		if (Score[i]<60) D[0]++;
		else if (Score[i]<70) D[1]++;
		else if (Score[i]<80) D[2]++;
		else if (Score[i]<90) D[3]++;
		else if (Score[i]<100) D[4]++;
		else D[5]++;
	}
	printf("<60\t%d\t%.2f%%\n",D[0],(float)D[0]/n*100);
	for (i=60;i<=90;i+=10)
	{
		printf("%d-%d\t%d\t%.2f%%\n",i,i+9,D[(i-50)/10],(float)D[(i-50)/10]/n*100);
	}
	printf("%d\t%d\t%.2f%%\n",100,D[5],(float)D[5]/n*100);
}
void Print(long int A[],float Score[],int n)
{
	int i,j,count[30]={0};
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (A[i]<=A[j]) count[i]++;
		}
	}
	 for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (count[j]==n-i)
            {
             printf("%ld\t%.0f\n",A[j],Score[j]);
            }
        }
    }
}
