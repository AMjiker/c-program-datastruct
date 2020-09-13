#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define MAXSIZE 6   		//空间初始分配量，为了检验空间扩展，初值取小一点
#define INCREMENT 10	//空间分配增量
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType *elem;     		//存储空间基址
    int length;		  		//当前顺序表中实际元素的个数
    int listsize;	 			//当前分配的存储容量
} SqList;

Status InitList(SqList &L)		// 初始化顺序表
{
	L.elem=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));
	if(!L.elem)  exit(OVERFLOW);
	L.length=0;
 	L.listsize = MAXSIZE ;
	
	return OK;
}

Status  InsertList (SqList &L, int i, ElemType e) {
//将新元素e插入到顺序表L的第i个位置上
   if (i< 1 || i>L.length + 1)  return  ERROR;
   ElemType  *p;
   int  j;
   if(L.length >= L.listsize) {		//若顺序表已满，则需扩充空间
      p=(ElemType *)realloc(L.elem, (L.listsize+INCREMENT)*sizeof(ElemType));
      if (!p) exit (OVERFLOW);
      L.elem=p;
      L.listsize += INCREMENT;
   }
   for(j = L.length-1; j>=i-1; --j) L.elem[j+1]=L.elem[j];
   L.elem[i-1] = e;			//插入新元素
   L.length++;
   return OK;
}// InsertList 

void PrintList(SqList L)				// 输出顺序表元素
{
    int  i;
    for(i=0; i<L.length; i++)
       printf("%d  ", L.elem[i]);
    printf("\n");
}

int SearchList(SqList L, ElemType e)
// 在顺序表L中查找值为e的第一个元素，查找成功返回元素的位置，失败返回-1
{
    int i;
    for(i=0; i<L.length; i++)
        if(e == L.elem[i])   		// 找到相同的元素，返回位置
           return i;
    return -1;
}

int Del_List1(SqList &L, ElemType e)
// 在顺序表L中删除值为e的第一个元素，删除成功返回元素位置，失败则返回-1
{
    int i, j;
    for(i=0; i<L.length; i++)
        if(L.elem[i] == e)              		// 找到相同的元素
           break;
    if(i<L.length){
        for(j=i; j<L.length -1; j++)			// 删除
		L.elem[j] = L.elem[j+1]; 
        L.length--;
        return i;
}
    return -1;
}

Status  Del_List2(SqList &L, int i, ElemType &e)
// 在顺序表L中删除第i个元素，被删元素用参数e带回
{
     if (i< 1 && i>=L.length) return  ERROR;
	 int  j;
	 e=L.elem[i-1];
     for(j=i; j<L.length; j++) 
 	 	L.elem[j-1] = L.elem[j];
     --L.length;
	 return OK;
}

int main()
{
    SqList  LL;
    ElemType x;
    int r,i;
    printf("(1)初始化顺序表……\n");
    if( !InitList(LL) )  return -1;
    printf("  初始化成功！\n");
    printf("(2)顺序表的插入操作……\n");
    while(1)      
    {
        printf("  输入插入元素的值(0:结束)=>");
        scanf("%d", &x);
        if(x == 0)  
            break;
        printf("    输入插入位置：");
        scanf("%d", &r);
 		InsertList(LL,r,x);
        printf("  线性表输出：");
		PrintList(LL);
    }
    printf("(3)顺序表上的查找操作……\n");
    while(1)      //在顺序表中查找指定值的元素，输出该元素所在位置
    {
    printf("  输入查找元素的值(0:结束)=>");
        scanf("%d", &x);
        if(x==0)
            break;
        r= SearchList(LL,x);
        if(r<0)
            printf("    没找到！\n");
       else
            printf("  有符合条件的元素，位置为：%d\n", r+1);
    }
    printf("(4)顺序表中指定元素值的删除操作……\n");
    while(1)        //在顺序表中删除指定值的元素
    {
    printf("  输入删除元素的值(0:结束)=>");
        scanf("%d", &x);
        if(x==0)
            break;
        r= Del_List1(LL,x);
		if(r<0)
            printf("  没找到\n");
        else {
            printf("  删除成功！被删元素的位置是：%d\n  线性表输出：", r+1);
            PrintList(LL);
        }
    }
    printf("(5)顺序表中指定元素位置的删除操作……\n");
    while(1) 
    {
    	printf("  输入删除元素的位置(0:结束)=>");
        scanf("%d", &r);
        if(r==0)
            break;
        if(!Del_List2(LL,r,i))
            printf("  位置越界!\n");
        else {
            printf("  线性表输出：");
            PrintList(LL);
        }
    }
}

