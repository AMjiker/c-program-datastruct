#include<iostream>
#include<cstdlib>
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


//（1）二叉树结点数据结构
typedef struct BiTNode {  			// 定义树结束结构
    char data; 					// 假定树的元素类型为int
    struct BiTNode *lchild; 			// 左子树
    struct BiTNode *rchild; 		// 右子树
} BiTNode,*BiTree;

//（2）链栈结点数据结构（用于二叉树非递归迭代遍历）

typedef struct Stack{   				// 定义链栈结点结构
    BiTNode *t;   				// 栈结点元素为指向二叉树结点的指针
    int flag;     					// 后序遍历时用到该标志
    struct Stack *next;  			// 栈结点链指针
} Stack, *LinkStack; 

//	（3）链队列数据结构（用于二叉树的层序遍历）

typedef struct QNode{     		// 定义链队列结点结构
    BiTree   t;    				// 链队列结点数据域
    struct QNode  *next;     	// 链队列结点指针域
}QNode, *QueuePtr;

typedef struct {     				// 队列类型
    QueuePtr   front;    		// 队首指针
    QueuePtr   rear;     		// 队尾指针
}LinkQueue;

// ① 进栈函数
void Push(LinkStack &top, BiTree tree) {
// 树结点入栈
    LinkStack p;           			// 工作指针
    p=(Stack *)malloc(sizeof(Stack)); 	// 申请栈结点
    p->t = tree;              			// 根结点进栈
    p->next = top;            			// 新栈结点指向栈顶
    top = p;             				// 栈顶为新结点
}
// ② 出栈函数
void Pop(LinkStack &top, BiTree &tree)
// 出栈，栈内元素赋值给树结点
{
    LinkStack p=top;      				// 工作指针
    if(top == NULL)      				// 空栈
       tree = NULL;
    else {               				// 栈非空
        tree=top->t;      				// 栈顶结点元素赋值给树结点
        top = top->next;    			// 栈顶指向下一个链接，完成出栈
        free(p);        				// 释放栈顶结点空间
    }
}
// ③ 初始化链队列函数
Status InitQueue(LinkQueue &Q) {	
// 创建一个带附加表头结点的空链队列Q
	Q.front= Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)  return ERROR;
	Q.front->next = NULL;
	return  OK;
}
// ④ 进队函数
Status EnQueue(LinkQueue &Q, BiTree e) {
//将元素e插入到带头结点的链队列Q中
 	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)  return ERROR;
	p->t = e;	p->next=NULL;
	Q.rear->next = p;  	Q.rear=p;  
	return  OK;
}
// ⑤ 出队函数
Status DeQueue(LinkQueue &Q, BiTree &e) {
//若队列不空，则队首元素出队列，用e返回其值，返回OK，否则返回ERROR
    QueuePtr p;
	if(Q.rear==Q.front)
       return ERROR;
    p=Q.front->next;
    e=p->t;
    Q.front->next=p->next; 
    if(Q.rear==p)
       Q.rear=Q.front; 
    free(p);
    return  OK;
}
// ⑥先序遍历，递归方法 
void re_PreOrder(BiTNode *tree) {
    if(tree!=NULL) {                		// 不为空子树时递归遍历
		printf("%c ",tree->data);      		// 访问根结点
        re_PreOrder (tree->lchild);    		// 先序遍历左子树
        re_PreOrder (tree->rchild);    		// 先序遍历右子树
    }
}
// ⑦中序遍历，递归方法
void re_MidOrder(BiTNode *tree) {//1        
    // 请编写中序遍历子程序
	if(tree!=NULL){
		re_MidOrder(tree->lchild);
		printf("%c ",tree->data);
		re_MidOrder(tree->rchild);
	}
}
// ⑧后序遍历，递归方法
void re_PostOrder(BiTNode *tree) {
    if(tree!=NULL) {                 		// 不为空子树时递归遍历
        re_PostOrder (tree->lchild);    		// 先后序遍历左子树
        re_PostOrder (tree->rchild);    		// 再后序遍历右子树
		printf("%c ",tree->data);       		//  最后访问根结点
    }
}
// ⑨先序遍历，采用链栈的迭代方法
void st_PreOrder(BiTNode *tree)
{	/*
    LinkStack top;             			// 栈顶指针
	top=NULL;              				// 初始化为空栈
    while(tree!=NULL) {       			// 二叉树还未遍历完
        Push(top,tree); 	//2	// 访问根结点
        if(tree->rchild!=NULL) 	//3	// 右子树结点入栈
			Push(top, tree->rchild);
		if(tree->lchild!=NULL)  			// 左子树结点入栈
			Push(top,tree->lchild); //4
        Pop(top, tree); 	// 树结点出栈
    }
    */
    LinkStack top;             			// 栈顶指针
	top=NULL;
	BiTNode *p=tree;              				// 初始化为空栈
    while(p!=NULL) {       			// 二叉树还未遍历完
        Push(top,p); 	//2	// 访问根结点
        if(p->rchild!=NULL) 	//3	// 右子树结点入栈
			Push(top, p->rchild);
		if(p->lchild!=NULL)  			// 左子树结点入栈
			Push(top,p->lchild); //4
        Pop(top, p); 	// 树结点出栈
        
    }
}
// ⑩中序遍历，采用链栈的迭代方法
void st_MidOrder(BiTNode *tree)
{
    LinkStack top;            				// 栈顶指针
    top = NULL;              			// 初始化为空栈
    while(tree!=NULL&&top!=NULL){ 	//5	// 循环条件为二叉树还未遍历完，或栈非空
        while(tree!=NULL) {  				// 二叉树还未遍历完
            Push(top, tree);  				// 树结点入栈
			tree=tree->lchild; 	//6	// 沿左子树前进，将经过的结点依次进栈
        } 
        if(top!=NULL){   				// 左子树点入栈结束，且栈非空
            Pop(top, tree);  				// 树结点出栈
			printf("%c ",tree->data); 	//7	// 访问根结点
			tree=tree->rchild; 	//8	// 向右子树前进
        }
    }
}
// ○11后序遍历，采用链接栈的送代方法
void st_PostOrder(BiTNode *tree)
{
	LinkStack top;    						// 栈顶指针 
	top=NULL;   						// 初始化为空栈
	do {
		while(tree!=NULL) { //9	// 二叉树还未历完 
			Push(top, tree);    			// 树结点人栈
			top->flag = 0;      			// 标志为0，表示右子树未访问。
			Push(top,tree->lchild);	//10	// 沿左子树前进，将经过的结点依次进栈
		}
		if(top!=NULL) {     				// 栈非空 
			while(top!=NULL&& top->flag == 1){  //11 // 右子树已访问
				Pop(top, tree);    			// 出栈
				printf("%c ", tree->data);
			}
			if(top!=NULL) {
				top->flag=1; //12	// 置右子树为访问标志
				tree = (top->t)->rchild; 		// 查找栈顶无素的右子树
			}
		}
	} while(top!=NULL);      				// 循环条件为栈非空
}
// ○12二叉树的层序遍历
void LevelOrder(BiTNode *root) {			
	LinkQueue Q;
	BiTree p;
   if (root !=NULL) {
      InitQueue(Q);
      EnQueue(Q,root);
      while(Q.front==Q.rear)  { //13	// 循环条件为队非空
          DeQueue(Q,p);
          printf("%c ", p->data);
          if(p->lchild!=NULL) EnQueue(Q, p->lchild);
          if(p->rchild!=NULL) EnQueue(Q, p->rchild);
      }  //While
	  printf("\n");
   }   //if
}  //LevelOrder 

// ○13创建二叉树
void CreateBiTree(BiTree &T)             		
{  // 先序递归遍历方式创建一棵二叉树
    char ch; 
    scanf("\n%c",&ch);     								// 输入根结点的值
    if (ch =='#') 											// 终止项
        T = NULL; 
    else
    { 
        T = (BiTree)malloc(sizeof(BiTNode)); 				// 创建根结点
        if (!T) 
            exit(-1); 
        T->data = ch; 
        printf("\n请输入%c结点的左子结点(#表无):",T->data ); // 先序遍历创建左子树
        CreateBiTree(T->lchild); 
        printf("\n请输入%c结点的右子结点(#表无):",T->data ); // 先序遍历创建右子树
        CreateBiTree(T->rchild); 
    }     
}

//○14以括号表示格式输出二叉树
void OutputBiTree(BiTree T)
{		// 先序递归遍历方式输出括号表示的二叉树
	if(T!=NULL)									// 终止项
	{
		printf("%c", T->data);						// 访问根结点
		if(T->lchild!=NULL||T->rchild!=NULL)
		{
			printf("(");							// 根的孩子用圆括号对括
			OutputBiTree(T->lchild);				// 先序遍历输出左子树
			if(T->rchild!=NULL)
				printf("，");						// 根的左右孩子以"，"分隔
			OutputBiTree(T->rchild);				// 先序遍历输出右子树
			printf(")");							// 根的孩子用圆括号对括
		}
	}
}
int main(){
	BiTNode *proot;        				// 定义树
    proot=NULL;      					// 初始化为空树
	printf("请输入根结点元素(#表无):");
	CreateBiTree(proot);     	//14		// 创建二叉树
	printf("\n(1)二叉树创建成功，其括号表示格式输出：\n\t");
	OutputBiTree(proot);

	printf("\n(2)先序遍历，递归方法\n\t");
	re_PreOrder(proot);      //15			// 先序遍历，递归方法

	printf("\n(3)中序遍历，递归方法\n\t");
	re_MidOrder(proot);      		//16	// 中序遍历，递归方法

	printf("\n(4)后序遍历，递归方法\n\t");
	re_PostOrder(proot);   	//17		// 后序遍历，递归方法

	printf("\n(5)先序遍历，链接栈的迭代方法\n\t");
	st_PreOrder(proot);  		//18		// 先序遍历，采用链接栈的迭代方法

	printf("\n(6)中序遍历，链接栈的迭代方法\n\t");
	st_MidOrder(proot);  //19  			// 中序遍历，采用链接栈的迭代方法

	printf("\n(7)后序遍历，链接栈的迭代方法\n\t");
	st_MidOrder(proot);      	//20		// 后序遍历，采用链接栈的迭代方法
	
printf("\n(8)层序遍历，链队列的迭代方法\n\t");
	LevelOrder( proot );       				// 后序遍历，采用链接栈的迭代方法
}
 
