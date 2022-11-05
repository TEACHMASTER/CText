#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef int dataType;
typedef struct DNode{
    dataType data;
    struct DNode *prior,*next;
}DNode,*DLinkNode;

void initList(DLinkNode *dlinknode){
    (*dlinknode) = (DLinkNode)malloc(sizeof(DNode));
    (*dlinknode)->next = NULL;
    (*dlinknode)->prior = NULL;
}

bool empty(DLinkNode dlinknode){
    return dlinknode->next==NULL?true:false;
}

void display(DLinkNode dlinknode){
    if(dlinknode==NULL){
        return;
    }
    DNode *p = (dlinknode)->next;
    while(p){
        printf("%d,",p->data);
        p = p->next;
    }
    printf("\n");
}

void insertList_Tail(DLinkNode *dlinknode,dataType e,int i){
    if(i<1){
        return;
    }
    DNode *p = (*dlinknode);
    int x=0;
    while(p&&x<i-1){
        p = p->next;
        x++;
    }
    if(!p){
        return;
    }
    DNode *temp = (DNode*)malloc(sizeof(DNode));
    temp->data = e;
    temp->next = p->next;
    if((p->next)!=NULL){
        p->next->prior = temp;
    }
    p->next = temp;
    temp->prior = p;
}

void delete(DLinkNode *dlinknode,int i){
    if(i<1){
        return;
    }
    DNode *p = (*dlinknode);
    int x=0;
    while(p&&x<i-1){
        p = p->next;
        x++;
    }
    if(!p){
        return;
    }
    if(!(p->next)){
        return;
    }
    DNode *temp = p->next;
    p->next = temp->next;
    if((temp->next)!=NULL){
        temp->next->prior = p;
    }
    free(temp);
}

DNode* get(DLinkNode dlinknode,int i){
    if(empty(dlinknode)){
        return NULL;
    }
    DNode *p = dlinknode;
    int x=0;
    while(p&&x<i){
        p = p->next;
        x++;
    }
    if(!p){
        return NULL;
    }
    return p;
}

void main(){
    DLinkNode dlinknode;
    initList(&dlinknode);
    insertList_Tail(&dlinknode,10,1);
    insertList_Tail(&dlinknode,20,1);
    insertList_Tail(&dlinknode,30,2);
    delete(&dlinknode,4);
    //display(dlinknode);
    DNode *p = get(dlinknode,1);
    DNode *temp = p;
    printf("%d\n",p->data);
    while((temp->next)){
        printf("%d,",temp->data);
        temp = temp->next;
    }
}