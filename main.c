#include "root.h"
#include "queue.h"


int main() {
    root* root1 = NULL;
    NodeType* first = NULL;
    NodeType* last = NULL;
    char valasz[5];
    int szam;
    char nev[25];
    int belepesi_ido_ora;
    int belepesi_ido_perc;

    printf("1. Regisztracio\n");
    printf("2. Kilepes\n");
    printf(">>");
    scanf("%s",valasz);
    while (strcmp(valasz,"2")!=0) {
        if (atoi(valasz) == 1){
            printf("Kerek egy nevet:");
            scanf("%s",nev);
            printf("Hany orakor?");
            scanf("%d",&belepesi_ido_ora);
            printf("Hany perckor?");
            scanf("%d",&belepesi_ido_perc);
            emberRegisztral(&root1,nev,belepesi_ido_ora*60+belepesi_ido_perc);
        }
        printf(">>");
        scanf("%s",valasz);
    }
    printf("Idoszimulalas\n");
    int ora = 7;
    int perc = 0;
    root * p_root = NULL;

    while (ora < 21) {
        if (perc%60==0) {
            ora++;
            perc = 0;
        }
        p_root = Find(root1,ora*60+perc);
        if (p_root != NULL ){
            printf("%d:%d-kor %s belepett!\n",ora,perc,p_root->nev);
            insert_q(&first,&last,p_root->belepesi_ido+30,p_root->nev);
        }
        if (isEmpty(first) == 0 ) {
            if (first->q_kilepesi_ido == ora*60+perc) {
                printf("%d:%d-kor %s kilepett!\n",ora,perc,first->q_nev);
                delete(&first);
            }
        }
        ++perc;
    }


    return 0;
}