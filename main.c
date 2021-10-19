
/*1. 顺序表元素循环左移（new）
【问题描述】

顺序表中有N(N>0)个元素，将每个元素循环左移M(M>=0，也可能会大于N)个位置。

即顺序表中数据由（a1a2a3...an）变换为（am+1....ana1a2...am）。

如果可以，控制时间复杂度为：O(n)

【输入形式】

第一行输入N(1<=N<=100)、M（M>=0）；

第二行输入N个整数。

【输出形式】

输出顺序表中循环左移M位以后的元素序列（元素之间空格分隔）。

【样例输入1】

8 4

1 2 3 4 5 6 7 8
【样例输出1】

5 6 7 8 1 2 3 4

【样例输入2】

4 6

1 2 3 4
【样例输出2】

3 4 1 2

【样例输入3】

1 0

10
【样例输出3】

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
//初始化
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
//插入元素
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
//删除元素
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
//输出顺序表
void printSq(Sqlist *L)
{
    int i;
    for(i=0;i<L->length;i++)
    {
        printf("%d ",L->slist[i]);
    }
    printf("\n");
}
//循环左移
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






