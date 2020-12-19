#include <stdio.h>
void result(long int A[],float aver[],int B[],int C[],int D[],int sum[],int n);
void sort(float aver[],int n);
void swap(float *A,float *B);
int main()
{
    int B[40],C[40],D[40],sum[40];
    int i,n;
    float aver[40];
    long int A[40];
    printf("Input the total number of the students(n<40):");
    scanf("%d",&n);
    printf("Input student¡¯s ID and score as: MT  EN  PH:\n");
    for (i=0;i<n;i++)
    {
        scanf("%ld %d %d %d",&A[i],&B[i],&C[i],&D[i]);
    }
    result(A,aver,B,C,D,sum,n);
    return 0;
}
void result(long int A[],float aver[],int B[],int C[],int D[],int sum[],int n)
{
    int i,j,sum1=0,sum2=0,sum3=0;
    int count[40]={0};
    for (i=0;i<n;i++)
    {
        sum[i]=B[i]+C[i]+D[i];
        aver[i]=sum[i]/3.0;
    }
    for (i=0;i<n;i++)
    {
        sum1+=B[i];
        sum2+=C[i];
        sum3+=D[i];
    }
    printf("Counting Result:\n");
    printf("Student¡¯s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (aver[i]>aver[j]) count[i]++;
            if (aver[i]==aver[j]&&i<=j) count[i]++;
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (count[j]==n-i)
            {
        printf("%12ld\t",A[j]);
        printf("%4d\t",B[j]);
        printf("%4d\t",C[j]);
        printf("%4d\t",D[j]);
        printf("%4d\t%5.1f\n",sum[j],aver[j]);
            }
        }
    }
    printf("SumofCourse \t%4d\t%4d\t%4d\t",sum1,sum2,sum3);
    printf("\nAverofCourse\t%4.1f\t%4.1f\t%4.1f\t",(float)sum1/n,(float)sum2/n,(float)sum3/n);
}
void sort(float aver[],int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (aver[j]>aver[j+1]) swap(&aver[j],&aver[j+1]);
        }
    }
}
void swap(float *A,float *B)
{
    float temp;
    temp=*B;
    *B=*A;
    *A=temp;
}
