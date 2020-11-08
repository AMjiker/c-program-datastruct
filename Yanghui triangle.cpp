#define OK 1
#define ERROR 0
#include<stdio.h>
#include<malloc.h>
typedef int Status;
typedef int QElemType;

typedef struct QNode{  	//链表结点类型
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
  
typedef struct {     		//队列类型
    QueuePtr   front;  	//队头指针
    QueuePtr   rear;  	//队尾指针
}LinkQueue;

Status InitQueue(LinkQueue &Q) {
//构造一个带附加表头结点的空链队列Q
	Q.front= Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)  return ERROR;
	Q.front->next = NULL;
	return  OK;
}

Status EnQueue(LinkQueue &Q, QElemType e){
//将元素e插入到带头结点的链队列Q中
 	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)  return ERROR;
	p->data = e;
	p->next=NULL;
	Q.rear->next=p;  
	Q.rear = p;  
	return  OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e){
//若队列不空，则队首元素出队列，用e返回其值，返回OK，否则返回ERROR
    QueuePtr p;
	if(Q.rear==Q.front)
       return ERROR;
    p=Q.front->next;
    e=p->data;
    Q.front->next=p->next; 
    if(Q.rear==p)
    	Q.rear = Q.front; 
    free(p);
    return  OK;
}

void OutputQueue(LinkQueue Q)
// 输出队列中的所有元素
{
    QueuePtr p;
	p=Q.front->next;
    while(p!=NULL) {
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
    return ;
}

void out_number(int n);
int main(){
	out_number(5);
	return 0;
} 


void out_number(int n){     			// 输出n行杨辉三角	InitQueue(Q);
	QElemType s1=0, s2=1;
	LinkQueue *Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	InitQueue(*Q);
	printf("1\n");
	EnQueue(*Q,s1+s2);
	for(int i=2; i<=n; i++) {
		s1=0;
		for(int j=1;j<=i-1;j++) {
			DeQueue(*Q,s2);
			printf("%d ",s2);
			EnQueue (*Q,s1+s2);
			s1=s2;
		}
		printf("1\n");
		EnQueue (*Q,1+s2);
	}
}

