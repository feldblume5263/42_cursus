nasm -fmacho64 ft_strlen.s
nasm -fmacho64 ft_strcpy.s
nasm -fmacho64 ft_strcmp.s
nasm -fmacho64 ft_write.s
nasm -fmacho64 ft_read.s
nasm -fmacho64 ft_strdup.s
gcc -O3 -c main.c
gcc -O3 -o test  *.o
