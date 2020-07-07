#include <stdio.h>
#include "ft_printf.h"

int			main(void)
{
	char		*ptr;

	printf("\n");
	printf("my result = %d\n", ft_printf("ft_printf = |%.5s|\n", "abc"));
	printf("ra result = %d\n",    printf("   printf = |%.5s|\n", "abc"));
	printf("\n");
}
