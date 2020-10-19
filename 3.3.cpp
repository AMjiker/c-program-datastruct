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
int emp(Stack *stack);//查看当前栈中顶部元素 
int panlindrome();//回文 
int conversion();

int  bracket();//配对括号 
int isbracket(char s); //判断是否是括号 
int ischar(char s, char c); //判断是不是配对括号 

int insetLine();
int main(){
//	panlindrome();
//	conversion();
//	bracket();
	insetLine();
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

int panlindrome(){
	int n;
	char s[size];
	int i = 0;
	Stack stack;
	inistack(&stack);
	gets(s);
	
	while(s[i]!=0){
		if(s[i] == ' '){
			int j = i;
			while(s[j] != 0){
				s[j] = s[j+1];
				j ++;
			}
			s[j] = 0;
		}
		i ++;
	}
	i = 0;
	while(s[i] != 0){
		pushstack(&stack,s[i]);
		i++;
	}
	i = 0;
	int flag = 1;
	while(s[i] != 0){
		if(s[i] != popstack(&stack)){
			flag = 0;
			break;
		} 
		i++;
	}
	if(flag ==  1) 
		printf("true");
	else
		printf("flase");
	
}

int conversion(){
	int s,r;
	int mult;
	int temp;
	Stack stack;
	inistack(&stack);
	scanf("%d %d",&s,&r);
	while(s){
		temp = s%r;
		s = s/r;
		if(temp > 10) temp = temp-'0'+'A' - 10;
		pushstack(&stack,temp+'0');
	}
	mult = 1;
	temp = 0;
	while(1){
		if((s = popstack(&stack)) == -1){
			break;
		}
		
		printf("%c ",s);
	}
}


int  bracket(){
	char s[size];
	gets(s);
	Stack stack;
	inistack(&stack);
//	int flag = 1;
	
	int i = 0;
	while(s[i] != 0){
		if(isbracket(s[i])){
			pushstack(&stack,s[i]);
		}else{
			if(ischar(emp(&stack),s[i])){
				popstack(&stack);
			}else{
				pushstack(&stack,s[i]);
			}
		}
		i++;
	}
	
	if(emp(&stack) != -1){
		printf("false");
	}else{
		printf("true");
	}
}
int isbracket(char s){
	return s=='('||s=='{'||s=='[';
}

int ischar(char s, char c){
	int flag = 0;
	if(s == '{' && c == '}'){
		flag = 1;
	}else if(s == '(' && c == ')'){
		flag = 1;
	}else if(s == '[' && c == ']'){
		flag = 1;
	}
	return flag;
}

int insetLine(){
	Stack s;
	inistack(&s);
	Stack p;
	char c = ' ';
	c = getchar();
	while(c != '^'){
		inistack(&p);
		do{
			if(c == '#'){
				popstack(&s);
			}else if(c == '@'){
				
				while(emp(&s) != -1){
//					pushstack(&p,popstack(&s));
					popstack(&s);
				}
				
			}else{
				pushstack(&s,c);
			}
		}while((c = getchar()) != '\n' && c != '^');
		while(emp(&s) != -1){
					pushstack(&p,popstack(&s));
//					popstack(&s);
				}
		while(emp(&p)!=-1){
			printf("%c",(char)popstack(&p));
		}
		printf("\n");
		c = getchar();
	}
	
} 
