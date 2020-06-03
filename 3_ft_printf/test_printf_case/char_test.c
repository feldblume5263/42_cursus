/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:52:07 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/03 15:49:52 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	printf("***************************************\n");
	printf("*********** printf_char_test **********\n");
	printf("***************************************\n");
	printf("made by junhpark @ 42Seoul");
	printf("\n");

	printf("\n***************************************\n");

	printf("\nprintf(\"%%c\", 'a')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%c|\n", 'a') - 14);

	printf("\nprintf(\"%%0c\", 'a')\n");
	/*printf("\t\treturn : %d\n", printf("\t\tresult : |%0c|\n", 'a') - 14);*/ printf("warnging\n");

	printf("\nprintf(\"%%1c\", 'a')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%1c|\n", 'a') - 14);

	printf("\nprintf(\"%%3c\", 'a')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%3c|\n", 'a') - 14);

	printf("\nprintf(\"%%5c\", 'a')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%5c|\n", 'a') - 14);

	printf("\nprintf(\"%%c\", 0)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%c|\n", 0) - 14);

	printf("\nprintf(\"%%3c\", 0)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%3c|\n", 0) - 14);

	printf("\nprintf(\"%%c\", '\\0')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%c|\n", '\0') - 14);

	printf("\nprintf(\"%%3c\", '\\0')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%3c|\n", '\0') - 14);

	printf("\nprintf(\"%%-c\", 'a')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-c|\n", 'a') - 14);

	printf("\nprintf(\"%%-3c\", 'a')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-3c|\n", 'a') - 14);

	printf("\nprintf(\"%%.c\", 'a')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%.c|\n", 'a') - 14);

	printf("\nprintf(\"%%.3c\", 'a')\n");
	/*printf("\t\treturn : %d\n", printf("\t\tresult : |%.3c|\n", 'a') - 14);*/ printf("warning\n");

	printf("\nprintf(\"%%3.5c\", 'a')\n");
	/*printf("\t\treturn : %d\n", printf("\t\tresult : |%3.5c|\n", 'a') - 14);*/ printf("warning\n");

	printf("\nprintf(\"%%5.c\", 'a')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%5.c|\n", 'a') - 14);

	printf("\nprintf(\"%%0c\", 'a')\n");
	/*printf("\t\treturn : %d\n", printf("\t\tresult : |%0c|\n", 'a') - 14);*/ printf("warning\n");

	printf("\nprintf(\"%%03c\", 'a')\n");
	/*printf("\t\treturn : %d\n", printf("\t\tresult : |%03c|\n", 'a') - 14);*/ printf("warning\n");

	printf("\nprintf(\"%%*c\", 3, 'a')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%*c|\n", 3, 'a') - 14);

	printf("\nprintf(\"%%*c\", 'a')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-*c|\n", 3, 'a') - 14);

	printf("\nprintf(\"%%*c\", -3, 'a')\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%*c|\n", -3, 'a') - 14);

}
