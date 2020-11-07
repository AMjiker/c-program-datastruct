#include<stdio.h>
#define MAX 21
typedef struct {				// 定义Huffman树结点结构
    char data;         		// 结点值
    int weight;        		// 权重
    int parent;        		// 父结点
    int lchild;      			// 左孩子
    int rchild;      			// 右孩子
}HTNode;
typedef struct {     			// 定义Huffman编码结构
    char cd[MAX]; 
    int start; 
}HCode;

void CreatHT(HTNode *HT, int n)
{
	int i,k,l,r;
	int m1, m2;
	int lnode,rnode; 
    for(i=1;i<2*n; i++) 
        HT[i].parent = HT[i].lchild = HT[i].rchild = 0;	// 初始化每一个节点上的值 
    for(i=n+1; i<2*n; i++) {    		// 构造Huffman树
        m1 =m2 = 0x7fff;			// m1取最小权重，m2取次小权重 0x7fff=32767，就相当于是一个极大值 
        lnode = rnode = 0;     		// lnode, rnode分别取两个最小权重的结点位置，分别是极小权重和第二权总 
        for( k=1; k<i; k++) //进去构造每一颗Huffman树 
		{	if(HT[k].parent==0) //双亲结点等于0代表需要重组 ，没有父节点  
			{
				if(HT[k].weight<m1) {//找到权重更小的值 
	                m2 = m1;  rnode=lnode;//把以前权总小的值给第二小的值，节点也更新一下 
					m1 = HT[k].weight;  lnode=k;//1  更新权总 
				}
				else if(HT[k].weight<m2) {//找到权总第二小的值 （比原来第二小的小，但是比第一小的大） 
					m2 =HT[k].weight;//直接更新权重 
					rnode =  k;//2
				}
            }
		}
        HT[lnode].parent = i;//权重最小的作为他的左节点 
		HT[rnode].parent = i;//权重次小的作为右节点 
		HT[i].weight =  m1+m2;//3 这一个节点的总权总 
		//注：左孩子的权总比右孩子小一点 
		//这里每一次的数都有变化，权重最小是相对的，因为权重最小的排列了以后就没有这一项了，因为他的HT[k].parent有值了 
		HT[i].lchild =  lnode;//4 他的左孩子位置 
		HT[i].rchild =  rnode;//4 他的右孩子位置 
    }
}
void CreatHCode(HTNode *HT, HCode *hcd, int n)
{
	int i, f, c;
	HCode hc; //hc存放对应的Huffman编码值 ，这一个是一个temp，临时存放Huffman编码和对应序列 
    for(i=1; i<=n; i++) 
    {
		hc.start = n;//hc.start代表的每一个编码对应的序列，方便循环输出用 ，
		//循环完是一个n-i的数，如何下面的编码也是一个逆序，在输出的时候刚好从n-i到n，
		//这里注释的i指代的是while循环的次数中的遍历次数 
        c = i;//开始处理第几个数据 
        f = HT[i].parent;//找到这个的父节点 
        while( f!=0 ) {
            if(HT[f].lchild == c)  //6 	// c是f的左孩子，编码取'0'，否则取'1'
                hc.cd[--hc.start]='0';
            else
                hc.cd[--hc.start]='1'; 
            c = f;							// 向根结点方向搜索
			f= HT[f].parent;//7  寻找他的下一个父节点，至下而上的寻找 
        }
		hcd[i]= hc;//把这个变量给到存储空间中 
    }
}

void PrintHCode(HTNode *HT, HCode *hcd, int n)
{
	int i,k;
	for(i=1; i<=n; i++) 
	{
		printf("  %c：",HT[i].data);
		for(k=  hcd[i].start; k<n; k++)//8 打印就从每一个Huffman编码中的start中开始到n结束就是每一个编码 
			printf("%c", hcd[i].cd[k]);
		printf("\n");
	}
}

int main()
{
	int i, n;
    HTNode HT[2*MAX-1];
    HCode hcd[MAX];
	printf("(1)创建Huffman树......\n");
	do {
	    printf("  请输入元素个数(1-%d)：", MAX-1);
		scanf("%d", &n);
	} while(n<1||n>MAX-1);	// 确保n值合规
    for(i=1; i<=n; i++) {		// Huffman树结点存放在ht数组从1下标开始的位置
        fflush(stdin);
		printf("  第%d个元素的结点值==>", i);
        scanf("%c",&HT[i].data);
		printf("\t权重==>");
		scanf("%d",&HT[i].weight);
    }
	CreatHT(HT, n);
	printf("  Huffman树创建成功！\n");
    fflush(stdin);
	getchar();
	printf("(2)创建Huffman编码......\n");
	CreatHCode(HT, hcd, n);
	printf("  Huffman编码创建成功！\n");
	getchar();

	printf("(3)输出Huffman编码：\n");
	PrintHCode(HT, hcd, n);
} 
//测试代码 
/*

6
a
7
b
9
c
12
d
22
e
23
f
27



*/

