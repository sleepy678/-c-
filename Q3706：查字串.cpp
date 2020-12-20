#include <stdio.h>
#include <string.h>
int FindString(char *str,char *sub);
int main()
{
    char A[20],B[20];
    int c=0;
    printf("Please input the first str:");
    scanf("%s",A);
    printf("Please input the second str:");
    scanf("%s",B);
    c=FindString(A,B);
    if (c==0) printf("NO\n");
    else printf("YES\n");
    return 0;   
}
int FindString(char *str,char *sub)
{
    int i=0,j=0,n=0,m=0,count=0,count2=0;
    n=strlen(str);
    m=strlen(sub);
    for (i=0;i<=n-m;i++)
    {   count=0;
        for (j=i;j<m+i;j++)
        {
            if (*(str+j)==*(sub+j-i)) {count++;}
            if (count==m) count2++;
        }
    }
    return count2;
}
