#include <stdio.h>
#include "nbtree.h"

int main() {
    Isi_Tree tree = {0};
    int jumlahNode;
    int pilihan;
    char cari, node1, node2;

    printf("Masukkan jumlah node dalam tree: ");
    scanf("%d", &jumlahNode);
    Create_tree(tree, jumlahNode);

    do {
        printf("\n1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree\n");
        printf("6. Search node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencari Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. Exit\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("PreOrder: ");
                PreOrder(tree);
                break;
            case 2:
                printf("InOrder: ");
                InOrder(tree);
                break;
            case 3:
                printf("PostOrder: ");
                PostOrder(tree);
                break;
            case 4:
                printf("Level Order: ");
                Level_order(tree, jumlahNode);
                break;
            case 5:
                PrintTree(tree);            
                break;
            case 6:
                printf("Masukkan karakter yang ingin dicari: ");
                scanf(" %c", &cari);
                if (Search(tree, cari))
                    printf("Node '%c' ditemukan.\n", cari);
                else
                    printf("Node '%c' tidak ditemukan.\n", cari);
                break;
            case 7:
                printf("Jumlah Daun/Leaf: %d\n", nbDaun(tree));
                break;
            case 8:
                printf("Masukkan karakter node: ");
                scanf(" %c", &cari);
                printf("Level node '%c' berada di level %d\n", cari, Level(tree, cari));
                break;
            case 9:
                printf("Kedalaman Tree: %d\n", Depth(tree));
                break;
            case 10:
                printf("Masukkan node pertama: ");
                scanf(" %c", &node1);
                printf("Masukkan node kedua: ");
                scanf(" %c", &node2);
                if (Level(tree, node1) == Level(tree, node2))
                    printf("Node '%c' dan '%c' berada di level yang sama.\n", node1, node2);
                else
                    printf("Node '%c' dan '%c' berada di level yang berbeda.\n", node1, node2);
                break;
            case 11:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 11);

    return 0;
}
