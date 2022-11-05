#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef int dataType;
typedef struct LNode{
    dataType data;
    struct LNode *next;
}LNode,*LinkList;

bool empty(LinkList list){
    return list->next==NULL?true:false;
}

void initList(LinkList *list){
    (*list) = (LinkList)malloc(sizeof(LNode));
    (*list)->next = NULL;
}

void insertList_Tail(LinkList *list,dataType e,int i){
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

void insertList_Head(LinkList *list,dataType e,int i){
    if(i<1){
        return;
    }
    LNode *p = (*list);
    int x=0;
    while(p&&x<i){
        p=p->next;
        x++;
    }
    if(!p){
        return;
    }
    LNode *temp = (LNode*)malloc(sizeof(LNode));
    temp->next = p->next;
    p->next = temp;
    temp->data = p->data;
    p->data = e;
}

void ListTail(LinkList *list){
    (*list) = (LinkList)malloc(sizeof(LNode));
    (*list)->next = NULL;
    LNode *c;
    LNode *r = (*list);
    dataType e;
    scanf("%d",&e);
    while(e!=-1){
        c = (LNode*)malloc(sizeof(LNode));
        c->data = e;
        r->next = c;
        r = c;
        scanf("%d",&e);
    }
    r->next = NULL;
}

void ListHead(LinkList *list){
    (*list) = (LinkList)malloc(sizeof(LNode));
    (*list)->next = NULL;
    LNode *c;
    dataType e;
    scanf("%d",&e);
    while(e!=-1){
        c = (LNode*)malloc(sizeof(LNode));
        c->next = (*list)->next;
        (*list)->next = c;
        c->data = e;
        scanf("%d",&e);
    }
}

void delete(LinkList *list,int i){
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
    LNode *next = p->next;
    p->next = next->next;
    free(next);
}

void del(LNode *node){
    if(node==NULL){
        return;
    }
    LNode *p = node->next;
    node->next = p->next;
    node->data = p->data;
    free(p);
}

LNode* get(LinkList list,int i){
    if(i<1){
        return NULL;
    }
    LNode *p = list;
    int x=0;
    while(p&&x<i){
        p=p->next;
        x++;
    }
    if(!p){
        return NULL;
    }
    return p;
}

void display(LinkList list){
    if(list==NULL){
        return;
    }
    LNode *p = list->next;
    while(p){
        printf("%d,",p->data);
        p = p->next;
    }
    printf("\n");
}
void main(){
    LinkList list;
    initList(&list);
    ListHead(&list);
    insertList_Head(&list,100,1);
    delete(&list,3);
    LNode *temp = get(list,2);
    del(temp);
    display(list);
    printf("%d",empty(list));
}