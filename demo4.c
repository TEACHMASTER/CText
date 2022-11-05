#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


typedef int dataType;
typedef struct LNode{
    dataType data;
    struct LNode *next;
}LNode,*LinkList;

void initList(LinkList *list){
    (*list) = (LNode*)malloc(sizeof(LNode));
    (*list)->next = (*list);
}

bool empty(LinkList list){
    return list->next==list?true:false;
}

void insert(LinkList *list,dataType e,int i){
    if(i<1){
        return;
    }
    LNode *p = (*list);
    int x=0;
    while(p&&x<i-1){
        p = p->next;
        x++;
    }
    if(!p){
        return;
    }
    LNode *temp = (LNode*)malloc(sizeof(LNode));
    temp->data = e;
    temp->next = p->next;
    p->next = temp;
}

void display(LinkList list){
    if(empty(list)){
        return;
    }
    LNode *p = list->next;
    while(p){
        printf("%d,",p->data);
        p=p->next;
    }
    printf("\n");
}

void main(){
    LinkList list;
    initList(&list);
    insert(&list,10,1);
    insert(&list,20,2);
    insert(&list,30,2);
    display(list);
    printf("%d\n",empty(list));
}