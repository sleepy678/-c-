#include <stdio.h>
void Stu(float A[5][5],int n);
int main()
{
	int i,j,n;
	float A[5][5];
	printf("Please enter matrix size n(1<=n<20):");
	scanf("%d",&n);
	printf("Please input matrix line by line:\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%f",&A[i][j]);
		}
	}
	printf("matrix a:\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%6.1f\t",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	Stu(A,n);
}
void Stu(float A[5][5],int n)
{
	int a,i,j,count,f;
	float sum=0,B[4],C[3];
	for (a=0;a<n;a++)
	{
		count=0;
		printf("Submatrix:\n");
		for (i=0;i<n;i++)
		{
			if (i==0) continue;
			for (j=0;j<n;j++)
			{
				if (j==a) continue;
				printf("%6.1f\t",A[i][j]);
				B[count]=A[i][j];
				count++;
			}
			printf("\n");
		}
		C[a]=B[0]*B[3]-B[1]*B[2];
		printf("DValue of the Submatrix is %6.1f\n",C[a]);
	}
	for (a=0;a<n;a++)
	{
		if (a%2==0) f=1;
		else f=-1;
		sum+=A[0][a]*C[a]*f;
	}
	printf("result = %f\n",sum);	
}
