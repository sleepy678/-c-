#include <stdio.h>
int A(int n,int m)
{
    if (n==1) return 0;
    else return((A(n-1,m)+m)%n);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d\n",A(n,m)+1);
    return 0;
}
//n个人中最终留下来的人可以看作是把第m个人去除后，余下的n-1个人最终留下的人的编号再减去m后的人，因为可能大于n，所以需对n取余 

