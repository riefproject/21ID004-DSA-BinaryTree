/*
    created by:
        Arief F-sa Wijaya
        Irvan Supriadi Situmorang
        M. Hasbi Hardian

    How to Run? (pilih salah satu cara):
    Untuk compile Case Study 2 (Morse) gunakan perintah ini di terminal:
    - command prompt   : . run.sh Morse
    - powershell / git : ./run.sh Morse

    - manual           :
      a. compile : gcc -o SC2-Morse/main -ISC2-Morse/include SC2-Morse/main.c SC2-Morse/lib/binarytree.c SC2-Morse/lib/morse.c
      b. run     : ./SC2-Morse/main.exe

    NB: Biarkan PATH Anda berada di parent (Jangan masuk ke folder apapun setelah clone)
*/

#include <stdio.h>
#include <string.h>
#include "include/morse.h"

void InsertNode(BinTree* tree);
void showMenuMorse();
void selectMenuMorse(int choice, BinTree* tree);

int main() {
    BinTree tree = NULL;
    int choice;
    selectMenuMorse(choice, &tree);
    return 0;
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

void showMenuMorse() {
    printf("\n\n");
    printf("1. Insert node\n");
    printf("2. Char to Morse\n");
    printf("3. Morse to Char\n");
    printf("4. Print Tree\n");
    printf("5. Exit\n");
    printf("Masukkan pilihan: ");
}

void selectMenuMorse(int choice, BinTree* tree) {
    do {
        showMenuMorse();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            InsertNode(tree);
            break;
        case 2:
            // String to Morse
            char input[100];
            char morseOutput[1000];
            printf("Masukkan karakter: ");
            scanf(" %[^\n]", input);
            StringToMorse(*tree, input, morseOutput);
            printf("%s", morseOutput);
            break;

        case 3:
            // Morse to Char
            char morseInput[1000];
            char output[100];
            printf("Masukkan kode morse: ");
            scanf(" %[^\n]", morseInput);
            MorseStringToText(*tree, morseInput, output);

            if (strcmp(output, "*") != 0 && strcmp(output, "(") != 0 && strcmp(output, ")") != 0) {
                printf("hasil dari pencarian kode morse: %s\n", output);
            }
            else if (strcmp(output, "*") == 0) {
                printf("error, tree masih kosong!\n");
            }
            else if (strcmp(output, "(") == 0) {
                printf("error, bukan karakter morse!\n");
            }
            else {
                printf("karakter tidak ditemukan, jalur tidak valid!\n");
            }


            break;
        case 4:
            // Print Tree
            PrintTree(*tree, 0);
            break;
        case 5:
            printf("Keluar dari program...\n");
            break;

        default:
            printf("Pilihan tidak valid. Coba lagi!.\n");
        }
    } while (choice != 5);
}
