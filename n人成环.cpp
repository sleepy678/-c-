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
//n�������������������˿��Կ����ǰѵ�m����ȥ�������µ�n-1�����������µ��˵ı���ټ�ȥm����ˣ���Ϊ���ܴ���n���������nȡ�� 

