#!/bin/sh

# Cek apakah parameter pertama diberikan
if [ -z "$1" ]; then
    echo "Usage: $0 <ADT|Morse>"
    exit 1
fi

# Kompilasi berdasarkan parameter pertama
if [ "$1" = "ADT" ]; then
    gcc -o SC1-ADT/main -ISC1-ADT/include SC1-ADT/main.c SC1-ADT/lib/binarytree.c SC1-ADT/lib/morse.c
elif [ "$1" = "Morse" ]; then
    gcc -o SC2-Morse/main -ISC2-Morse/include SC2-Morse/main.c SC2-Morse/lib/binarytree.c SC2-Morse/lib/morse.c
else
    echo "Invalid parameter. Use 'ADT' or 'Morse'."
    exit 1
fi

# Cek apakah kompilasi berhasil
if [ $? -eq 0 ]; then
    clear
    echo "Compilation successful. Running the program..."
    if [ "$1" = "ADT" ]; then
        ./SC1-ADT/main
    elif [ "$1" = "Morse" ]; then
        ./SC2-Morse/main
    fi
else
    echo "Compilation failed."
fi