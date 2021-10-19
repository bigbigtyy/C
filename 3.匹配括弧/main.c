#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define STACK_INT_SIZE 10
#define STACKINCREMENT 5
typedef  char ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;

int initStack(SqStack *s);
int emptyStack(SqStack *s);
int pushStack(SqStack *s, ElemType e);
int popStack(SqStack *s,ElemType *e);
int BracketsCheck(SqStack *s,char *str);
//初始化栈
int initStack(SqStack *s)
{
    s->base=(ElemType *)malloc(STACK_INT_SIZE*sizeof(ElemType));
    if(!s->base)
        return ERROR;
    s->top=s->base;
    s->stacksize=STACK_INT_SIZE;
    return OK;




}
//判断栈空
int emptyStack(SqStack *s)
{

    if(s->base==s->top)
        return OK;
    else
        return ERROR;


}
//入栈
int pushStack(SqStack *s, ElemType e)
{
    if(s->top-s->base>=s->stacksize)
    {
        s->base=(ElemType *)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(ElemType));
        if(!s->base)
            return ERROR;
        s->top=s->base+s->stacksize;
        s->stacksize+=STACKINCREMENT;
    }
    *s->top=e;
    s->top++;
    return OK;



}
//出栈
int popStack(SqStack *s,ElemType *e)
{
    if(s->top==s->base)
        return ERROR;
    --s->top;
    *e=*s->top;
    return OK;



}
int BracketsCheck(SqStack *s,char *str){
    ElemType e=0;
    int i=0;
    while(str[i]!='\0'){
    switch(str[i]){
        case '(':pushStack(s,'(');break;
        case '[':pushStack(s,'[');break;
        case '{':pushStack(s,'{');break;

        case ')':popStack(s,&e);
            if(e!='('){printf("not match\n");return 0;}
        break;

        case ']':popStack(s,&e);
            if(e!='[') {printf("not match\n");return 0;}
        break;

        case '}':popStack(s,&e);
            if(e!='{'){printf("not match\n"); return 0;}
        break;

        default:
            break;
            }
            i++;
        }
        if(!emptyStack(s)){
            printf("not match\n");

            return 0;

        }
        else{
            printf("match\n");
            return 1;
        }
    }

int main()
{
    SqStack s;

    char a[100] = {0};

        //补充代码：实现读入数据入栈和出栈
        while(scanf("%s",a)==1)
        {
            initStack(&s);
            BracketsCheck(&s,a);


        }

  return 0;

    }


