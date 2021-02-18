#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		ft_strlen(char const *str);
char	*ft_strcpy(char *dest, char const *src);
int		ft_strcmp(char const *dest, char const *src);

int		main(void)
{
	char	len[] = "\0";
	char	cpy_src[10] = "\0";
	char	cpy_des[10];

	printf("ft_strlen(\"abcd\") = %d\n", ft_strlen(len));
	printf("ft_strcpy(des, \"good\") = %s\n", ft_strcpy(cpy_des, cpy_src));
	printf("ft_strcmp() = %d\n", ft_strcmp(cpy_src, len));
	printf("strcmp() = %d\n", strcmp(cpy_src, len));

	return (0);
}
