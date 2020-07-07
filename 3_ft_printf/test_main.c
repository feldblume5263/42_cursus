#include <stdio.h>
#include "ft_printf.h"

int			main(void)
{
	char		*ptr;

	printf("\n");
	printf("my result = %d\n", ft_printf("ft_printf = |%-4.x|\n", 10));
	printf("ra result = %d\n",    printf("   printf = |%-4.x|\n", 10));
	printf("\n");
}
