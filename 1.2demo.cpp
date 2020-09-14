#define MAXSIZE 10        //空间初始分配量
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int Status;
typedef int ElemType;     //将元素类型定义为整型
typedef struct {
    ElemType *elem;     //存储空间基址
    int length;		   //当前顺序表中实际元素的个数
    int listsize;	       //当前分配的存储容量
} SqList;

Status  CreatList(SqList &L) {		// 建立有n个元素的顺序表
	int i;
	do {							// 若表的长度输入不合法，则循环输入
		printf("请输入元素个数：");
		scanf("%d", &L.length );
	} while( L.length < 0 || L.length > L.listsize); // 1
	L.elem=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));
	if(!L.elem) return ERROR;
	for(i=0; i<L.length; i++)  {		// 依次输入n个元素
		printf("请输入第%d个元素值=>", i+1);
		scanf("%d", &L.elem[i]); //2
	}
	return OK;
}

Status  InsertList (SqList &L, int i, int m, ElemType *E) {
// 在顺序表L的第i个位置上插入m个新元素E[]
   if (i<1 || i > L.length+1|| m <1 ) // 进行i、m的合法性判断 // 3
		return  ERROR;
   ElemType  *p;
   int  j;
   if( L.length+m > L.listsize ) {	//若顺序表空间不够，则需扩充空间 //4
      p=(ElemType *)realloc(L.elem, (L.length+m)*sizeof(ElemType));
      if (!p) exit (OVERFLOW);
      L.elem=p;
      L.listsize = L.length+m;
   }
   for(j = L.length-1; j>=i-1; --j) 			// 移动元素
L.elem[j+m]=L.elem[j];
   for(j = 0; j<m; j++)					// 插入元素
L.elem[i+j-1]=E[j];
   L.length =   L.length + m;  // 修改表的长度 //5
   return OK;
}// InsertList 

Status  DeleteList(SqList &L, int x, int y) {
// 在顺序表L中删除其值介于x到y之间的所有元素
		if(x>y) return ERROR;
		int i, j;          // 临时变量j用于当前元素i前移的位置
		for(i=j=0; i<L.length; i++)
			if(L.elem[i]>=x && L.elem[i]<=y)   
	  			j++	; //6
			else
 				L.elem[i-j] = L.elem[i]	;  // 前移j个位置//7
	   	L.length-=j;
    return OK;
}

void PrintList(SqList L)  {		// 输出顺序表中所有元素值
	int i;
		printf("顺序表中有%d个元素：\n", L.length);
	for(i=0; i<L.length; i++)
		printf("%4d",L.elem[i]);
	printf("\n");
}

int main()
{
    SqList  L;
    int  i, m=3;						// 插入点及插入元素个数
    ElemType  E[]={23,24,25};			// 待插入的新元素
    ElemType  x, y;
		printf("(1) 建立有n个元素的顺序表 ……\n");
		if(!CreatList(L)) {printf("创建顺序表失败！\n");  exit(0);}
		printf("当前顺序表如下：\n");
    PrintList(L);

		printf("(2) 在顺序表第i个位置上插入m个新元素……\n");
		printf("请输入插入位置i：");
		scanf("%d", &i);
		if( !InsertList(L, i, m, E) )
			printf("插入失败！\n");
		else {
			printf("插入成功！插入后的顺序表如下：\n");
			PrintList(L);
		}

		printf("(3) 在顺序表中删除其值介于x到y之间的所有元素……\n");
		printf("请输入被删元素下限值x：");
		scanf("%d", &x);
		printf("请输入被删元素上限值y：");
		scanf("%d", &y);
		if(!DeleteList(L, x, y))
			printf("参数错误，删除失败！");
		else {
			printf("删除后的顺序表如下：\n");
    PrintList(L);
}
}

