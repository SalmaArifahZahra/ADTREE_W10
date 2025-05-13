#include <stdio.h>
#include "header/nb.h"

int main() {
    Isi_Tree Tree;
    Isi_Tree_Morse MorseTree;
    int pilihan, jmlNode = 0; 
    infotype cari;
    char kalimat[256];

    inisialize(MorseTree);
    add_morse(MorseTree);

    do {
        printf("\n====== MENU PROGRAM ======\n");
        printf("1. Inisialisasi Tree Non-Biner\n");
        printf("2. Traversal PreOrder\n");
        printf("3. Traversal InOrder\n");
        printf("4. Traversal PostOrder\n");
        printf("5. Level Order\n");
        printf("6. Cek Tree Kosong\n");
        printf("7. Cari Node\n");
        printf("8. Jumlah Node\n");
        printf("9. Jumlah Daun\n");
        printf("10. Level Node\n");
        printf("11. Kedalaman Tree\n");
        printf("12. InOrder (Morse Tree)\n");
        printf("13. Konversi String ke Morse\n");
        printf("14. Konversi file\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        getchar(); 

        switch(pilihan) {
            case 1:
                printf("=== Inisialisasi Tree Non-Biner ===\n");
                Create_tree(Tree, jmlNode);
                break;
            case 2:
                if (jmlNode > 0) {
                    printf("PreOrder: ");
                    PreOrder(Tree);
                    printf("\n");
                } else {
                    printf("Tree belum diinisialisasi!\n");
                }
                break;
            case 3:
                if (jmlNode > 0) {
                    printf("InOrder: ");
                    InOrder(Tree);
                    printf("\n");
                } else {
                    printf("Tree belum diinisialisasi!\n");
                }
                break;
            case 4:
                if (jmlNode > 0) {
                    printf("PostOrder: ");
                    PostOrder(Tree);
                    printf("\n");
                } else {
                    printf("Tree belum diinisialisasi!\n");
                }
                break;
            case 5:
                if (jmlNode > 0) {
                    printf("Level Order: ");
                    Level_order(Tree, jml_maks);
                    printf("\n");
                } else {
                    printf("Tree belum diinisialisasi!\n");
                }
                break;
            case 6:
                printf(IsEmpty(Tree) ? "Tree kosong\n" : "Tree tidak kosong\n");
                break;
            case 7:
                if (jmlNode > 0) {
                    printf("Masukkan data: ");
                    scanf(" %c", &cari);
                    printf(Search(Tree, cari) ? "Data ditemukan\n" : "Data tidak ditemukan\n");
                } else {
                    printf("Tree belum diinisialisasi!\n");
                }
                break;
            case 8:
                printf("Jumlah Node: %d\n", nbElmt(Tree));
                break;
            case 9:
                printf("Jumlah Daun: %d\n", nbDaun(Tree));
                break;
            case 10:
                if (jmlNode > 0) {
                    printf("Masukkan data node: ");
                    scanf(" %c", &cari);
                    int level = Level(Tree, cari);
                    if (level >= 0)
                        printf("Level node %c adalah %d\n", cari, level);
                    else
                        printf("Node tidak ditemukan\n");
                } else {
                    printf("Tree belum diinisialisasi!\n");
                }
                break;
            case 11:
                printf("Kedalaman Tree: %d\n", Depth(Tree));
                break;
            case 12:
                printf("[Inorder Morse Tree]:\n");
                InorderTranversal(MorseTree, 1);
                printf("\n");
                break;
          case 13:
                printf("Masukkan kalimat: ");
                fgets(kalimat, sizeof(kalimat), stdin);
                kalimat[strcspn(kalimat, "\n")] = '\0';  

                FILE* fin = fopen("input.txt", "a");
                if (fin) {
                    fprintf(fin, "%s\n", kalimat); 
                    fclose(fin);
                    printf("Kalimat disimpan di input.txt\n");

                    printf("Hasil Morse:\n");
                    ConvertString(MorseTree, kalimat, "out.txt"); 
                    printf("(Morse juga disimpan di out.txt)\n");
                } else {
                    printf("Gagal membuka file input.txt\n");
                }
                break;
            case 14:
                ConvertFile(MorseTree, "input.txt", "out.txt");
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 0);

    return 0;
}
