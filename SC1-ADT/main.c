/*
    created by:
        Arief F-sa Wijaya
        Irvan Supriadi Situmorang
        M. Hasbi Hardian

    How to Run? (pilih salah satu cara):
    Untuk compile Case Study 1 (ADT) gunakan perintah ini di terminal:
    - command prompt   : . run.sh ADT
    - powershell / git : ./run.sh ADT

    - manual           :
      a. compile : gcc -o SC1-ADT/main -ISC1-ADT/include SC1-ADT/main.c SC1-ADT/lib/binarytree.c SC1-ADT/lib/morse.c
      b. run     : ./SC1-ADT/main.exe

    NB: Biarkan PATH Anda berada di parent (Jangan masuk ke folder apapun setelah clone)
*/

#include <stdio.h>
#include <string.h>
#include "include/morse.h"

void showMenu();
void InsertNode(BinTree* tree);
void selectMenu(int choice, BinTree* tree);

int main() {
    BinTree tree = NULL;
    int choice;
    selectMenu(choice, &tree);
    return 0;
}

void showMenu() {
    printf("\n\n");
    printf("1. Insert node\n");
    printf("2. Print Tree\n");
    printf("3. Traversal PreOrder\n");
    printf("4. Traversal InOrder\n");
    printf("5. Traversal PostOrder\n");
    printf("6. Traversal LevelOrder\n");
    printf("7. Search Node Tree\n");
    printf("8. Jumlah Daun/Leaf\n");
    printf("9. Mencari Keadalaman Node Tree\n");
    printf("10. Membandingkan 2 Node Tree\n");
    printf("11. Exit\n\n");
    printf("Masukkan pilihan: ");
}

void InsertNode(BinTree* tree) {
    // Insert node
    /*
     * 1. Masukkan data node
     * 2. Apakah sudah ada akar?
     *    a. JIKA BELUM: buat node menjadi akar
     *    b. JIKA ADA: tentukan parent dari node.
     *       dengan cara input dari parent
     * 3. Apakah node parent sudah punya anak?
     *    a. JIKA BELUM: tentukan mau insert di mana? L atau R
     *    b. JIKA SUDAH: dapatkan jumlah anak
     *    c. JIKA HANYA OUNYA SATU ANAK: insert node sebagai anak kedua baik L/R
     *    d. JIKA SUDAH PUNYA 2 ANAK: tampilkan error
     */
    infotype data;
    printf("Masukkan data node: ");
    scanf(" %c", &data);
    if (IsEmpty(*tree)) {
        AddDaunTerkiri(tree, data);
        printf("Node %c ditambahkan sebagai akar.\n", data);
    }
    else {
        infotype parentData;
        printf("Masukkan data parent: ");
        scanf(" %c", &parentData);
        BinTree pr = BinSearch(*tree, parentData);
        if (pr) {
            if (Left(pr) == NULL && Right(pr) == NULL) {
                printf("Parent belum memiliki anak.\n");
                printf("Tentukan letak input (\"kiri\" atau \"kanan\")\n");
                char side[6];
                do {

                    scanf("%s", side);
                    if (strcasecmp(side, "kiri") == 0) {
                        Left(pr) = Alokasi(data);
                        printf("Node %c ditambahkan sebagai anak kiri dari %c.\n", data, parentData);
                    }
                    else if (strcasecmp(side, "kanan") == 0) {
                        Right(pr) = Alokasi(data);
                        printf("Node %c ditambahkan sebagai anak kanan dari %c.\n", data, parentData);
                    }
                    else {
                        printf("Input tidak valid. Harus \"kiri\" atau \"kanan\".\n");
                    }
                } while (strcasecmp(side, "kiri") != 0 && strcasecmp(side, "kanan") != 0);
            }
            else if (Left(pr) == NULL) {
                Left(pr) = Alokasi(data);
                printf("Node %c ditambahkan sebagai anak kiri dari %c.\n", data, parentData);
            }
            else if (Right(pr) == NULL) {
                Right(pr) = Alokasi(data);
                printf("Node %c ditambahkan sebagai anak kanan dari %c.\n", data, parentData);
            }
            else {
                printf("Parent sudah memiliki 2 anak. Tidak bisa menambah node baru.\n");
            }
        }
        else {
            printf("Parent tidak ditemukan.\n");
        }
    }
}

void selectMenu(int choice, BinTree* tree) {
    do {
        printf("\nbanyak elemen tree sekarang: %d", nbElmt(*tree));
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            InsertNode(tree);
            break;
        case 2:
            // Print Tree
            PrintTree(*tree, 0);
            break;
        case 3:
            // Traversal PreOrder
            printf("\nPreorder\n");
            PreOrder(*tree);
            break;
        case 4:
            // Traversal InOrder
            printf("\nInOrder\n");
            InOrder(*tree);
            break;
        case 5:
            // Traversal PostOrder
            printf("\nPostorder\n");
            PostOrder(*tree);
            break;
        case 6:
            // Traversal LevelOrder
            printf("\nLevelOrder\n");
            LevelOrder(*tree);
            break;
        case 7:
            // Search Node Tree
            printf("Masukkan nilai yang dicari: ");
            infotype x;
            scanf(" %c", &x);
            printf(Search(*tree, x) ? "Node ditemukan.\n" : "Node tidak ditemukan.\n");
            break;
        case 8:
            // Jumlah Daun/Leaf
            printf("Jumlah daun: %d\n", nbDaun(*tree));
            break;
        case 9:
            // Mencari Keadalaman Node Tree
            printf("Kedalaman tree: %d\n", Depth(*tree));
            break;
        case 10:
            // Membandingkan 2 Node Tree
            infotype data1, data2;
            printf("Masukkan data node 1: ");
            scanf(" %c", &data1);
            printf("Masukkan data node 2: ");
            scanf(" %c", &data2);
            printf("Nilai terbesar dari %d dan %d adalah: %d\n", data1, data2, Max(data1, data2));
            break;
        case 11:
            printf("Keluar dari program...\n");
            break;
        default:
            printf("Pilihan tidak valid. Coba lagi!.\n");
        }
    } while (choice != 11);
}

