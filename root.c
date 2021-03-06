//
// Created by csoma on 2021. 05. 05..
//

#include "root.h"

root *create(char nev[], int belepesi_ido)
{
    root *ag;
    ag = (root *)(malloc(sizeof(root)));
    if(!ag)
    {
        printf("Sikertelen lefoglalas");
        return 0;
    }
    strcpy(ag->nev,nev);
    ag->belepesi_ido=belepesi_ido;
    ag->jobb = NULL;
    ag->bal = NULL;
    return ag;
}
void insert(root **pRoot,char nev[], int belepesi_ido)
{
    if((*pRoot) == NULL)
    {
        (*pRoot) = create(nev,belepesi_ido);
    }
    else
    {
        if((*pRoot)->belepesi_ido > belepesi_ido)
            insert(&((*pRoot)->bal),nev,belepesi_ido);
        else insert(&((*pRoot)->jobb),nev,belepesi_ido);
    }
}
void inorder(root *pRoot) {
    if (pRoot->bal)
        inorder(pRoot->bal);
    printf("%s=>>%d:%d\n", pRoot->nev, pRoot->belepesi_ido / 60, pRoot->belepesi_ido % 60);
    if (pRoot->jobb)
        inorder(pRoot->jobb);
}
int findMaxforN(root* pRoot, int belepesi_ido)
{
    if (pRoot == NULL)
        return -1;
    if (pRoot->belepesi_ido == belepesi_ido)
        return belepesi_ido;

    else if (pRoot->belepesi_ido < belepesi_ido) {
        int k = findMaxforN(pRoot->jobb, belepesi_ido);
        if (k == -1) {
            return pRoot->belepesi_ido;
        }
        else
            return k;
    }
    else if (pRoot->belepesi_ido > belepesi_ido)
        return findMaxforN(pRoot->bal, belepesi_ido);
}
void emberRegisztral(root **pRoot,char nev[], int belepesi_ido, int max_ember){
    int max=0;
    int be_ido;
    be_ido = findMaxforN(*pRoot,belepesi_ido+30);
    while(be_ido!=-1){
        if (be_ido<(belepesi_ido-30)){
            break;
        }else{
            max++;
            be_ido--;
            be_ido=findMaxforN(*pRoot,be_ido);
        }
    }
    if (max==max_ember){
        printf("Ebben az idopontban nem lehet belepni, max 5 ember!\n");
    }else{
        insert(pRoot,nev,belepesi_ido);
        printf("%s regisztralt!\n", nev);
    }
}