#include<stdio.h>          /*标准输入输出 */
#include<stdlib.h>         /*malloc等函数的调用 */

#define LIST_INTI_SIZE 10  /*线性表存储空间的初始分配量 */
#define LIST_INCREMENT 5   /*线性表存储空间的分配增量 */

typedef int ElemType;      /*定义ElemType为int类型 */

typedef struct {
	ElemType *elem;
	int Listsize;          /*线性表的总大小 */
	int length;            /*线性表当前长度 */
}SqList;

/*构建一个空的线性表 */
int InitList(SqList *L){
	L->elem = (ElemType *)malloc(LIST_INTI_SIZE*sizeof(ElemType));
	L->length = 0;
	L->Listsize = LIST_INTI_SIZE;
	printf("InitList finish\n");
	return 0;
} 

/*线性表插入 */
int ListInsert(SqList *L,int i,ElemType e){
	if(i<1||i>L->Listsize){
		printf("Position Error\n");
		return -1;
	}
	if(L->length >= L->Listsize){
		L->elem = (ElemType *)realloc(L->elem,(LIST_INTI_SIZE+LIST_INCREMENT)*sizeof(ElemType));
	}
	if(L->elem == NULL){
		printf("realloc error\n");
		return -1;
	}
	int *p = NULL;
	int *q = NULL;
	p = &L->elem[i-1];
	for(q=&L->elem[L->length-1];q>=p;q--){
		*(q+1) = *(q);
	}
	*p = e;
	L->length++;
	L->Listsize += LIST_INCREMENT;
	printf("Insert completed\n");
	return 0;
}

/*线性表删除 */
int ListDelete(SqList *L,int i,int *e){
	if(i<1||i>L->Listsize){
		printf("postion error");
		return -1;
	}
	int *p = NULL;
	int *q = NULL;
	p = &L->elem[i-1];
	*e = *p;
	q = &L->elem[L->length-1];
	for(p;p<=q;p++){
		*(p)=*(p+1);
	}
	L->length--;
	printf("Delete completed\n");
	return 0;
}

/*线性表打印 */
int PrintList(SqList *L){
	int i;
	for(i=0;i<L->length;i++){
		printf("%d ",L->elem[i]);
	}
	printf("\n");
	return 0;
}

/*线性表...更方便的输入数据吧 */
int DataInput(SqList *L){
	int sum,s,m;
	printf("Please enter the number of elements: ");
	scanf("%d",&sum);
	int a[sum];
	for(s=0;s<sum;s++){
		scanf("%d",&a[s]);
	}
	for(m=1;m<=sum;m++){
		if(!ListInsert(L,m,a[m-1]))
		printf("The %d num %d is inserted into the list\n",m,a[m-1]);
	}
	printf("input over\n");
	return 0;
}

int Length(SqList L){
	return L.length;
}

int LocateElem(SqList L,int e){
	int i;
	for(i=0;i<L.length;i++){
		if(L.elem[i]==e){
			return i+1;
		}
	}
	return 0;
}

int GetElem(SqList L,int i){
	if(i<0||i>L.length){
		printf("position error");
		return -1;
	}
	return L.elem[i-1];
}

int Empty(SqList L){
	if(L.length == 0){
		printf("List is empty \n");
		return 0;
	}
	else{
		printf("List is not empty \n");
		return -1;
	}
}

int DestroyList(SqList *L){
	while(L->elem==NULL){
		free(L->elem);
	}
	L->length = 0;
	printf("destroy finish \n");
	return 0;
}



int main(){
	printf("--------List-order--------\n");
	printf("0.exit                  1.InitList             2.ListInsert(&L,i,e)  \n");
	printf("3.ListDelete(&L,i,&e)   4.PrintList            5.DataInput           \n");
	printf("6.GetElem(L,i)          7.Empty(L)             8.DestroyList(&L)     \n");
	printf("9.Length(L)             10.LocateElem(L,e)     \n");
	printf("\n");
	int n;
	SqList L;
	do
	{
		printf("Please enter the number of the action you want to perform: ");
		scanf("%d",&n);
		switch(n){
			case 1:
				InitList(&L);
				break;
			case 2:
				int i,e;
				printf("Please enter the location and data you want to insert: ");
				scanf("%d %d",&i,&e);
				ListInsert(&L,i,e);
				break;
			case 3:
				int ee;
				printf("Please enter the location you want to delete: ");
				scanf("%d",&i);
				ListDelete(&L,i,&ee);
				printf("delete elem is %d \n",ee);
				break;
			case 4:
				PrintList(&L);
				break;
			case 5:
				DataInput(&L);
				break;	
			case 6:
				int p,num;
				printf("Please enter the position i: ");
				scanf("%d",&p);
				num=GetElem(L,p);
				printf("the element value of the %d position is %d\n",p,num);
				break;
			case 7:
				Empty(L);
				break;
			case 8:
				DestroyList(&L);
				break;
			case 9:
				int l1;
				l1=Length(L);
				printf("the List Length is %d\n",l1);
				break;
			case 10:
				int l,num1;
				printf("Please enter a search element value e: ");
				scanf("%d",&l);
				num1=LocateElem(L,l);
				printf("the position of the value %d is %d \n",l,num1);
				break;
			default:
				break;
		}
	} while (n != 0 );

	return 0;
}