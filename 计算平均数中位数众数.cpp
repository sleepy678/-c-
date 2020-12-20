#include <stdio.h>
int Mean(int A[],int n);
int Median(int A[],int n);
int Mode(int A[],int n);
void Sort(int A[],int n);
int main()
{
	int A[40],i,j,n=40;
	printf("Input the feedbacks of 40 students:\n");
	for (i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("Mean value=%d\n",Mean(A,n));
	printf("Median value=%d\n",Median(A,n));
	printf("Mode value=%d\n",Mode(A,n));
}
int Mean(int A[],int n)
{
	int i,sum=0;
	for (i=0;i<n;i++)
	{
		sum+=A[i];
	}
	return sum/n;
}
int Median(int A[],int n)
{
	int i,j,temp;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			if (A[j]>A[j+1])
			{
				temp=A[j+1];
				A[j+1]=A[j];
				A[j]=temp;
			}
		}
	}
	if (n%2==0) return (A[n/2-1]+A[n/2])/2;
	else return A[n/2];
}
int Mode(int A[],int n)
{
	int i,j,count[40]={0},max=0,k=0;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (A[i]==A[j]) count[i]++;
		}
	}
	max=count[0];
	for (i=0;i<n;i++)
	{
		if (max<count[i]) {max=count[i];k=i;}
	}
	return A[k];
}
