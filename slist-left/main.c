
/*1. ˳���Ԫ��ѭ�����ƣ�new��
������������

˳�������N(N>0)��Ԫ�أ���ÿ��Ԫ��ѭ������M(M>=0��Ҳ���ܻ����N)��λ�á�

��˳����������ɣ�a1a2a3...an���任Ϊ��am+1....ana1a2...am����

������ԣ�����ʱ�临�Ӷ�Ϊ��O(n)

��������ʽ��

��һ������N(1<=N<=100)��M��M>=0����

�ڶ�������N��������

�������ʽ��

���˳�����ѭ������Mλ�Ժ��Ԫ�����У�Ԫ��֮��ո�ָ�����

����������1��

8 4

1 2 3 4 5 6 7 8
���������1��

5 6 7 8 1 2 3 4

����������2��

4 6

1 2 3 4
���������2��

3 4 1 2

����������3��

1 0

10
���������3��

10
*/
#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 5
#define INCREM 3
typedef int ElemType;
typedef struct Sqlist{
	ElemType *slist;
	int length;
	int listsize;
}Sqlist;
//��ʼ��
int initSq(Sqlist *L)
{
    L->slist=(ElemType *)malloc(INIT_SIZE*sizeof(ElemType));
    if(L->slist==NULL){
        return 0;
    }
    L->length=0;
    L->listsize=INIT_SIZE;
    return 1;
}
//����Ԫ��
int insertSq(Sqlist *L, ElemType e, int i)
{
    if(i<1||i>L->length+1){
        return 0;
    }
    if(L->length>=L->listsize){
        L->slist=(ElemType *)realloc(L->slist,(L->listsize+INCREM)*sizeof(ElemType));
        if(L->slist==NULL)
            return 0;
        L->listsize+=INCREM;
    }
    int j;
    for(j=L->length-1;j>=i-1;j--){
        L->slist[j+1]=L->slist[j];
    }
    L->slist[i-1]=e;
    L->length++;
    return 1;
}
//ɾ��Ԫ��
int deleteSq(Sqlist *L,int i)
{
    if(i<1||i>L->length)
        return 0;
    int k;
    for(k=i;k<L->length;k++)
    {
        L->slist[k-1]=L->slist[k];
    }
    L->length--;
    return 1;
}
//���˳���
void printSq(Sqlist *L)
{
    int i;
    for(i=0;i<L->length;i++)
    {
        printf("%d ",L->slist[i]);
    }
    printf("\n");
}
//ѭ������
void circleLeft(Sqlist *L, int m)
{
int i;
for(i=0;i<m;i++){
       int x=L->slist[0];
        deleteSq(L,1);
        insertSq(L,x,L->length+1);






}






}
int main()
{
    Sqlist sq;
    ElemType e;
    int n,m;
    if(initSq(&sq)){
       scanf("%d%d",&n,&m);
       while(n--)
       {
            scanf("%d",&e);
            insertSq(&sq,e,sq.length+1);
       }
       circleLeft(&sq,m);
       printSq(&sq);
    }
    return 0;
}






