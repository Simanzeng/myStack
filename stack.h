//����һ������ջ��ͷ�ļ�
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

#define STACK_INIT_SIZE 20
#define STACKCREMENT 10

using namespace std;

typedef char Elemtype;
typedef struct
{
	Elemtype *top;       //ָ��ջ����ָ��
	Elemtype *base;      //ָ��ջ�׵�ָ��
	int stackSize;       //ջ���������
}sqstack;

void Initstack(sqstack *s)        //Ϊջ����һ�οռ�
{
	s->base=(Elemtype *)malloc(STACK_INIT_SIZE*sizeof(Elemtype));
	if(!s->base)
	{
		exit(0);
	}

	s->top=s->base;
	s->stackSize=STACK_INIT_SIZE;
}

void Push(sqstack *s,Elemtype el)   //��Ԫ��ѹ��ջ
{
	if(s->top - s->base>=s->stackSize)
	{
		s->base=(Elemtype*)realloc(s->base,(s->stackSize+STACKCREMENT)*sizeof(Elemtype));  //����ջ�Ŀռ�
		if(!s->base)
		{
			exit(0);
		}
	}
	*s->top=el;
	s->top++;
}

void Pop(sqstack *s,Elemtype *el)    //��Ԫ�ص���ջ
{
	if(s->top==s->base)
	{
		return;
	}
	s->top--;
	*el=*(s->top);
}

int stackLen(sqstack s)         //����ջ�ĳ���
{
	return (s.top - s.base);
}

