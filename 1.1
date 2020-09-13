
/*
1．问题描述
设有线性表（34，12，45，64，28，36，45），采用顺序存储结构。编程实现有关顺序表的下列基本操作：
（1）初始化一个空的顺序表；ok
（2）在顺序表的第i个位置上插入一个新元素；ok
（3）在顺序表中查找指定值的元素位置；ok
（4）删除顺序表中的第i个元素；ok 
（5）删除顺序表中指定值的元素；ok
（6）输出顺序表中的所有元素值。ok
2．基本要求
（1）采用动态分配方式设计顺序表的存储结构；
（2）用反复执行插入操作的方式建立线性表；
（3）每完成一个步骤，必须及时输出顺序表中的所有元素，便于观察操作结果；
（4）完善参考程序，并在参考程序中的下划线处填上适当的语句或文字；
（5）设计测试用例，上机调试、测试完善后的参考程序，保存和打印测试结果，对测试结果进行分析，包括算法效率分析；
*/
/*


1．问题描述
创建一个顺序表，编程实现顺序表的下列基本运算：
（1）在顺序表的第i个位置上插入m个新元素；
（2）删除顺序表中元素值在x到y之间的所有元素。
2．基本要求
（1）采用动态分配方式设计顺序表的存储结构；
（2）插入算法必须考虑存储空间的动态扩充；插入和删除两种算法均必须满足时间复杂度为O(n)，空间复杂度为O(1)；
（3）根据插入和删除的算法分析，请在参考程序中的下划线处填上适当的子句，完善参考程序；
（4）设计测试数据，上机调试、测试参考程序，保存和打印测试结果，对测试结果进行分析，重点分析两种算法的性能是否达到第（2）条的要求。

*/

/*
1．问题描述
编程实现将两个顺序存储的有序线性表归并为一个线性表，归并后的线性表仍然有序，要求同样的数据元素只出现一次。
2．基本要求
（1）设计创建有序顺序表的算法（可采用有序直接插入法）；
（2）设计有序顺序表的归并算法；
（3）设计输出顺序表全部元素的算法；
（4）编写求解归并问题的完整程序，设计好测试用例；
（5）上机调试、测试，记录测试结果，对测试结果进行分析。

*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 10
#define INCREMENT 10

typedef struct{
	int *elem ;	  //数组 
	int length;	  //可变数组长度 
	int listsize; //现在已有数据 
}SqList;


void incrementSq(SqList *q);

SqList newSq(){		//初始化这个线性表结构体，利用memset 
	SqList q;
	q.elem = (int *)malloc(100*sizeof(int)); //malloc分配空间 
	memset(q.elem,0,MAXSIZE*sizeof(int));  //memset初始化地址中的数据 
	q.length = MAXSIZE;
	q.listsize = 0; 
	return q;
}

//void delSq(SqList *q){ // 销毁线性表 
//	
//	free(q->elem);
//	q->length = 0;
//	q->listsize = 0;
//	
//}

//void clearSq(SqList *q){ // 清除线性表 
//
//	memset(q->elem,0,q->length * sizeof(int));
//	q->listsize = 0;
//}

//int emptySq(SqList *q){ //判断线性表是否为空 
//	if(q->elem == NULL){
//		return 0;
//	}else{
//		return 1;	
//	}
//} 



void addSq(SqList *q , int n){
	int i = 0;
	if(q->listsize < q->length){ 
//		q->elem[q->listsize] = n;
//		q->listsize ++;
		while(q->elem[i] ){
			i++;
		}//如果是顺序添加，则找到第一个不为0的位置插入 
		q->elem[i] = n;
		q->listsize ++;
	} else{
		printf("is full"); //现在暂时设置为空，以后把这个设置为自动分配几个空间； 
		incrementSq(q);
		addSq(q,n);
		printf("\nadd size : %d %d \n" , q->length , q->listsize); // 自动增加 INCREMENT个空间 
	} 
}

void printSq(SqList q){
	int i = 0;
	for(i;i<q.listsize-1;i++){
//		if(q.elem[i]) printf("%d ->",q.elem[i]);
		printf("%d |",q.elem[i]);
	}
		printf("%d ",q.elem[i]);
}

void insertSq(SqList *q , int n , int i){
	int j = q->listsize;
	while(i > q->length  || q->listsize + 1 > q->length){
		printf("this i more than q.length \n");	//若插入的位置大于线性表本身长度就报错 
		printf("this q.length %d \n" , q->length);
		incrementSq(q);
	} 
	if(i >= 0){
		if(i > q->listsize ){
			q->elem[i] = n;//如果是插入线性表内，但是却大于当前长度的就直接赋值 
			q->listsize = i;//将最大长度改成i 
		} else {
			do{
				q->elem[j+1] = q->elem[j];
				j--;
			}while(i <= j ); //循环的作用就是将线性表的数据右移，空出i这个位置 
			q->elem[i] = n; 
			q->listsize ++;//线性表的长度要增加 
		}
	}
}

int searchSq(SqList q,int n){
	int i = 0;
	for(i ; i < q.listsize ; i ++){
		if(n == q.elem[i]){
			break;
		}
	}
	return i;
}

void incrementSq(SqList *q){	//自己定义的扩容函数 
	int *p = (int *)malloc(sizeof(int)*(q->length + INCREMENT));
	int *pr = NULL;
	int i = 0;
	memset(p,0,sizeof(int)*(q->length + INCREMENT));
	while( i < q->length){
		p[i] = q->elem[i];
		i ++;
	}
	pr = q->elem;
	q->elem = p;
	free(pr);
	q->length = q->length + INCREMENT;
	
}

int delSq1(SqList *q , int n){
	int i ;
	int e ; 
	i = searchSq(*q,n);
	if(i == -1){
		e = -1;
	}else{
		e = q->elem[i];
	}
	while(i < q->length && i >= 0){
		q->elem[i] = q->elem[i+1];
		i++;
	}
	q->listsize --;
	return e;
}

int delSq2(SqList *q , int i){
	int e;
	if( i >= 0 && i < q->length  ){
		e = q->elem[i];	
	} else{
		e = -1;
	}
	
	while( i < q->length && i >= 0 ){
		q->elem[i] = q->elem[i+1];
		i++; 
	}
	q->listsize --;
	return e;
}


void insertSqs(SqList *q , int m , int i){
	int number = 0;
	int j = 0;
	printSq(*q);
	if( i < 0 || m <= 0){
		exit(0);
	}
	while( i + m > q->length ){
		incrementSq(q);
	}
	for( j = 0;  j < m; j++){
		printf("请输入第%d个数，共%d个数 :",j+1,m);
		scanf("%d",&number);
		
		insertSq(q,number,i+j);
		
	}
}

//void DelSqs(SqList *q , int x, int y){
//	int i = 0;
//	printf("输出删除前的数据\n,删除从%d到%d的数据",x,y);
//	printSq(*q);
//	printf("\n");
//	for(i; i<q->listsize ; i ++){
//		if(q->elem[i] >= x && q->elem[i] <= y){
//			q->elem[i] = 0;
//		}
//	}
//	
//	
//}
void DelSqs(SqList *q , int x, int y){
	int i = 0;
	int j,k;
	printf("输出删除前的数据\n,删除从%d到%d的数据",x,y);
	printSq(*q);
	printf("\n");
	if(x > y){
		printf("error\n");
		exit(0);
		
	}
	for(i; i<q->listsize ; i ++){
		if(q->elem[i] >= x && q->elem[i] <= y){
			printf("找到了值在%d与%d的元素：%d  删除后总长度",x,y,q->elem[i] );
			for(j = i; j < q->listsize ; j++){
				q->elem[j] = q->elem[j+1];
			}
			i --;
			q->listsize --;
			printf("%d \n",q->listsize);
		}
	}
	
	
}
void quick_sort(int arr[] ,int left , int right){
	int l = left;
	int r = right;
	int mid = arr[(left+right) / 2];
	
	
	while(1){
		while(arr[l] < mid){
			l++;
		}
		
		while(arr[r] > mid){
			r--;
		}
		
		if( l >= r) {
			break;
		}
		
		int temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
		
		if(arr[l] == mid){
			l++;
		}
		
		if(arr[r] == mid){
			r--;
		}
	}
	if(l == r){
		l++;
		r--;
	}
	
	if(left < r){
		quick_sort(arr,left,r);
	}
	if(right > l){
		quick_sort(arr,l,right);
	}
}

SqList fusionSq(SqList q1){
	SqList q2 = newSq();
	SqList q = newSq();
	
	int len = 0,k;
	int i;
	int i1 = 0,i2 = 0;
	do{
		scanf("%d",&len);
	}while(len < 0);
	while(len > q2.length){
		incrementSq(&q2);
	}
	for( i =0 ;i<len;i++){
		scanf("%d",&k);
		q2.elem[i] = k;
		q2.listsize ++;
	}
	quick_sort(q2.elem,0,q2.listsize);
	printf("\n"); 
	printSq(q2);
	printf("\n");
	len = q1.listsize + q2.listsize ;
	while(len > q.length){
		incrementSq(&q);
	}
	q.listsize = len;
	i = 0;
	while(i1 < q1.listsize && i2 < q2.listsize){
		if(q1.elem[i1] >= q2.elem[i2]){
			q.elem[i] = q1.elem[i1];
			i1++;
		}else{
			q.elem[i] = q2.elem[i2];
			i2++;
		}
		i++;
	}
	while(i1 < q1.listsize){
		q.elem[i] = q1.elem[i1];
		i1++;
		i++;
	}
	while(i2 < q2.listsize){
		q.elem[i] = q2.elem[i2];
		i2++;
		i++;
	}
	printSq(q);
	
}
int main(){
	int i = 0;
	SqList q = newSq();
	SqList qq = newSq(); 
	int Loop = 1;
	char s;
	int p;
	int n;

	
	while(Loop){
		printf("\t[1] \t addSq\n");
		printf("\t[2] \t insertSq\n");
		printf("\t[3] \t printSq\n");
		printf("\t[4] \t searchSq\n");
		printf("\t[5] \t incrementSq\n");
		printf("\t[6] \t delSq1\n");
		printf("\t[7] \t delSq2\n");
		printf("\t[8] \t insertSqs\n");
		printf("\t[9] \t delSqs\n");
		printf("\t[0] \t quick_sort\n");
		printf("\t[w] \t fusion\n");
		printf("\t[Any] \t EXIT\n");
		
		scanf("%c",&s);
//		if(s == '1'){
//			scanf("%d",&n);
//			addSq(&q,n);
//		}else if(s == '2'){
//			scanf("%d %d",&n,&p);
//			insertSq(&q,n,p);
//		} else if(s == '3'){
//			printSq(q);
//			printf("\n"); 
//		} else {
//			Loop = 0;
//		}
		
		switch(s){
			case '1':
				scanf("%d",&n);
				addSq(&q,n);
				break;
			case '2':
				scanf("%d %d",&n,&p);
				insertSq(&q,n,p);
				break;
			case '3':
				printSq(q);
				printf("\n"); 
				break;
			case '4':
				scanf("%d",&n);
				p = searchSq(q,n);
				printf("%d %d\n",q.elem[p],p);
				break;
			case '5':
				incrementSq(&q);
				printf("%d %d \n",q.length,q.listsize);
				break;
			case '6':
				scanf("%d",&n);
				printf("%d \n",delSq1(&q,n));
				break;
			case '7':
				scanf("%d",&i);
				printf("%d \n",delSq2(&q,i));
				break;
			case '8':
				printf("请输入插入的位置以及插入的个数:"); 
				scanf("%d %d",&i , &n);
				insertSqs(&q,n,i);
				break;
			case '9':
				printf("输入需要删除的数据：");
				scanf("%d %d",&i,&n);
				DelSqs(&q,i,n);
				break;
			case '0':
				quick_sort(q.elem,0,q.listsize);
				break;
			case 'w':
				fusionSq(q);
				break;
			default :
				Loop = 0;
				break;
		}
		printSq(q);
		printf("\n");
		fflush(stdin);
		system("pause");
		system("cls");
		
	}
	
	
	return 0;
}

