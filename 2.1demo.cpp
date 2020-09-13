#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FLASE 0
#include<stdio.h>
#include<stdlib.h>

#include<malloc.h>
typedef int Status;
typedef int ElemType;

typedef struct LNode{
		ElemType  data;	       //数据域
		struct LNode *next;       //指针域
}LNode, *LinkList;

Status  CreatLinkL1(LinkList  &L, int n, ElemType *E) {
//用表头插入法逆序建立带头结点的单链表
	int i;
	LinkList p;
	L = (LinkList) malloc(sizeof(LNode));
	if(!L)  return ERROR;
	L->next = NULL;				//建立头结点，假定与元素结点结构相同
	for (i = n-1; i>= 0; --i) 	 					//从后向前输入元素 
	{
		if(!(p=(LinkList)malloc(sizeof(LNode))))	//生成新结点
			return ERROR;
	    p->data=E[i];
	    p->next = L->next;  //1
		L->next = p;  		//2		//新结点插入到表头
		;  
	}
	return OK;
}

Status  CreatLinkL2(LinkList  &L, int n, ElemType *E) {
//用表尾插入法建立带头结点的单链表
	int i;
	LinkList p, r;
	L = (LinkList) malloc(sizeof(LNode));
	if(!L)  return ERROR;
	r=L;										//初始化尾指针
	for (i = 0; i<n; i++) 	 			
	{
		if(!(p=(LinkList)malloc(sizeof(LNode))))	//生成新结点
			return ERROR;
	    p->data=E[i];
	    r->next = p;  	//3			//新结点插入到表尾
		r = r->next;   //4
	}
	r->next=NULL;
	return OK;
}

Status  InsertLinkL(LinkList &L, int i, ElemType e) {
    //在带头结点的单链表L中第i个位置之前插入元素e 
    LinkList  s,  p=L;
	int  k=0;           				//初始化，p指向头结点，k为计数器
    while (p->next!=NULL && k<i-1) {  //定位指针p指向第i-1个元素或p为空
        p=p->next;
		++k;
    }
     if(!p->next||k>i-1)  return ERROR; 		//定位插入点失败
     if(!(s=(LinkList)malloc(sizeof(LNode)))) 	//申请元素e的结点空间 
	 		return  OVERFLOW;      	//内存无空闲单元，无法申请到空间 
     s->data=e;
      s->next = p->next; 	   	//5		// 将新结点s插入到链表中 
      p->next = s;			//6
     return  OK;
} // InsertList1 

Status  Del_LinkL1(LinkList L, int i, ElemType &e)    {
//在带头结点的单链表L中，删除第i个元素，并由e返回其值
	int k=0;			//初始化，p指向头结点，k为计数器
	LinkList q, p=L;
    while(p->next!=NULL && k<i-1) {    
        							//逐一移动指针p，直到p指向第i-1个结点或p为空
	p=p->next;  ++k;
     }
    if(!p->next||k>i-1)  return  ERROR;      //无法删除 
    q=p->next;  	    			// 令q指向待删除的元素结点； 
    p->next = q->next; //7 			// 将q结点从链表中删除
    e=q->data;  free(q); 
    return  OK;
}

Status  Del_LinkL2(LinkList &L, ElemType  e)
// 在带头结点的单链表中删除键值为e的结点，成功返回OK，失败返回ERROR
{
	LinkList p, q;    				// p为被删结点前驱，q为被删除结点
	p=L;
	q=L->next; 
	while(q->data != e && p->next !=NULL) { // 8	//定位指针q指向被删结点
		p=q;
		q=q->next;
	}
	if(q==NULL)   				// 链表为空
		return ERROR;
    p->next=q->next ;   			// 被删结点从链表中脱离
	free(q);        				// 释放被删除结点的空间
	return OK;          			// 删除成功
}

Status  Del_LinkL3(LinkList &L, ElemType  e)
// 在带头结点的单链表L中删除键值为e的所有结点，
// 成功返回TRUE，没找到返回FLASE 
{
	LinkList p, q;  				// p为被删结点前驱，q为被删除结点
	int tag=FLASE;
	p=L;
	q=L->next; 
	while(q!=NULL)  {				//定位指针q指向被删结点
		if(q->data==e)
		{	
			p->next = q->next;	//9	// 让q结点从链表中脱离
			free(q);  tag=TRUE;
		}
		else
			p=q;
		q=p->next;
	}
	return tag; 
}
void PrintLinkL(LinkList L)
// 输出带头结点的单链表中所有结点的键值
{
	LinkList p=L->next;
	while(p) {
		printf("%d→", p->data);
		p=p->next;                	// 遍历下一个结点
	}
	printf("∧\n");
}
void FreeLinkL(LinkList &L)
// 释放带头结点的链表空间（含头结点）
{
	LinkList p, q;
	p=L;
	while(p!=NULL) {
	    q = p; //10
		p=p->next;
	    free(q) ; 
	} 
	L=NULL;  					// 将链表头指针置空
}

int main()						//  主函数。
{
	ElemType  E[]={34,12,45,64,28,36,45,56};		// 准备线性表
	int  i, n=8;
	LinkList  head;
	ElemType  rc;
	printf("(1)表头插入法创建单链表……\n");
    if(!CreatLinkL1(head, n, E)) {
		printf("  内存空间不够，创建失败！\n");
		return 0;
    }
	else {
		printf("  创建完成。链表输出：");
	    PrintLinkL(head);
	}
	printf("(2)表尾插入法创建单链表……\n");
	FreeLinkL(head);
    if(!CreatLinkL2(head, n, E)) {
		printf("  内存空间不够，创建失败！\n");
		return 0;
    }
	else {
		printf("  创建完成。链表输出：");
	    PrintLinkL(head);
	}
	printf("(3)指定位置插入……\n");
	printf("  输入插入位置和新元素值==>");
	scanf("%d%d", &i, &rc);
    if(!InsertLinkL(head, i, rc)) 
		printf("  参数错误或内存空间不够，插入失败！\n");
	else {
		printf("  插入成功！链表输出：");
		PrintLinkL(head);
	}
	printf("(4)删除指定位置结点……\n");
	printf("  输入被删结点位置==>");
	scanf("%d", &i);
    if(!Del_LinkL1(head, i, rc)) 
		printf("  参数错误，删除失败！\n");
else {
		printf("  删除成功！被删结点键值是：%d\n  链表输出：", rc);
    PrintLinkL(head);
	}
	printf("(5)删除指定值结点……\n");
	printf("  输入被删结点的键值==>");
	scanf("%d", &rc);
    if(!Del_LinkL2(head, rc)) 
		printf("  输入的键值不存在！\n");
else {
		printf("  删除成功！链表输出：");
    PrintLinkL(head);
	}
	printf("(6)删除指定值所有结点……\n");
	printf("  输入被删结点的键值==>");
	scanf("%d", &rc);
    if(!Del_LinkL3(head, rc)) 
		printf("  输入的键值不存在！\n");
else {
		printf("  删除成功！链表输出：");
    PrintLinkL(head);
	}
	printf("(7)清空链表……\n");
	FreeLinkL(head);
	if(!head)
		printf("  链表已清空\n");
	else
		printf("  清空链表失败！");
}

