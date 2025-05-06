/*
    created by: Arief F-sa Wijaya
    How to Run? (pilih salah satu cara):
    1. Command Prompt (CMD) : ./run.sh
       git/powershell       : . run.sh
    2. gcc -o main -Iinclude main.c
*/
#include <stdio.h>
#include "binarytree.h"

void showMenu() {
    printf("\n\n");
    printf("1. Insert node\n");
    printf("2. Print Tree\n");
    printf("3. Traversal PreOrder\n");
    printf("4. Traversal InOrder\n");
    printf("5. Traversal PreOrder\n");
    printf("6. Traversal LevelOrder\n");
    printf("7. Search Node Tree\n");
    printf("8. Jumlah Daun/Leaf\n");
    printf("9. Mencari Keadalaman Node Tree\n");
    printf("10. Membandingkan 2 Node Tree\n");
    printf("11. Exit\n");
    printf("Masukkan pilihan: ");
}

void selectMenu(int choice) {
    do {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            // Insert node
            break;
        case 2:
            // Print Tree
            break;
        case 3:
            // Traversal PreOrder
            break;
        case 4:
            // Traversal InOrder
            break;
        case 5:
            // Traversal PostOrder
            break;
        case 6:
            // Traversal LevelOrder
            break;
        case 7:
            // Search Node Tree
            break;
        case 8:
            // Jumlah Daun/Leaf
            break;
        case 9:
            // Mencari Keadalaman Node Tree
            break;
        case 10:
            // Membandingkan 2 Node Tree
            break;
        case 11:
            printf("Keluar dari program...\n");
            break;
        default:
            printf("Pilihan tidak valid. Coba lagi!.\n");
        }
    } while (choice != 11);
}

int main() {

}