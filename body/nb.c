#include "../header/nb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Create_tree(Isi_Tree t, int Jml_Node) {
    int i, parent;
    infotype info;

    for (i = 1; i <= jml_maks; i++) {
        t[i].info = '-';
        t[i].ps_fs = nil;
        t[i].ps_nb = nil;
        t[i].ps_pr = nil;
    }

    printf("Masukkan jumlah node: ");
    scanf("%d", &Jml_Node);

    for (i = 1; i <= Jml_Node; i++) {
        printf("Masukkan info untuk node ke-%d: ", i);
        scanf(" %c", &t[i].info);
    }

    printf("Parent:\n");
    for (i = 2; i <= Jml_Node; i++) {
        printf("Masukkan indeks parent untuk node ke-%d :", i);
        scanf("%d", &parent);

        t[i].ps_pr = parent;

        if (t[parent].ps_fs == nil) {
            t[parent].ps_fs = i;
        } else {
            int ns = t[parent].ps_fs;
            while (t[ns].ps_nb != nil) {
                ns = t[ns].ps_nb;
            }
            t[ns].ps_nb = i;
        }
    }
}

boolean IsEmpty(Isi_Tree P) {
    return (P[1].info == '\0');
}

void PreOrder(Isi_Tree P) {
    static int init = 0;
    static int node;

    if (!init) {
        if (IsEmpty(P)) {
            printf("Tree kosong\n");
            return;
        }
        node = 1;
        init = 1;
    }

    if (node == 0) return;

    printf("%c ", P[node].info);

    int current = node;

    node = P[current].ps_fs;
    PreOrder(P);

    node = P[current].ps_nb;
    PreOrder(P);

    if (current == 1) {
        init = 0;
    }
}

void InOrder(Isi_Tree P) {
    static int init = 0;
    static int node;

    if (!init) {
        if (IsEmpty(P)) {
            printf("Tree kosong\n");
            return;
        }
        node = 1;
        init = 1;
    }

    if (node == 0) return;

    int current = node;

    if (P[current].ps_fs != 0) {
        node = P[current].ps_fs;
        InOrder(P);
    }

    printf("%c ", P[current].info);

    if (P[current].ps_fs != 0) {
        int ns = P[P[current].ps_fs].ps_nb;
        while (ns != 0) {
            node = ns;
            InOrder(P);
            ns = P[ns].ps_nb;
        }
    }

    if (current == 1) {
        init = 0;
    }
}

void InorderTranversal(Isi_Tree_Morse tree, address_morse root) {
    if (root == nil_morse || tree[root].info == '\0') return;
    InorderTranversal(tree, tree[root].left);
    if (tree[root].info != '#') printf("%c ", tree[root].info);
    InorderTranversal(tree, tree[root].right);
}

void PostOrder(Isi_Tree P) {
    static int init = 0;
    static int node;

    if (!init) {
        if (IsEmpty(P)) {
            printf("Tree kosong\n");
            return;
        }
        node = 1;
        init = 1;
    }

    if (node == 0) return;

    int current = node;

    if (P[current].ps_fs != 0) {
        node = P[current].ps_fs;
        PostOrder(P);
    }

    if (P[current].ps_fs != 0) {
        int ns = P[P[current].ps_fs].ps_nb;
        while (ns != 0) {
            node = ns;
            PostOrder(P);
            ns = P[ns].ps_nb;
        }
    }

    printf("%c ", P[current].info);

    if (current == 1) {
        init = 0;
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    if (IsEmpty(X)) {
        printf("Tree Kosong\n");
        return;
    }

    int queue[jml_maks];
    int front = 0, rear = 0;

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
}

boolean Search(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            return 1;
        }
    }
    return 0;
}

int nbElmt(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            count++;
        }
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == nil) {
            count++;
        }
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int level = 0;
            int parent = P[i].ps_pr;
            while (parent != nil) {
                level++;
                parent = P[parent].ps_pr;
            }
            return level;
        }
    }
    return -1;
}

int Depth(Isi_Tree P) {
    int maxDepth = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            int depth = 0;
            int parent = P[i].ps_pr;
            while (parent != nil) {
                depth++;
                parent = P[parent].ps_pr;
            }
            if (depth > maxDepth) {
                maxDepth = depth;
            }
        }
    }
    return maxDepth;
}

void inisialize(Isi_Tree_Morse tree) {
    for (int i = 1; i <= jml_maks_morse; i++) {
        tree[i].info = '\0';
        tree[i].left = nil_morse;
        tree[i].right = nil_morse;
    }
}

address_morse Alokasi(Isi_Tree_Morse tree, char info) {
    for (int i = 1; i <= jml_maks_morse; i++) {
        if (tree[i].info == '\0') {
            tree[i].info = info;
            return i;
        }
    }
    return nil_morse;
}

void Insert(Isi_Tree_Morse tree, char huruf, const char* kode) {
    address_morse current = 1;
    if (tree[current].info == '\0') tree[current].info = '#';

    for (int i = 0; kode[i] != '\0'; i++) {
        if (kode[i] == '.') {
            if (tree[current].left == nil_morse) {
                address_morse baru = Alokasi(tree, '#');
                tree[current].left = baru;
            }
            current = tree[current].left;
        } else if (kode[i] == '-') {
            if (tree[current].right == nil_morse) {
                address_morse baru = Alokasi(tree, '#');
                tree[current].right = baru;
            }
            current = tree[current].right;
        }
    }
    tree[current].info = huruf;
}

void add_morse(Isi_Tree_Morse tree) {
    Insert(tree, 'A', "-"); Insert(tree, 'B', "."); Insert(tree, 'C', "-.");
    Insert(tree, 'D', ".."); Insert(tree, 'E', "--"); Insert(tree, 'F', ".-");
    Insert(tree, 'G', "-.."); Insert(tree, 'H', "..."); Insert(tree, 'I', "-.-");
    Insert(tree, 'J', "..-"); Insert(tree, 'K', "--."); Insert(tree, 'L', ".-.");
    Insert(tree, 'M', "---"); Insert(tree, 'N', ".--"); Insert(tree, 'O', "-...");
    Insert(tree, 'P', "...."); Insert(tree, 'Q', "-..-"); Insert(tree, 'R', "...-");
    Insert(tree, 'S', "-.-."); Insert(tree, 'T', "..-."); Insert(tree, 'U', "-.--");
    Insert(tree, 'V', "..--"); Insert(tree, 'W', "--.."); Insert(tree, 'X', ".-..");
    Insert(tree, 'Y', "--.-"); Insert(tree, 'Z', ".-.-"); Insert(tree, '1', "---.");
    Insert(tree, '2', ".--."); Insert(tree, '3', "----"); Insert(tree, '4', ".---");
    Insert(tree, '5', "-...."); Insert(tree, '6', "....."); Insert(tree, '7', "-...-");
    Insert(tree, '8', "....-"); Insert(tree, '9', "-.-..."); Insert(tree, ' ', "/");

}

const char* CariKodeMorse(Isi_Tree_Morse tree, address_morse root, char target, char* buffer, int depth) {
    if (root == nil_morse) return NULL;
    if (tree[root].info == target) {
        buffer[depth] = '\0';
        return buffer;
    }
    if (tree[root].left != nil_morse) {
        buffer[depth] = '.';
        const char* res = CariKodeMorse(tree, tree[root].left, target, buffer, depth + 1);
        if (res != NULL) return res;
    }
    if (tree[root].right != nil_morse) {
        buffer[depth] = '-';
        const char* res = CariKodeMorse(tree, tree[root].right, target, buffer, depth + 1);
        if (res != NULL) return res;
    }
    return NULL;
}

void ConvertString(Isi_Tree_Morse tree, const char* kalimat, const char* outputFile) {
    char buffer[100];
    FILE* fout = fopen(outputFile, "a");

    if (!fout) {
        printf("Gagal membuka file output.\n");
        return;
    }

    for (int i = 0; kalimat[i] != '\0'; i++) {
        char ch = toupper(kalimat[i]);
        const char* kode = CariKodeMorse(tree, 1, ch, buffer, 0);
        if (kode != NULL) {
            fprintf(fout, "%s ", kode); 
            printf("%s ", kode);
        } else {
            fprintf(fout, "? ");
            printf("? ");
        }
    }
    fprintf(fout, "\n");  
    printf("\n");

    fclose(fout);
    printf("Output disimpan di %s", outputFile);
}




void ConvertFile(Isi_Tree_Morse tree, const char* inputFile, const char* outputFile) {
    FILE* fin = fopen(inputFile, "r");
    FILE* fout = fopen(outputFile, "w");
    char buffer[256];
    char morse[100];

    if (!fin) {
        printf("Gagal membuka file input: %s\n", inputFile);
        return;
    }

    if (!fout) {
        printf("Gagal membuka file output: %s\n", outputFile);
        fclose(fin);
        return;
    }

    while (fgets(buffer, sizeof(buffer), fin)) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            char ch = toupper(buffer[i]);

            if (ch == '\n') {
                fprintf(fout, "\n");
                continue;
            }

            const char* kode = CariKodeMorse(tree, 1, ch, morse, 0);
            if (kode != NULL) {
                fprintf(fout, "%s ", kode);
            } else {
                fprintf(fout, "? ");
            }
        }
    }

    fclose(fin);
    fclose(fout);
    printf("Output berhasil disimpan di %s", outputFile);
}
