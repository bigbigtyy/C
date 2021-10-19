#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
#define OK 1

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

void CreateListTail(LinkList *L)
{
    LinkList p,q;
    ElemType e;
     *L=p=NULL;
    while(scanf("%d",&e)==1)
    {
        q=(LinkList)malloc(sizeof(LNode));
        q->data=e;
        if(*L==NULL)
            *L=q;
        else
            p->next=q;
        p=q;
    }
   if(p)
        p->next=NULL;
}

int LengthList_re(LinkList L)
{

LinkList p=L;

int len=0;
while(p!=NULL){
    len++;
    p=p->next;
}
return len;





}

int main()
{
    LinkList L;
    CreateListTail(&L);
    printf("%d\n",LengthList_re(L));
    return 0;
}






