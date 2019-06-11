#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d",&x);
    while(x!=999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}

LinkList List_TailInsert(LinkList &L){
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s;
    LNode *r = L;
    scanf("%d",&x);
    while(x!=999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}

LNode *GetElem(LinkList L,int i){
    int j=1;
    LNode *p = L->next;
    if(i==0)
        return L;
    if(i<1)
        return NULL;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList L,int e){
    LNode *p=L->next;
    int j=1;
    while(p!=NULL&&p->data!=e){
        p=p->next;
        j++;
    }
    printf("the position of the value %d is %d \n",e,j);
    return p;
}

int Length(LinkList L){
    int count=0;
    LNode *p=L;
    while(p->next!=NULL){
        p=p->next;
        count++;
    }
    return count;
}

int PrintList(LinkList L){
    int i;
    LNode *p = L->next;
    for(i=0;i<Length(L);i++){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int InsertNode(LinkList &L,int i,int e){
    LNode *p;
    LNode *s;
    s=(LNode*)malloc(sizeof(LNode*));
    s->data = e;
    p = GetElem(L,i-1);
    s->next=p->next;
    p->next=s;
}

int DeleteNode(LinkList &L,int i){
    LNode *p;
    LNode *q;
    p=GetElem(L,i-1);
    q=p->next;
    p->next = q->next;
    free(q);
}

int main(){
    printf("---------List-chain---------\n");
    printf("0.exit      1.List_HeadInsert   2.List_TailInsert \n");
    printf("3.GetElem   4.LocateElem        5.PrintList       \n");
    printf("6.Length    7.InsertNode        8.DeleteNode      \n");
    printf("\n");
    int n;
    LinkList L;
    do{
        printf("Please enter the number of the action you want to perform: ");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("(Enter 999 to end the input!)\n");
                List_HeadInsert(L);
                break;
            case 2:
                printf("(Enter 999 to end the input!)\n");
                List_TailInsert(L);
                break;
            case 3:
                printf("Please enter the position i: ");
                int g;
                LNode *v;
                scanf("%d",&g);
                v=GetElem(L,g);
                printf("the element value of the %d position is %d\n",g,v->data);
                break;
            case 4:
                int l;
                LNode *v1;
                printf("Please enter a search element value e: (NOTE:HEAD OR TAIL!)");
                scanf("%d",&l);
                v1 = LocateElem(L,l);
                break;
            case 5:
                PrintList(L);
                break;
            case 6:
                int sum;
                sum=Length(L);
                printf("The length of the liner table is %d\n",sum);
                break;
            case 7:
                int in;
                int ee;
                printf("Please enter the node to insert: ");
                scanf("%d %d",&in,&ee);
                InsertNode(L,in,ee);
                break;
            case 8:
                int out;
                printf("Please enter the node to delete: ");
                scanf("%d",&out);
                DeleteNode(L,out);
                break;
        }

    }while(n!=0);
    // LinkList L;
    // List_HeadInsert(L);
    // int sum = Length(L);
    // printf("%d\n",sum);
    // PrintList(L);
    return 0;
}