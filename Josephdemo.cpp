#define OK 1
#define ERROR 0
#include<stdio.h>
#include<malloc.h>
typedef int Status;
typedef struct LNode {
    int no;
    int pass;
    struct LNode *next;
}LNode, *LinkList;

Status CreatJosephus(LinkList &Tail, int n, int M[])    //创建Josephus环（循环单链表）
{
    int i;
    LinkList p, head;
    for(i=1; i<=n; i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
		if(p==NULL)  return ERROR;
		p->no=i;							// 号码从1开始
		p->pass=M[i-1];
		if(i==1) 							// 第1个结点
	    head = p;//1	
		else								// 其余结点
	    Tail->next = p; //2
		Tail=p;
    }
    Tail->next = head;//3 	// 令最后一个结点的指针指向第1个结点构成循环链表
    return OK;
}

Status Josephus(LinkList &Tail, int m)		// 求解Josephus环问题
{
    LinkList q,p=Tail->next, pre=Tail;			// pre始终指向p的直接前驱
    int k;								// 用于报数计数器
    if(m<1)  return ERROR;
    while(p != NULL)//4				// 若还有未出列者循环
    {
		for(k=1; k<m; k++)					// 报数
		{
    		pre = p;//5
    		p=p->next;
		}
		printf("%4d", p->no);				// 出列
		q=p; 
		m=q->pass;						// 将出列者密码重新m
		p=p->next;						// 从出列者下一人开始继续报数
		pre->next = p;			// 修改链指针，从环中删除出列者
		if(p==q)  p=NULL;				// 若是最后一个出列者，置p为空
		free(q);
    }
    printf("\n");
    return OK;
}

void OutputJosephus(LinkList Tail)			// 输出Josephus环
{
    LinkList p=Tail;
    do {
		p=p->next; 
        printf("%d(%d)，", p->no, p->pass);
    } while(p != Tail); //7			// 循环条件为未搜索到表尾
    printf("\n");
}

int main()
{
    int M[]={4,7,14,3,22,1,5,9,11,6,8,2};		// 初始化密码数组
    int n=12;								// 定义Josephus环的长度
    int m=0;								// 初始密码初始化
    LinkList tail=NULL;
    printf("（1）创建Josephus环......\n");
    if(CreatJosephus(tail, n, M))
    {
        printf("（2）当前Josephus环为：");
        OutputJosephus(tail);
        printf("请输入初始密码："); 
        while(m<=0) scanf("%d",&m);		// 密码必须为正数
        printf("（3）Josephus环求解结果为：");
        Josephus(tail, m);
    }
    else
        printf("创建Josephus环失败！\n");
    return 0;
} 
