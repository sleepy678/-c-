#include <stdio.h>
int Max(int A[], int n);
int main()
{
	int A[20],n,i;
	printf("Please input the arraysize\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Please input the %d-th number\n",i);
        scanf("%d",&A[i]);
    }
    printf("values are %d\n",Max(A,n));
	return 0;
}
int Max(int A[], int n)
{
    int max1=0,max2=0,j;
    for(j = 0;j < n;j++)
    {
        max1 += A[j];

        if(max1 > max2)
            max2 = max1;
        else if(max1< 0)
            max1 = 0; 
    }
    return max2; 
} 
