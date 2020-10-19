#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE  100	//栈存储空间初始分配量
#define STACKINCREMENT  10	//栈存储空间分配增量

typedef int status;
typedef char SelemType;
typedef struct{						//顺序栈的定义
    SelemType *base;
    SelemType *top;
    int stacksize;
}SqStack;

int iniStack(SqStack *stack){
	stack->base = (SelemType*)malloc(sizeof(SelemType)*STACK_INIT_SIZE);
	if(stack->base == NULL) return -1;
	stack->top = stack->base;
	stack->stacksize = STACK_INIT_SIZE;
	return 1;
}
int increase(SqStack *stack){
	stack->base = (SelemType *)realloc(stack->base,(stack->stacksize + STACKINCREMENT)*sizeof(SelemType));
	if(stack->base == NULL) return -1;
	stack->top = stack->base + stack->stacksize;
	stack->stacksize = stack->stacksize + STACKINCREMENT;
}
void pushStack(SqStack *stack , SelemType s){
	if(stack->top - stack->base >= stack->stacksize){
		increase(stack);
	}
	*stack->top ++ = s;
}

SelemType popStack(SqStack *stack){
	SelemType s;
	if(stack->top <= stack->base ){
		return -1;
	}
	s = *--stack->top;
	return s;
}


int main(){
	int s,r;
	int mult;
	int temp;
	SqStack stack;
	iniStack(&stack);
	scanf("%d %d",&s,&r);
	while(s){
		temp = s%r;
		s = s/r;
		if(temp > 10) temp = temp-'0'+'A' - 10;
		pushStack(&stack,temp+'0');
	}
	mult = 1;
	temp = 0;
	while(1){
		if((s = popStack(&stack)) == -1){
			break;
		}
		
		printf("%c ",s);
	}
	return 0;
}
