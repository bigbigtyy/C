/*1. ����ͨ�������ģʽƥ���㷨��BF��
������������

��дһ������ͨ�������ģʽƥ���㷨��?����������һ���ַ�ƥ�䡣
��������ʽ��

��������s��

�����Ӵ�t��

����Ƚ���ʼλ��pos��

�������ʽ��

���ƥ�������Ӵ���һ�γ��ֵ�λ�ã���δ�ҵ������0��
����������1��

there are many cats.

?re

1

���������1��

3

����������2��

thsdfiewnjf fsdfdsjewd

f??f

3

���������2��

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
//���ĳ�ʼ��
int initString(SqString *s)
{

    s->data=(char *)malloc(MAXSIZE* sizeof(char));
    if(!s->data)
    return 0;
    s->length=0;
    s->stringsize=MAXSIZE;

    return 1;





}
//���ĸ���
int strAssign(SqString *s, char *str )
{


int i=0;
    while(*str)
    s->data[i++]=*str++;
    s->data[i]='\0';
    s->length=i;
    return 1;




}
//��ͳ�����ģʽƥ��
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
    //���²������ʵ�ֽ������ݣ�������
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
