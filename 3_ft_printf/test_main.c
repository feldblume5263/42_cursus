#include <stdio.h>
#include "ft_printf.h"

int			main(void)
{
	printf("\n");
	printf("my result = %d\n", ft_printf("ft_printf = |%.9d|\n", -234));
	printf("ra result = %d\n", printf("   printf = |%.9d|\n", -234));
	printf("\n");

}
