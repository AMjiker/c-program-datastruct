#include<stdio.h>
#include<stdlib.h>
/*
1．问题描述
设有线性表（34，12，45，64，28，36，45，56），采用链式存储结构。编程实现下列有关单链表的基本操作及运算：
（1） 用表头插入法创建单链表；addNode2
（2） 用表尾插入法创建单链表；addNode1
（3） 在单链表的第i个结点前插入一个结点；insertNodei
（4） 删除单链表中第i个结点；delNode
（5） 删除单链表中指定值的结点；delNodeValue
（6） 删除单链表中结点值等于e的所有结点；delNodeValueall
（7） 输出链表元素；printNode
（8） 清空单链表。clearNode
2．基本要求
（1）链表必须带有附加表头结点，设计链表结点的存储结构；
（2）掌握单链表各种基本操作的算法设计方法和技巧，分析各算法的性能；
（3）在参考程序中的下划线处填上适当的语句或文字，完善参考程序；
（4）设计测试用例，上机调试、测试参考程序，打印测试结果，对测试结果进行分析；
（5）每完成一个步骤，必须及时输出链表中的所有元素，便于观察操作结果。
*/
/*
链表的逆转(反转); reverseNode
链表的排序；sortNode 
*/
typedef int ElemType;

typedef struct node{
	ElemType data;  //数据域 
	struct node *next; //指针域 
}LNode , *LinkList;

LinkList newNode(ElemType data){  //初始化这个节点 
	LNode *p;
	p = (LinkList)malloc(sizeof(LNode));
	p->data = data;
	p->next = NULL;
	return p;
}

void addNode0(LinkList head, LinkList p){ //tail _ insert
	LNode *temp ;
	if(head->next == NULL){
		head->next = p;
		return;
	} 
	temp = head->next;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = p;
	
}

void addNode1(LinkList head, LinkList p){ //head _ insert
	LNode *temp;
	if(head->next == NULL){
		head->next = p;
		return;
	}
	temp = head->next;
	head->next = p;
	p->next = temp;
	
} 

void addorderNode(LinkList head , LinkList p){ //order - insert 
	LNode *temp ;
	LNode *cur;
	if(head->next == NULL){
		head->next = p;
		return;
	} 
	temp = head->next;
	cur = head;
	while(1){
		if(temp->next == NULL){
			break;
		}
		
		if(temp->data >= p->data){
			break;
		}
		cur = temp;
		temp = temp->next;
	}
	cur->next = p;
	p->next = temp;
	
}

void printNode(LinkList p){ //print Node
	LinkList temp;
	if(p->next == NULL){
		return;
	}
	
	 temp = p->next;
	
	while(temp != NULL){
		printf("%d ", temp->data);
		if(temp->next!= NULL) printf("->");
		temp = temp->next;
	}
	printf("\n");
}

int lengthNode(LinkList p){ // find the length of the node
	LinkList temp ;
	int i = 0;
	if(p->next == NULL){
		return 0;
	}
	temp = p->next;
	
	while(temp){
		i++;
		temp = temp->next;
	}
	return i;
}

void delNode(LinkList p, int i){ //delete the node with node order i
	int j,k;
	LinkList q;
	LinkList temp;
	if(i <= 0 || i > lengthNode(p)){ //判断是否合法 
		return ;
	}
	if(i == 1){
		temp = p->next;
//		if(p->next != NULL){
//			p->next = temp->next;  //如果是第一个且后面有元素 
//			
//		}else{
//			p->next = NULL; // 如果是第一个且后面无元素 
//		}
		p->next = temp->next;
		free(temp);
		return ;
	} 
	
	j = 1;
	q = p->next;
	temp = p;
	while(j < i){  //移动到第i个元素 
		j++;
		temp = q;
		q = q->next;
	}
	
//	if(q->next != NULL){ //删除元素 
//		temp->next = q->next;
//	}else{
//		temp->next = NULL;
//	}
	temp->next = q->next;
	free(q);
}

void insertNodei(LinkList head , int i, LinkList p){ //insert the node with node order i
	LinkList temp,cur;
	int j = 1;
	if(i< 1 || i>lengthNode(head)+1){ //判断是否合法 
		return;
	}
	
	temp = head->next;
	cur = head;
	
	while(j<i){
		j++;
		cur = temp;
		temp = temp->next;
	}
	
	if(temp!= NULL){ // temp下一个不为空就在temp前插入这个数 
		cur->next = p;
		p->next = temp;
	}else{
		cur->next = p;//temp 为空就是最后一个，末尾加1 
	}
}

int delNodeValue(LinkList head , ElemType n){ //delete the node with node value n
	LinkList temp = head->next;
	LinkList cur;
	if(head->next == NULL) return 0;
	int flag = 0;
	if(temp->data == n){
//		if(temp){
//			head->next = temp->next;
//		}else{
//			head->next = NULL;
//		}
		head->next = temp->next;
		free(temp);
		return;
	}
	while(temp->next != NULL){
		if(temp->data == n){
			flag = 1;
			break;
		}
		cur = temp;
		temp = temp->next;
	}
	
	if(temp->data == n){
		flag = 1;
	}
	if(flag){
		cur->next = temp->next;
		free(temp);
	}
	fflush(stdin);
	return flag;
} 

void delNodeValueall(LinkList head , int n){ // all delete the node wiht node value n
	int i = 0;
	int j = lengthNode(head);
	for(i; i<j ; i++){
		delNodeValue(head,n);	
	}
	
	
}

void clearNode(LinkList head){ //clearNode
	LinkList temp = head->next;
	LinkList p,q;
	p = head->next;
	while(p!=NULL){
		q = p->next;
		p = p->next;
		free(q); 
	}
	head->next = NULL;
	
}

void reverseNode(LinkList head){ //in linklist reverseNode of head _insert
	LNode *temp;
	LinkList cur;
	temp = head;
	head = head->next;
	temp->next = NULL;
	while(head){
		cur = head->next;
		head->next = temp->next;
		temp->next = head;
		head = cur;
	}
	head = temp;
}
void sortNode(LinkList head){  //bobble_sort in the node 
	LinkList temp = head->next;
	LinkList cur ;
	int i = 0;
	int max ;
	int tmp;
	while(temp->next != NULL){
		cur = temp;
		while(cur != NULL){
			if(temp->data >= cur->data){
				tmp = cur->data;
				cur->data = temp->data;
				temp->data = tmp;
			}
			cur = cur->next;
		}
		temp = temp->next;
	}
	
}
LinkList FusionNode(LinkList p1 , LinkList p2){
	LinkList a1,a2;
	LinkList p;
	LinkList temp;
	LNode *head = p1;
	a1 = p1->next;
	a2 = p2->next;
	head->next = NULL;
	p = head;
	while(a1 && a2 ){
		if(a1->data <= a2->data){
			// 
			p->next = a1;
			
			a1 = a1->next;
		}else{
			// 
			p->next = a2;
			a2 = a2->next;
		} 
		p = p->next;
		p->next = NULL;
	}
	if(a1){
		p->next = a1;
	} 
	if(a2){
		p->next = a2;
	}
	return head;
}


int main(){			//test demo
	int i,j,k;
	int n;
	char s;
	int Loop = 1;
	LNode *head;
	LNode *p;
	LNode *head1;
	head = newNode(0);
	head1 = newNode(0); 
	while(Loop){
		printf("\n\t\n\n当前链表长度：%d , 链表为 : \n",lengthNode(head));
		printNode(head);
		
		printf("\n\t[1] \t add tail link list \n");
		printf("\n\t[q] \t add order link list \n");
		printf("\n\t[a] \t add head link list \n");
		printf("\n\t[2] \t print link list \n");
		printf("\n\t[3] \t delete link list \n");
		printf("\n\t[e] \t delete link list of vlaue \n");
		printf("\n\t[d] \t delete link list of vlaue all \n");
		printf("\n\t[4] \t insert link list of i \n");
		printf("\n\t[c] \t clear link list  \n");
		printf("\n\t[r] \t reverse link list  \n");
		printf("\n\t[s] \t sort link list  \n");
		fflush(stdin);
		scanf("%c",&s);
		switch(s){
			case '1':
				scanf("%d",&n);
				p = newNode(n);
				addNode0(head,p);
				break;
			case 'q':
				scanf("%d",&n);
				p = newNode(n);
				addorderNode(head,p);
				break;
			case 'a':
				scanf("%d",&n);
				p = newNode(n);
				addNode1(head,p);
				break;
			case '2':
				printNode(head);
				system("pause");
				break;
			case '3':
				scanf("%d",&i);
				delNode(head,i);
				break;
			case 'e':
				scanf("%d",&n);
				delNodeValue(head,n);
				break;
			case 'd':
				scanf("%d",&n);
				delNodeValueall(head,n);
				break;
			case '4':
				scanf("%d %d",&i,&n);
				p = newNode(n);
				insertNodei(head,i,p);
				break;
			case 'c':
				clearNode(head);
				break;
			case 'r':
				reverseNode(head);
				break;
			case 's':
				sortNode(head);
				break;
			case 'f':
				n = 1;
				printf("输入第二个链表的数据：\n");
				while(n){
					scanf("%d",&n);
					if(n == 0) break;
					p = newNode(n);
					addNode0(head1,p);
				}
				sortNode(head1);
				printf("head数据为：\n");
				printNode(head);
				printf("head1数据为：\n");
				printNode(head1);
				head = FusionNode(head,head1);
				printf("融合后数据为：\n");
				printNode(head);
				system("pause");
				break;	
			default :
				Loop = 0;
				break;
		}
		
		fflush(stdin);
		
		system("cls");
	}
	
	return 0;
} 
