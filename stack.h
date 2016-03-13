//这是一个定义栈的头文件
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
	Elemtype *top;       //指向栈顶的指针
	Elemtype *base;      //指向栈底的指针
	int stackSize;       //栈的最大容量
}sqstack;

void Initstack(sqstack *s)        //为栈申请一段空间
{
	s->base=(Elemtype *)malloc(STACK_INIT_SIZE*sizeof(Elemtype));
	if(!s->base)
	{
		exit(0);
	}

	s->top=s->base;
	s->stackSize=STACK_INIT_SIZE;
}

void Push(sqstack *s,Elemtype el)   //把元素压入栈
{
	if(s->top - s->base>=s->stackSize)
	{
		s->base=(Elemtype*)realloc(s->base,(s->stackSize+STACKCREMENT)*sizeof(Elemtype));  //增大栈的空间
		if(!s->base)
		{
			exit(0);
		}
	}
	*s->top=el;
	s->top++;
}

void Pop(sqstack *s,Elemtype *el)    //把元素弹出栈
{
	if(s->top==s->base)
	{
		return;
	}
	s->top--;
	*el=*(s->top);
}

int stackLen(sqstack s)         //返回栈的长度
{
	return (s.top - s.base);
}

