nasm -fmacho64 *.s
gcc -c main.c
gcc -o test  *.o
