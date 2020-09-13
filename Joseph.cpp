#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node , *Link;
Link iniNode(int data){
	Node *p;
	p = (Link)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	return p;
}

int printNode(Link head){
	Link cur = head;
	Link temp = head->next;
	int i = 1;
	printf("%d  ",head->data);
	while(temp != head){
		printf("%d  ",temp->data);
		temp = temp->next;
		i++;
	}
	printf("\n"); 
	return i;
} 
void Joseph(int n, int m ,int j){
	int i = 0;
	int k = 0;
	
	Node *head;
	Node *p;
	Link temp;
	head = iniNode(i+1);
	temp = head;
	for(i = 2; i<= n; i++){
		p = iniNode(i);
		temp->next = p;
		temp = temp->next;
	}
	temp->next = head;
	printf("�ܳ���%d \n",printNode(head));
	
	while(head->data != j && j <= n && j!= 0){
		head = head->next; 
	}
	temp = head;
	i = 1;
	while(temp->next != temp){
		if( i == m-1){
			k++; 
			printf("��%d����ɾ��������Ϊ%d\n",k,temp->next->data);
			temp->next = temp->next->next;
			printNode(temp);
			i = 0;
		}
		
		i ++;
		temp = temp->next;
	}
	printf("������µ�����Ϊ:%d",temp->data);
}

int main(){
	int i,j,k;
	printf("������Joseph���������Լ�ÿ�����������Ǹ����˳��Լ��ӵڼ����˿�ʼ\n");
	scanf("%d %d %d",&i,&j,&k);
	Joseph(i,j,k);
	return 0;
}

