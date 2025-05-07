#include "../include/binarytree.h"
int charToMorse(BinTree root, int target, char *path, int depth)
{
    if (root == NULL)
        return 0;

    if (root->info == target)
    {
        path[depth] = '\0'; // Null-terminate string
        return 1;
    }

    path[depth] = '.'; // kiri
    if (charToMorse(root->left, target, path, depth + 1))
        return 1;

    path[depth] = '-'; // kanan
    if (charToMorse(root->right, target, path, depth + 1))
        return 1;

    return 0;
}
char MorseToChar(BinTree root, char *path)
{
    BinTree curr = root;
    if (curr == NULL)
    {
        return '*';
    }
    for (int i = 0; path[i] != '\0'; i++)
    {
        if (curr == NULL)
        {
            return ')';
        }
        if (path[i] == '.')
        {
            curr = Left(curr);
        }
        else if (path[i] == '-')
        {
            curr = Right(curr);
        }
        else
        {
            return '(';
        }
    }
    if (curr != NULL)
    {
        return Info(curr);
    }
    return ')';
}

void MorseStringToText(BinTree root, const char *morseInput, char *output)
{
    char token[100][10]; // Maks 100 morse tokens, masing2 maks 10 char
    int i = 0, j = 0, k = 0;

    // Memisahkan morseInput ke dalam token
    while (morseInput[i] != '\0') {
        if (morseInput[i] != ' ') {
            token[k][j++] = morseInput[i];
        } else {
            token[k][j] = '\0'; // akhiri token
            k++;
            j = 0;
        }
        i++;
    }
    token[k][j] = '\0'; // terakhir
    int numTokens = k + 1;

    // Konversi token morse ke karakter
    for (int idx = 0; idx < numTokens; idx++) {
        output[idx] = MorseToChar(root, token[idx]);
    }
    output[numTokens] = '\0'; // akhir string output
}

