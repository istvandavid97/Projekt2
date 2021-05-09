//
// Created by István on 5/9/2021.
//

#ifndef PROJEKT2_QUEUE_H
#define PROJEKT2_QUEUE_H

#include <stdio.h>
#include "malloc.h"
#include <limits.h>
#include <string.h>
typedef struct NodeType{
    int q_kilepesi_ido;
    char q_nev[25];
    struct NodeType *next;
}NodeType;

void createQueue(NodeType**);
int isEmpty(NodeType *first);
void insert_q(NodeType**,NodeType**,int,char[]);
int delete(NodeType**);
void printNode(NodeType**);


#endif //PROJEKT2_QUEUE_H
