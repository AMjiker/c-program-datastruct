#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 100
typedef struct node{
	char data;
	struct node *next;
}Node,*List;
List InitStack(Node *s){
	s=(List)malloc(sizeof(Node));
	s->next=NULL;
	return s;
}
int push(Node *s,char x){
	Node *p;
	Node *q;
	q=(List)malloc(sizeof(Node));
	q->data=x;
	q->next=NULL;
	p=s->next;
	if(p==NULL){
		s->next=q;
		return 0;
	}
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=q;
	return 0;
}
int pop(Node *s,char &x){
	if(s->next == NULL){
		return 0;
	}
	Node *p,*cur;
	p=s->next;
	cur=s;
	while(p->next!=NULL){
		cur=p;
		p=p->next;
	}
	x=p->data;
	cur->next=NULL;
	free(p);
	return 1;
}

int StackEmpty(Node *s){
	if(s->next!=NULL){
		return 1;
	}else{
		return 0;
	}
}
int correct( char *exp, int max )           //配对函数
// 传入参数为表达式和表达式长度，返回1为成功，返回0为错误 
{
    int i, flag = 1;                       // 括号匹配标志，1为匹配
    char e,x;
	Node *S = NULL;
	S=InitStack(S);
    for( i=0; i<max&&flag==1; i++) { //1 //表达式未结束且括号匹配则循环
        x=exp[i];
		if( exp[i]=='('||exp[i]=='['||exp[i]=='{')   // 遇左括号进栈
          push(S,x); //2
        if(x==')'||x==']'||x=='}')              // 遇右括号出栈
        {  if(!pop(S,e)) flag=0;	//3 // 出栈，若出栈出错，则右括号太多，失配!
           else if((x==')'&&e!='(')||(x==']'&&e!='[')||(x=='}'&&e!='{')) flag = 0;//括号不匹配
		}
	}
    if(StackEmpty(S))  // 表达式扫描完毕，若栈非空则左括号太多，失配!
        flag = 0;
    return flag;
}

int main()
{
    char exp[MAXN];                		//定义表达式存储数组
    while( 1 ) {
        printf("请输入表达式，输入0退出：");
        gets(exp);// 从标准输入中读取表达式
		puts(exp);
        if(strcmp(exp,"0")==0)
           break;
        if(correct(exp, strlen(exp))==0)  		//调用匹配函数，判断是否匹配
           printf("表达式内容为：\n%s\n表达式括号不匹配\n", exp);
        else
           printf("表达式括号匹配\n");
    }
}
