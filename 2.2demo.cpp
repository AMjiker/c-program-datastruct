#define OK 1
#define ERROR 0
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

typedef int status;
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

void CreateList(LinkList &L,int n){
// 采用有序插入法建立一个带附加表头结点且长度为n的有序(升序)单链表L
	int i;
LNode *p,*q, *s;
	L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
	for(i=0;i<n;++i){
        s=( LinkList)malloc(sizeof(LNode));
		printf("请输入第%d个结点值：",i+1);
		scanf("%d", &s->data);
		p=L;
		q=L->next;
        while(q != NULL && q->data <= s->data) {  //1 	//定位指针q指向插入点
		    p = q;  	//2		//p为q的直接前驱
            q=q->next;
	    }
	    s->next = p->next; //3            	// 插入新结点
	    p->next=s;
    }
}//CreateList

void Mergesort(LinkList &A,LinkList &B,LinkList &C){
    // 归并两个非递减单链表A、B到C中，且C非递减
    //  A的头结点归并到C中，作为C的头结点
	LNode *pa,*pb, *pc;
    pa=A->next;
    pb = B->next;
    C=pc=A;
	while (pa && pb) {
		if (pa->data <=pb->data) {		// 若A表结点的值更小，取A表的结点到C
 		    pc->next = pa;//4
            pa = pa->next;//5
            pc = pc->next;//6
		}
		else{						// 否则将B表的结点移至C表表尾
		    pc->next = pb;//7
            pb = pb->next;//8
        	pc = pc->next;//9
		}
	} //while
	pc->next = pa?pa:pb;				// 将A表或B表剩余链表接在C表表尾
	free(B);							// 释放B表头结点
} // Mergesort
void OutputList(LinkList L)
// 输出带头结点的单链表中所有结点的键值
{
	LinkList p=L->next;
	while(p != NULL) { //10
		printf("%d→",p->data);
		p=p->next;       			// 遍历下一个结点
	}
    printf("∧\n");
}

int main(){
	LinkList La,Lb,Lc;
	int  na=5, nb=4;				// A链表5个结点，B链表4个结点
	printf("（1）创建有序单链表A……\n");
	CreateList(La, na);
	printf("A链表输出：");
    OutputList(La);
	printf("（2）创建有序单链表B……\n");
	CreateList(Lb, nb);
	printf("B链表输出：");
    OutputList(Lb);
	printf("（3）归并A、B到C，C链表仍有序……\n");
	Mergesort(La,Lb,Lc);
    printf("C链表输出：");
	OutputList(Lc);
}

