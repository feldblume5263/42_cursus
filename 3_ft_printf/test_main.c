#include <stdio.h>
#include "ft_printf.h"

int			main(void)
{
	printf("\n");
	printf("my result = %d\n", ft_printf("ft_printf = |%4.d|\n", 0));
	printf("ra result = %d\n",    printf("   printf = |%4.d|\n", 0));
	printf("\n");
}
