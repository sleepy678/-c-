#include <stdio.h>
#define MaxSize  100
typedef int DataType;

typedef struct
{
DataType list[MaxSize];
int size;
} SeqList;

void ListInitiate(SeqList *L)/*��ʼ��˳���L*/
{
L->size = 0;/*�����ʼ����Ԫ�ظ���*/
}
 
int ListLength(SeqList L)/*����˳���L�ĵ�ǰ����Ԫ�ظ���*/
{
return L.size;
}

int ListInsert(SeqList *L, int i, DataType x) 
/*��˳���L��λ��i��0 �� i �� size��ǰ��������Ԫ��ֵx*/ 
/*����ɹ�����1������ʧ�ܷ���0*/
{
int j;
if(L->size >= MaxSize)
{
printf("˳��������޷�����! \n");
return 0;
}
else if(i < 0 || i > L->size )
{
printf("����i���Ϸ�! \n");
return 0;
}
else
{ //�˶γ�����һ������
for(j = L->size; j > i; j--) L->list[j] = L->list[j-1];/*Ϊ������׼��*/
L->list[i] = x;/*����*/
L->size ++;/*Ԫ�ظ�����1*/
return 1;
}
}

int ListDelete(SeqList *L, int i, DataType *x)
/*ɾ��˳���L��λ��i��0 �� i �� size - 1��������Ԫ��ֵ����ŵ�����x��*/
/*ɾ���ɹ�����1��ɾ��ʧ�ܷ���0*/
{
int j;
if(L->size <= 0)
{
printf("˳����ѿ�������Ԫ�ؿ�ɾ! \n");
return 0;
}
else if(i < 0 || i > L->size-1)
{
printf("����i���Ϸ�");
return 0;
}
else
{//�˶γ�����һ������

*x = L->list[i];/*����ɾ����Ԫ�ص�����x��*/
for(j = i +1; j <= L->size-1; j++) L->list[j-1] = L->list[j];/*����ǰ��*/
L->size--;/*����Ԫ�ظ�����1*/
return 1;
}
}

int ListGet(SeqList L, int i, DataType *x)
/*ȡ˳���L�е�i������Ԫ�ص�ֵ����x�У��ɹ��򷵻�1��ʧ�ܷ���0*/
{
if(i < 0 || i > L.size-1)
{
printf("����i���Ϸ�! \n");
return 0;
}
else
{
*x = L.list[i];
return 1;
}
}

void MergeList(SeqList La,SeqList Lb,SeqList *Lc)
{
	int i=0,j=0,k=0;
	while (i<ListLength(La)&&j<ListLength(Lb)&&k<MaxSize)
	{
		if (La.list[i]<Lb.list[j]) ListInsert(Lc,k++,La.list[i++]);
		else ListInsert(Lc,k++,Lb.list[j++]);
	}
	while (i<ListLength(La)) ListInsert(Lc,k++,La.list[i++]);
	while (j<ListLength(Lb)) ListInsert(Lc,k++,Lb.list[j++]);
}
int main()
{   
    SeqList myList,myList2,myList3;
    int i , x;
    ListInitiate(&myList);
    ListInitiate(&myList2);
    ListInitiate(&myList3);
    for(i = 0; i < 10; i++) 
    {
    	ListInsert(&myList, i, i+1); 
    	ListInsert(&myList2, i, i*3); 
	}
    ListDelete(&myList, 4, &x);
	for(i = 0; i < ListLength(myList); i++)
	{
	ListGet(myList,i,&x); //�˶γ�����һ������
	printf("%d ", x);
	}
	printf("\n");
	for(i = 0; i < ListLength(myList2); i++)
	{
	ListGet(myList2,i,&x); //�˶γ�����һ������
	printf("%d ", x);
	}
	MergeList(myList,myList2,&myList3);
	printf("\n");
	for(i = 0; i < ListLength(myList3); i++)
	{
	ListGet(myList3,i,&x); //�˶γ�����һ������
	printf("%d ", x);
	}
	return 0;
}
