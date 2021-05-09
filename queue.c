//
// Created by István on 5/9/2021.
//

#include "queue.h"

void createQueue(NodeType** pNodeType){
    (*pNodeType)=(NodeType*)malloc(1*sizeof(NodeType));
    if ((*pNodeType)==NULL){
        printf("Hiba");
    }
    (*pNodeType)->next=NULL;
}
int isEmpty(NodeType *first){
    if (first==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void insert_q(NodeType** first,NodeType** last,int q_kilepesi_ido, char q_nev[]){
    NodeType* newNode;
    createQueue(&newNode);
    newNode->q_kilepesi_ido=q_kilepesi_ido;
    strcpy(newNode->q_nev,q_nev);
    if(isEmpty((*first))){
        (*first)=newNode;
        (*last)=newNode;
    }else{
        (*last)->next=newNode;
        (*last)=newNode;
    }
}

int delete(NodeType** first){
    NodeType* auxNode;
    if(!isEmpty(*first)){
        auxNode=(*first);
        int auxInfo=(*first)->q_kilepesi_ido;
        (*first)=(*first)->next;
        free(auxNode);
        return auxInfo;
    }else{
        return INT_MIN;
    }
}

void printNode(NodeType** first){
    while(isEmpty(*first)==0){
        printf("%d ", delete(first));
    }
    printf("\n");
}
