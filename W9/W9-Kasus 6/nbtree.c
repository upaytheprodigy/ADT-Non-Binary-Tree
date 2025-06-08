#include <stdio.h>
#include <stdbool.h>
#define jml_maks 20
#define nil 0

typedef char infotype;
typedef int address;

typedef struct {
    infotype info;
    address ps_fs, ps_nb, ps_pr;
} nbtree;

typedef nbtree Isi_Tree[jml_maks + 1];

void Create_tree(Isi_Tree X, int Jml_Node) {
    int i;
    char info;
    for (i = 1; i <= Jml_Node; i++) {
        printf("Masukkan info node ke-%d: ", i);
        scanf(" %c", &info);
        X[i].info = info;
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }

    for (i = 1; i <= Jml_Node; i++) {
        int parent;
        printf("Masukkan parent untuk node ke-%d (0 jika root): ", i);
        scanf("%d", &parent);
        if (parent != nil) {
            X[i].ps_pr = parent;
            if (X[parent].ps_fs == nil) {
                X[parent].ps_fs = i;
            } else {
                int temp = X[parent].ps_fs;
                while (X[temp].ps_nb != nil) {
                    temp = X[temp].ps_nb;
                }
                X[temp].ps_nb = i;
            }
        }
    }
}

bool IsEmpty(Isi_Tree P) {
    return P[1].info == '\0';
}

void PreOrder_Rekursif(Isi_Tree P, int idx) {
    if (idx == nil) return;
    printf("%c ", P[idx].info);
    PreOrder_Rekursif(P, P[idx].ps_fs);
    PreOrder_Rekursif(P, P[idx].ps_nb);
}

void PreOrder(Isi_Tree P) {
    if (!IsEmpty(P)) {
        PreOrder_Rekursif(P, 1);
        printf("\n");
    }
}

void PostOrder_Rekursif(Isi_Tree P, int idx) {
    if (idx == nil) return;
    PostOrder_Rekursif(P, P[idx].ps_fs);
    printf("%c ", P[idx].info);
    PostOrder_Rekursif(P, P[idx].ps_nb);
}

void PostOrder(Isi_Tree P) {
    if (!IsEmpty(P)) {
        PostOrder_Rekursif(P, 1);
        printf("\n");
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    int queue[jml_maks], front = 0, rear = 0;
    if (!IsEmpty(X)) {
        queue[rear++] = 1;
        while (front < rear) {
            int current = queue[front++];
            printf("%c ", X[current].info);
            int child = X[current].ps_fs;
            while (child != nil) {
                queue[rear++] = child;
                child = X[child].ps_nb;
            }
        }
        printf("\n");
    }
}

void PrintTree_Rekursif(Isi_Tree P, int idx, int depth) {
    if (idx == nil) return;
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("|- %c\n", P[idx].info);
    PrintTree_Rekursif(P, P[idx].ps_fs, depth + 1);
    PrintTree_Rekursif(P, P[idx].ps_nb, depth);
}

void PrintTree(Isi_Tree P) {
    if (!IsEmpty(P)) {
        printf("%c\n", P[1].info);
        PrintTree_Rekursif(P, P[1].ps_fs, 1);
    }
}

bool SearchRekursif(Isi_Tree P, int idx, infotype X) {
    if (idx == nil) return false;
    if (P[idx].info == X) return true;
    if (SearchRekursif(P, P[idx].ps_fs, X)) return true;
    return SearchRekursif(P, P[idx].ps_nb, X);
}

bool Search(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) return false;
    return SearchRekursif(P, 1, X);
}

int nbElmtRekursif(Isi_Tree P, int idx) {
    if (idx == nil) return 0;
    return 1 + nbElmtRekursif(P, P[idx].ps_fs) + nbElmtRekursif(P, P[idx].ps_nb);
}

int nbElmt(Isi_Tree P) {
    return nbElmtRekursif(P, 1);
}

int nbDaunRekursif(Isi_Tree P, int idx) {
    if (idx == nil) return 0;
    if (P[idx].ps_fs == nil) return 1 + nbDaunRekursif(P, P[idx].ps_nb);
    return nbDaunRekursif(P, P[idx].ps_fs) + nbDaunRekursif(P, P[idx].ps_nb);
}

int nbDaun(Isi_Tree P) {
    return nbDaunRekursif(P, 1);
}

int LevelRekursif(Isi_Tree P, int idx, infotype X, int depth) {
    if (idx == nil) return -1;
    if (P[idx].info == X) return depth;
    int d = LevelRekursif(P, P[idx].ps_fs, X, depth + 1);
    if (d != -1) return d;
    return LevelRekursif(P, P[idx].ps_nb, X, depth);
}

int Level(Isi_Tree P, infotype X) {
    return LevelRekursif(P, 1, X, 0);
}

int DepthRekursif(Isi_Tree P, int idx) {
    if (idx == nil) return -1;
    int max_depth = -1;
    int child = P[idx].ps_fs;
    while (child != nil) {
        int d = DepthRekursif(P, child);
        if (d > max_depth) max_depth = d;
        child = P[child].ps_nb;
    }
    return max_depth + 1;
}

int Depth(Isi_Tree P) {
    return DepthRekursif(P, 1);
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}
