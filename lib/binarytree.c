#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

/**** Primitif *****/
/* Selektor */

/* Mengirimkan informasi yang tersimpan di akar dari pohon Biner yg tdk kosong*/
infotype GetAkar(BinTree P) {
    return Info(P);
}

/* Mengirimkan anak kiri pohon biner P yang TIDAK kosong */
BinTree GetLeft(BinTree P) {
    return Left(P);
}

/* Mengirimkan anak kanan pohon biner P yang TIDAK kosong */
BinTree GetRight(BinTree P) {
    return Right(P);
}


/* Konstruktor */


/* Jika Alokasi berhasil, maka address != Nil dan Info (P) = X */
/* Mengirimkan address hasil alokasi sebuah elemen */
address Alokasi(infotype X) {
    address tree = (address)malloc(sizeof(Node));
    if (tree != NULL) {
        Info(tree) = X;
        Left(tree) = NULL;
        Right(tree) = NULL;
    }
    return tree;
}

/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
/* Menghasilkan sebuah pohon biner dari A, L dan R, jika alokasi berhasil */
BinTree Tree(infotype Akar, BinTree L, BinTree R) {
    BinTree tree = Alokasi(Akar);
    if (tree != NULL) {
        Left(tree) = L;
        Right(tree) = R;
    }
    return tree;
}

/* IS : BinTree Sembarang */
/* FS : Menghasilkan sebuah BinTree */
/* Menghasilkan sebuah pohon biner dari A, L dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree* P) {
    *P = Alokasi(Akar);
    if (*P != NULL) {
        Left(*P) = L;
        Right(*P) = R;
    }
}

/* Membentuk sebuah BinTree P dari pita karakter yang dibaca */
/* IS : Pita berisi "konstanta" pohon dalam bentuk prefix. Memori pasti cukup */
/*      Alokasi pasti berhasil */
/* FS : P dibentuk dari ekspresi dalam pita */
void BuildTree(BinTree* P) {

}


/**** Predikat Penting *****/
/* Mengirimkan true jika BinTree tidak kosong */
/* P adalah pohon UnerLeft (hanya mempunyai sub pohon kiri */
boolean IsUnerLeft(BinTree P) {

}

/* Mengirimkan true jika BinTree tidak kosong */
/* P adalah pohon UnerRight (hanya mempunyai sub pohon kanan */
boolean IsUnerRight(BinTree P) {

}

/* Mengirimkan true jika BinTree tidak kosong */
/* P adalah pohon Biner (mempunyai sub pohon kiri dan sub pohon kanan */
boolean IsBiner(BinTree P) {

}

/* Mengirimkan true jika BinTree KOSONG */
boolean IsEmpty(BinTree P) {
    return P == NULL;
}

/***** Traversal *****/


/* Traversal PreOrder menggunakan Rekursif */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah diproses secara PreOrder : Akar, Kiri, Kanan */
void PreOrder(BinTree P) {
    if (P != NULL) {
        printf("%c", Info(P));
        InOrder(Left(P));
        InOrder(Right(P));
    }
}

/* Traversal InOrder menggunakan Rekursif */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah diproses secara InOrder : Kiri, Arak, Kanan */
void InOrder(BinTree P) {
    if (P != NULL) {
        InOrder(Left(P));
        printf("%c", Info(P));
        InOrder(Right(P));
    }
}

/* Traversal PostOrder menggunakan Rekursif */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah diproses secara PostOrder :  Kiri, Kanan, Akar */
void PostOrder(BinTree P) {
    if (P != NULL) {
        InOrder(Right(P));
        InOrder(Left(P));
        printf("%c", Info(P));
    }
}

void LevelOrder(BinTree P) {
    int jmlNode = nbElmt(P);
    BinTree queue[jmlNode];
    int front = 0, rear = 0;
    queue[rear++] = P;
    while (front < rear) {
        BinTree current = queue[front++];
        printf("%c ", Info(current));
        if (Left(current) != NULL) {
            queue[rear++] = Left(current);
        }
        if (Right(current) != NULL) {
            queue[rear++] = Right(current);
        }
    }
    printf("\n");
}

/* IS : P terdefinisi, h adalah jarak indentasi */
/* FS : Semua simpul P sudah ditulis dengan indentasi */
void PrintTree(BinTree P, int h) {
    int jmlNode = nbElmt(P);
    BinTree queue[jmlNode];
    int front=0, rear=0;
    queue[rear++] = P;
    while(front<rear){
        BinTree current = queue[front++];
        printf("info node: %c \n",Info(current));
        if(Left(current)!=NULL){
            printf("info node left son: %c \n",Info(Left(current)));
        }else {
            printf("info node left son: (kosong) \n");
        }
        if(Right(current)!=NULL){
            printf("info node right son: %c \n\n",Info(Right(current)));
        }else {
            printf("info node left son: (kosong) \n\n");
        }
        if(Left(current)!=NULL){
            queue[rear++]= Left(current);
        }
        if(Right(current)!=NULL){
            queue[rear++]= Right(current);
        }
    }
    printf("\n");
}



/***** Search *****/

/* Mengirimkan true jika ada node dari P yang bernilai X */
boolean Search(BinTree P, infotype X) {

}


/***** Fungsi Lain *****/


/* Mengirimkan banyak elemen (node) pohon biner P */
int nbElmt(BinTree P) {
    if (P == NULL) return 0;
    else return 1 + nbElmt(Left(P)) + nbElmt(Right(P));
}

/* Mengirimkan banyak daun (node) pohon biner P */
int nbDaun(BinTree P) {

}

/* Mengirimkan true jika P adalah pohon condong kiri */
boolean IsSkewLeft(BinTree P) {

}

/* Mengirimkan true jika P adalah pohon condong kanan */
boolean IsSkewRight(BinTree P) {

}

/* Mengirimkan level dari node X yang merupakan salah satu simpul dari */
/* pohon biner P. Akar (P) levelnya adalah 1. Pohon tidak kosong */
int Level(BinTree P, infotype X) {
    if (P == NULL) return 0;
    if (Info(P) == X) return 1;
    int leftLevel = Level(Left(P), X);
    int rightLevel = Level(Right(P), X);
    if (leftLevel != 0) return leftLevel + 1;
    if (rightLevel != 0) return rightLevel + 1;
    return 0;
}

/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
/* Basis : Pohon Kosong, tingginya Nol */
/* Rekurens : 1 + maksimal (Depth (Anak Kiri), Depth  (Anak Kanan)) */
int Depth(BinTree P) {
    if (P == NULL) return 0;
    int leftDepth = Depth(Left(P));
    int rightDepth = Depth(Right(P));
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

/* Mengirimkan Nilai terbesar dari dua data */
infotype Max(infotype Data1, infotype Data2) {
    return Data1 < Data2 ? Data2 : Data1;
}


/***** Operasi Lain *****/

/* Menambah elemen Tree di cabang Kiri dengan alokasi baru */
/* IS : P boleh kosong */
/* FS : P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaunTerkiri(BinTree* P, infotype X) {
    if (*P == NULL) *P = Alokasi(X);
    else AddDaunTerkiri(&Left(*P), X);
}

/* IS : P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* FS : P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri) */
/*      atau sebagai anak Kanan X (jika NOT Kiri) */
void AddDaun(BinTree* P, infotype X, infotype Y, boolean Kiri) {

}


/* IS : P TIDAK Kosong */
/* FS : P dihapus daun terkirinya, dan didealokasi, dengan X adalah info */
/*      yang semula disimpan pada daun terkiri yang dihapus */
void DelDaunTerkiri(BinTree* T, infotype* X) {

}

/* IS : P TIDAK kosong, X adalah salah satu daun */
/* FS : X dihapus dari P */
void DelDaun(BinTree* T, infotype X) {

}


/***** Manipulasi LIST OF NODE *****/

/* Jika P adalah Pohon Kosong, maka menghasilkan List Kosong */
/* Jika P bukan Pohon Kosong, menghasilkan List yang elemennya adalah semua */
/*        daun pohon P, jika semua alokasi berhasil */
/*       		menghasilkan list kosong jika ada alokasi yang gagal */
ListOfNode MakeListDaun(BinTree P) {

}

/* Jika P adalah Pohon Kosong, maka menghasilkan List Kosong */
/* Jika P bukan Pohon Kosong, menghasilkan List yang elemennya adalah semua */
/*        elemen pohon P dengan urutan PreOrder, jika semua alokasi berhasil */
/*       		menghasilkan list kosong jika ada alokasi yang gagal */
ListOfNode MakeListPreOrder(BinTree P) {

}

/* Jika P adalah Pohon Kosong, maka menghasilkan List Kosong */
/* Jika P bukan Pohon Kosong, menghasilkan List yang elemennya adalah semua */
/*        elemen pohon P yang levelnya = N, jika semua alokasi berhasil */
/*       		menghasilkan list kosong jika ada alokasi yang gagal */
ListOfNode MakeListLevel(BinTree P, int N) {

}


/***** Membentuk Balanced Tree *****/

/* Menghasilkan sebuah balance Tree dengan N Node, nilai setiap node dibaca */
BinTree BuildBalanceTree(int N) {

}


/***** Operasi untuk Binary Search Tree *****/


/* Mengirimkan True jika ada node dari P yang bernilai X */
boolean BSearch(BinTree P, infotype X) {

}

/* Mengirimkan alamat Node jika ada node dari P yang bernilai X */
/* Mengirimkan Nil jika tidak ditemukan */
address BinSearch(BinTree P, infotype X) {
    if (P == NULL) {
        return NULL;
    }
    if (Info(P) == X) {
        return P;
    }
    address temp = BinSearch(Left(P), X);
    if (temp == NULL) {
        temp = BinSearch(Right(P), X);
    }

    return temp;
}

/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. */
/* Belum ada simpul P yang bernilai X */
void InsSearch(BinTree* P, infotype X) {

}


/* Menghapus seluruh elemen Tree secara Rekursif */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah dihapus secara PostOrder :  Kiri, Kanan, Akar */
void DestroyTree(BinTree* P) {

}

/* IS : Pohon P TIDAK kosong */
/* FS : Nilai X yang dihapus pasti ada, sebuah node dengan nilai X dihapus */
void DelBTree(BinTree* P, infotype X) {

}

/* IS : P adalah pohon biner TIDAK kosong */
/* FS : Q berisi salinan nilai daun terkanan */
void DelNode(BinTree* P) {

}

/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
void DeAlokasi(address P) {

}

