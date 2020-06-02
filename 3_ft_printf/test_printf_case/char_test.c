/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:52:07 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/02 18:00:14 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	printf("***************************************\n");
	printf("*********** printf_char_test ***********\n");
	printf("***************************************\n");
	printf("made by junhpark @ 42Seoul");
	printf("\n");

	printf("\n***************************************\n");
	printf("\n0. printf(\"%%c\", ...);\n");

	printf("\nprintf(\"%%c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%c|\n", 'a'));

	printf("\n***************************************\n");
	printf("\n1. printf(\"%%(num)c\", ...);\n");

	printf("\nprintf(\"%%5c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%5c|\n", 'a'));

	printf("\nprintf(\"%%7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%7c|\n", 'a'));

	printf("\nprintf(\"%%3c\", 'a')\n");
	printf("\t\treturn : %c", printf("\t\tresult : |%3c|\n", 'a'));

	printf("\nprintf(\"%%0c\", 'a')\n");
	/*printf("\t\tresult : |%0c|\n", 'a');*/ printf("warning\n");

	printf("\n***************************************\n");
	printf("\n2. printf(\"%%-(num)c\", ...);\n");

	printf("\nprintf(\"%%-c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-c|\n", 'a'));

	printf("\nprintf(\"%%-5c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-5c|\n", 'a'));

	printf("\nprintf(\"%%-7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-7c|\n", 'a'));

	printf("\nprintf(\"%%-3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-3c|\n", 'a'));

	printf("\nprintf(\"%%-0c\", 'a')\n");
	/*printf("\t\tresult : |%-0c|\n", 'a');*/ printf("warning\n");

	printf("\nprintf(\"%%---7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%--7c|\n", 'a'));

	printf("\nprintf(\"%%--3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%--3c|\n", 'a'));

	printf("\n***************************************\n");
	printf("\n3. printf(\"%%.(num)c\", ...);\n");

	printf("\nprintf(\"%%.c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%.c|\n", 'a'));

	printf("\n**printf(\"%%.7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%.7c|\n", 'a'));

	printf("\nprintf(\"%%.3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%.3c|\n", 'a'));

	printf("\nprintf(\"%%.0c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%.0c|\n", 'a'));

	printf("\n**printf(\"%%-.7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-.7c|\n", 'a'));

	printf("\nprintf(\"%%-7.c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-7.c|\n", 'a'));

	printf("\nprintf(\"%%-.3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-.3c|\n", 'a'));

	printf("\nprintf(\"%%-3.c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-3.c|\n", 'a'));

	printf("\nprintf(\"%%7.7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%7.7c|\n", 'a'));

	printf("\nprintf(\"%%7.3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%7.3c|\n", 'a'));

	printf("\nprintf(\"%%3.7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%3.7c|\n", 'a'));

	printf("\n**printf(\"%%9.7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%9.7c|\n", 'a'));

	printf("\n**printf(\"%%7.9c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%7.9c|\n", 'a'));

	printf("\nprintf(\"%%-7.3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-7.3c|\n", 'a'));

	printf("\nprintf(\"%%-9.7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-9.7c|\n", 'a'));

	printf("\nprintf(\"%%-9.3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-9.3c|\n", 'a'));

	printf("\nprintf(\"%%3.9c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%3.9c|\n", 'a'));

	printf("\nprintf(\"%%-3.9c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-3.9c|\n", 'a'));

	printf("\n***************************************\n");
	printf("\n4. printf(\"%%0c\", ...);\n");

	printf("\nprintf(\"%%0c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%0c|\n", 'a'));

	printf("\nprintf(\"%%07c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%07c|\n", 'a'));

	printf("\nprintf(\"%%05c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%05c|\n", 'a'));

	printf("\nprintf(\"%%03c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%03c|\n", 'a'));

	printf("\nprintf(\"%%0.9c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%0.9c|\n", 'a'));

	printf("\nprintf(\"%%0.5c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%0.5c|\n", 'a'));

	printf("\nprintf(\"%%3.0c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%c|\n", 'a'));

	printf("\nprintf(\"%%5.0c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%5.0c|\n", 'a'));

	printf("\nprintf(\"%%7.0c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%7.0c|\n", 'a'));

	printf("\nprintf(\"%%7.3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%7.3c|\n", 'a'));

	printf("\nprintf(\"%%7.5c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%7.5c|\n", 'a'));

	printf("\nprintf(\"%%7.7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%7.7c|\n", 'a'));

	printf("\nprintf(\"%%5.3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%5.3c|\n", 'a'));

	printf("\nprintf(\"%%5.5c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%5.5c|\n", 'a'));

	printf("\nprintf(\"%%5.7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%5.7c|\n", 'a'));

	printf("\nprintf(\"%%3.3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%3.3c|\n", 'a'));

	printf("\nprintf(\"%%3.5c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%3.5c|\n", 'a'));

	printf("\nprintf(\"%%3.7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%3.7c|\n", 'a'));

	printf("\nprintf(\"%%-0c\", 'a')\n");
	/*printf("|%-0c|\n", 'a');*/ printf("warning\n");

	printf("\nprintf(\"%%-07c\", 'a')\n");
	/*printf("|%-07c|\n", 'a');*/ printf("warning\n");

	printf("\nprintf(\"%%-05c\", 'a')\n");
	/*printf("|%-05c|\n", 'a');*/ printf("warning\n");

	printf("\nprintf(\"%%-03c\", 'a')\n");
	/*printf("|%-03c|\n", 'a');*/ printf("warning\n");

	printf("\nprintf(\"%%-0.9c\", 'a')\n");
	/*printf("|%-0.9c|\n", 'a'));*/ printf("warning\n");

	printf("\nprintf(\"%%-0.5c\", 'a')\n");
	/*printf("|%-0.5c|\n", 'a');*/ printf("warning\n");

	printf("\nprintf(\"%%-3.0c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-3.0c|\n", 'a'));

	printf("\nprintf(\"%%-5.0c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-5.0c|\n", 'a'));

	printf("\nprintf(\"%%-7.0c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-7.0c|\n", 'a'));

	printf("\nprintf(\"%%-7.3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-7.3c|\n", 'a'));

	printf("\nprintf(\"%%-7.5c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-7.5c|\n", 'a'));

	printf("\nprintf(\"%%-7.7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-7.7c|\n", 'a'));

	printf("\nprintf(\"%%-5.3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-5.3c|\n", 'a'));

	printf("\nprintf(\"%%-5.5c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-5.5c|\n", 'a'));

	printf("\nprintf(\"%%-5.7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-5.7c|\n", 'a'));

	printf("\nprintf(\"%%-3.3c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-3.3c|\n", 'a'));

	printf("\nprintf(\"%%-3.5c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-3.5c|\n", 'a'));

	printf("\nprintf(\"%%-3.7c\", 'a')\n");
	printf("\t\treturn : %c\n", printf("\t\tresult : |%-3.7c|\n", 'a'));
}
