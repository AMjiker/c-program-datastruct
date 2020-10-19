/*
	Name: 整数四则运算 
	Copyright: 
	Author: AMjieker 
	Date: 20/09/20 21:04
	Description: 可进行整数四则运算，支持括号优先级与符号优先级，目前没有发现bug 
*/


#include<stdio.h>
#include<stdlib.h>

#define size 20
typedef struct stack{
	int *data;
	int top;
} Stack ;
int inistack(Stack *stack);  //初始化栈 
void pushstack(Stack *stack , int n);//压入栈 
int popstack(Stack *stack);//弹出栈 
int printstack(Stack *stack);//输出栈中所有元素 
//int poland(char * s);//逆波兰表达式求值  //不可带括号 
int oper(int a,int b,char c); //进行四则运算 
int emp(Stack *stack);//查看当前栈中顶部元素 
int ischar(char c);//是否是运算符 
int oder(char c);//运算等级优先级谁高 
int polandoper(char *s);//四则运算可带括号运算 
// 2*3+2/4+2
//
int main(){
	
//	Stack stack;
//	char s;
//	int Loop = 1;
//	int n; 
//	inistack(&stack);
//	
//	while(Loop){
//		scanf("%d",&n);
//		if(n == -1) Loop = 0;
//		pushstack(&stack,n);
//		printf("\n");
//		printstack(&stack);
//	}

	while(1){
	char s[100];
	if(s[0] == '#') break;
	gets(s);
	printf("%d \n",polandoper(s)); 
	fflush(stdin);
	}
	 
	return 0;
} 

int inistack(Stack *stack){
	stack->data = (int *)malloc(size*sizeof(int));
	
	stack->top = -1;
	return 1;
}
void pushstack(Stack *stack , int n){
	
	stack->data[++stack->top] = n;
}

int popstack(Stack *stack){
	if(stack->top == -1) return -1;
	int n = stack->data[stack->top];
	stack->top --;
	return n;
}
int emp(Stack *stack){
	if(stack->top >= 0) 
		return stack->data[stack->top];
	else
		return -1; 
}
int printstack(Stack *stack){
	int n = stack->top;
	for(n ; n >= 0; n--){
		printf("%d ",stack->data[stack->top - n]);
	}
}

int ischar(char c){
	return c == '+'||c == '-'||c == '*'|| c == '/';
}

int oder(char c){
	if( c == '+' || c == '-'){
		return 1;
	}else if(c == '*' || c == '/'){
		return 2;
	}else{
		return 0;
	}
}
int oper(int a,int b,char c){
	if(c == '+'){
		return a+b;
	}else if(c == '-'){
		return a-b;
	}else if(c == '*'){
		return a*b;
	}else if(c == '/'){
		return a/b;
	}
}
//3*2+5/4+2-7=
//654+/
//int poland(char *s){ //不太成熟的算法 
//	Stack inter;
//	Stack charter;
//	int a;
//	int b;
//	int number;
//	int mult;
//	char c;
//	int i;
//	inistack(&inter);
//	inistack(&charter);
//	while(1){
//		c = *s++;
//		i = 0;  
//		mult = 10; //乘法倍数 
//		if(ischar(c) ){
//			if(oder(emp(&charter)) < oder(c)){
//				pushstack(&charter,c);
//			}else{
//				while(oder(emp(&charter)) >= oder(c)){
//					a = popstack(&inter);
//					b = popstack(&inter); 				
//					pushstack(&inter,oper(b,a,popstack(&charter)));
//				}
//				pushstack(&charter,c);
//			}
//		}else if(c == '='){
//			break;
//		}else{
//			//2+8*9-4/5+7=
//			number = c-'0'; 
//			while(!ischar(*s) && *s != '='){ //处理多位数 
//				c = *s++;
//				number = number*mult + (c - '0');
//				mult = mult*10;
//			}
//			
//			pushstack(&inter,number);//压入栈中  
//		} 
//	} 
//	while(emp(&charter) != -1){ //处理剩下的数据 
//		a = popstack(&inter);
//		b = popstack(&inter); 				
//		pushstack(&inter,oper(b,a,popstack(&charter)));
//	}
//	return popstack(&inter);
//}

int polandoper(char *s){ //对于一个运算式有括号的处理 
//例如 ： 3+2*(2-8*5)+2= 
	Stack inter;
	Stack charter;
	int a;
	int b;
	int number;
	int mult;
	char c;
	int i;
	inistack(&inter);
	inistack(&charter);
	while(1){
		c = *s++;
		i = 0;  
		mult = 10; //乘法倍数 
		if(ischar(c) || c =='(' || c == ')'){
			if(oder(emp(&charter)) < oder(c)|| c == '('){
				pushstack(&charter,c);
			}else if( c == ')'){
				while(emp(&charter) != '('){
					a = popstack(&inter);
					b = popstack(&inter); 				
					pushstack(&inter,oper(b,a,popstack(&charter)));
				}
				if( emp(&charter) == '(') popstack(&charter);
				
			}else {
				while(oder(emp(&charter)) >= oder(c)){
					a = popstack(&inter);
					b = popstack(&inter); 				
					pushstack(&inter,oper(b,a,popstack(&charter)));
				}
				pushstack(&charter,c);
			}
		}else if(c == '='){
			break;
		}else{
			//2+8*9-4/5+7=
			number = c-'0'; 
			while(!ischar(*s) && *s != '=' && *s != ')'){ //处理多位数 
				c = *s++;
				number = number*mult + (c - '0');
				mult = mult*10;
			}
			
			pushstack(&inter,number);//压入栈中  
		} 
	} 
	while(emp(&charter) != -1){ //处理剩下的数据 
		a = popstack(&inter);
		b = popstack(&inter); 				
		pushstack(&inter,oper(b,a,popstack(&charter)));
	}
	return popstack(&inter);
}
