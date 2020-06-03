/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %%_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:03:27 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/03 16:18:53 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	printf("***************************************\n");
	printf("*********** printf_%%%%_test ************\n");
	printf("***************************************\n");
	printf("made by junhpark @ 42Seoul");
	printf("\n");

	printf("\n***************************************\n");

	printf("\nprintf(\"%%%%\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%%|\n") - 14);

	printf("\nprintf(\"%%5%%\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%5%|\n") - 14);

	printf("\nprintf(\"%%05%%\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%05%|\n") - 14);

	printf("\nprintf(\"%%.%%\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%.%|\n") - 14);

	printf("\nprintf(\"%%.5%%\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%.5%|\n") - 14);

	printf("\nprintf(\"%%5.3%%\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%5.3%|\n") - 14);

	printf("\nprintf(\"%%-5%%\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-5%|\n") - 14);

	printf("\nprintf(\"%%-5.9%%\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-5.9%|\n") - 14);

	printf("\nprintf(\"%%*%%\", 5)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%*%|\n", 5) - 14);

	printf("\nprintf(\"%%*%%\", -5)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%*%|\n", -5) - 14);

	printf("\nprintf(\"%%-%%\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-%|\n") - 14);

	printf("\nprintf(\"%%-5%%\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-5%|\n") - 14);

	printf("\nprintf(\"%%-*%%\", 5)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-*%|\n", 5) - 14);

	printf("\nprintf(\"%%-*.3%%\", 7)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-*.3%|\n", 7) - 14);

	printf("\nprintf(\"%%*.7%%\", 3)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%*.7%|\n", 3) - 14);

	printf("\nprintf(\"%%0*%%\", 5)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%0*%|\n", 5) - 14);

	printf("\nprintf(\"%%-05%%\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-05%|\n") - 14);
}
