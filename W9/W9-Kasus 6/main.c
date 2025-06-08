#include <stdio.h>
#include "nbtree.h"

int main() {
    Isi_Tree tree = {0};
    int jumlahNode;

    printf("Masukkan jumlah node dalam tree: ");
    scanf("%d", &jumlahNode);

    Create_tree(tree, jumlahNode);

    printf("\n=== Hasil Tree ===\n");
    PrintTree(tree);

    return 0;
}
