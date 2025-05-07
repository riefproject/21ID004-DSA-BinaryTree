#include "binarytree.h"
int charToMorse(BinTree root, int target, char* path, int depth) {
    if (root == NULL)
        return 0;

    if (root->info == target) {
        path[depth] = '\0';  // Null-terminate string
        return 1;
    }

    path[depth] = '.';  // kiri
    if (charToMorse(root->left, target, path, depth + 1))
        return 1;

    path[depth] = '-';  // kanan
    if (charToMorse(root->right, target, path, depth + 1))
        return 1;

    return 0;

}
char MorseToChar(BinTree root, char* path){
    BinTree curr = root;
    if(curr == NULL){
        return '*';
    }
    for (int i=0; path[i]!='\0'; i++){
        if(curr == NULL){
            return ')';
        }
        if(path[i]=='.'){
            curr= Left(curr);
        } else if(path[i]=='-'){
            curr = Right(curr);
        }
        else {
            return '(';
        }
    }
    if (curr != NULL){
        return Info(curr);
    }
    return ')';
}