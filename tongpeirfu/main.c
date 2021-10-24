/*1. 具有通配符？的模式匹配算法（BF）
【问题描述】

编写一个具有通配符？的模式匹配算法。?可以与任意一个字符匹配。
【输入形式】

输入主串s；

输入子串t；

输入比较起始位置pos。

【输出形式】

输出匹配结果：子串第一次出现的位置，若未找到，输出0。
【样例输入1】

there are many cats.

?re

1

【样例输出1】

3

【样例输入2】

thsdfiewnjf fsdfdsjewd

f??f

3

【样例输出2】

13*/
#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 100
#define ERROR 0
#define OK 1
typedef struct{
	char *data;
	int length;
	int stringsize;
}SqString;
//串的初始化
int initString(SqString *s)
{

    s->data=(char *)malloc(MAXSIZE* sizeof(char));
    if(!s->data)
    return 0;
    s->length=0;
    s->stringsize=MAXSIZE;

    return 1;





}
//串的复制
int strAssign(SqString *s, char *str )
{


int i=0;
    while(*str)
    s->data[i++]=*str++;
    s->data[i]='\0';
    s->length=i;
    return 1;




}
//带统配符的模式匹配
int indexPattern(SqString *s,SqString *t,int start)
{
    int i=start-1,j=0;
    while(i<s->length&&j<t->length)
    if(s->data[i]==t->data[j]||t->data[j]=='?'){
        i++;
        j++;
    }
    else{
        i=i-j+1;
        j=0;
    }
    if(j>=t->length)
        return i-t->length+1;
    else
        return 0;






}
int main()
{
    SqString s,t;
    int start,m;
    char str[MAXSIZE];
    //以下补充代码实现接收数据，输出结果
    initString(&s);
    initString(&t);
    gets(str);
    strAssign(&s,str);

    gets(str);
    strAssign(&t,str);
    scanf("%d",&start);
    m=indexPattern(&s,&t,start);
    printf("%d",m);







    return 0;
}
