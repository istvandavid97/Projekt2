//
// Created by csoma on 2021. 05. 05..
//

#ifndef PROJEKT2_ROOT_H
#define PROJEKT2_ROOT_H

#include <stdio.h>
#include <malloc.h>
#include "string.h"
#define MAX_EMBER 3

typedef struct root
{
    char nev[50];
    int belepesi_ido;
    struct root *bal;
    struct root *jobb;
}root;



root *create(char nev[], int belepesi_ido);
void insert(root **pRoot, char nev[], int belepesi_ido);
void inorder(root *pRoot);
int findMaxforN(root* pRoot, int belepesi_ido);
void emberRegisztral(root **pRoot,char nev[], int belepesi_ido);
root *Find(root *fa, int a);



#endif //PROJEKT2_ROOT_H