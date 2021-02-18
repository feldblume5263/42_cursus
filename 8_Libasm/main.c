#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		ft_strlen(char const *str);
char	*ft_strcpy(char *dest, char const *src);
int		ft_strcmp(char const *dest, char const *src);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
ssize_t	ft_read(int fd, void const *buf, size_t nbyte);
int		ft_strdup(char const *ptr);

int		main(void)
{
	char	len[10] = "abcd";
	char	cpy_src[10] "abcdef";
	char	cpy_des[10];
	char	read[100];

	printf("ft_strlen(\"abcd\") = %d\n", ft_strlen(len));
	printf("ft_strcpy(des, \"good\") = %s\n", ft_strcpy(cpy_des, cpy_src));
	printf("ft_strcmp() = %d\n", ft_strcmp(cpy_src, len));
	printf("strcmp() = %d\n", strcmp(cpy_src, len));
	ft_write(1, "abc\n", 4);
	ft_read(0, read, 100);
	printf("%s", read);
	printf("%d\n", ft_strdup(read));
	return (0);
}
