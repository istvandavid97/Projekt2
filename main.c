#include "root.h"

int main() {
    root* root = NULL;
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
            emberRegisztral(&root,nev,belepesi_ido_ora*60+belepesi_ido_perc);
        }
        printf(">>");
        scanf("%s",valasz);
    }

    return 0;
}