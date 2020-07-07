#include <stdio.h>
#include "ft_printf.h"

int			main(void)
{

	printf("my result = %d\n", ft_printf("ft_printf = |%3.s|\n", "abcdef"));
	printf("ra result = %d\n",    printf("   printf = |%3.s|\n", "abcdef"));


	/*
	printf("\n");
	// w > p > s
	printf("my result = %d\n", ft_printf("\nft_printf = |%9.8s|\n", "abcdef"));
	printf("ra result = %d\n",    printf("   printf = |%9.8s|\n", "abcdef"));
	//printf = |   abcdef|

	// w > s > p
	printf("my result = %d\n", ft_printf("\nft_printf = |%9.3s|\n", "abcdef"));
	printf("ra result = %d\n",    printf("   printf = |%9.3s|\n", "abcdef"));
	//printf = |      abc|

	// p > w > s
	printf("my result = %d\n", ft_printf("\nft_printf = |%8.9s|\n", "abcdef"));
	printf("ra result = %d\n",    printf("   printf = |%8.9s|\n", "abcdef"));
	//printf = |  abcdef|

	// p > s > w
	printf("my result = %d\n", ft_printf("\nft_printf = |%9.3s|\n", "abcdef"));
	printf("ra result = %d\n",    printf("\n   printf = |%9.3s|\n", "abcdef"));
	//printf = |      abc|

	// s > w > p
	printf("my result = %d\n", ft_printf("\nft_printf = |%7.5s|\n", "abcdefgh"));
	printf("ra result = %d\n",    printf("\n   printf = |%7.5s|\n", "abcdefgh"));
	//printf = |  abcde|

	// s > p > w
	printf("my result = %d\n", ft_printf("\nft_printf = |%5.7s|\n", "abcdefgh"));
	printf("ra result = %d\n",    printf("\n   printf = |%5.7s|\n", "abcdefgh"));
	//printf = |abcdefg|

	// s = NULL, w > p
	printf("my result = %d\n", ft_printf("\nft_printf = |%7.5s|\n", NULL));
	printf("ra result = %d\n",    printf("\n   printf = |%7.5s|\n", NULL));
	//printf = |  (null|

	// s = NULL, p > w
	printf("my result = %d\n", ft_printf("\nft_printf = |%5.7s|\n", NULL));
	printf("ra result = %d\n",    printf("\n   printf = |%5.7s|\n", NULL));
	//printf = |(null)|

	// w = 0, p > s
	printf("my result = %d\n", ft_printf("\nft_printf = |%.7s|\n", "abcde"));
	printf("ra result = %d\n",    printf("\n   printf = |%.7s|\n", "abcde"));
	//printf = |abcde|

	// w = 0, s > p
	printf("my result = %d\n", ft_printf("\nft_printf = |%.3s|\n", "abcde"));
	printf("ra result = %d\n",    printf("\n   printf = |%.3s|\n", "abcde"));
	//printf = |abc|

	// p = 0, w > s
	printf("my result = %d\n", ft_printf("\nft_printf = |%7.0s|\n", "abcde"));
	printf("ra result = %d\n",    printf("\n   printf = |%7.0s|\n", "abcde"));
	//printf = |       |

	// p = 0, s > w
	printf("my result = %d\n", ft_printf("\nft_printf = |%3.0s|\n", "abcde"));
	printf("ra result = %d\n",    printf("\n   printf = |%3.0s|\n", "abcde"));
	//printf = |   |
	*/
	printf("\n");
}
