#include "root.h"

int main() {
    root* root = NULL;
    emberRegisztral(&root,"Janos",68,5);
    emberRegisztral(&root,"Attila",71,5);
    emberRegisztral(&root,"Bela",66,5);
    emberRegisztral(&root,"Karcsi",70,5);
    emberRegisztral(&root,"Margit",65,5);
    emberRegisztral(&root,"Anna",67,5);
    emberRegisztral(&root,"Peter",69,5);
    emberRegisztral(&root,"Julia",41,5);
    //inorder(root);

    return 0;
}