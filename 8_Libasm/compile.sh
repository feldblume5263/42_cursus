nasm -fmacho64 ft_strlen.s
nasm -fmacho64 ft_strcpy.s
nasm -fmacho64 ft_strcmp.s
gcc -c main.c
gcc -o test  *.o
