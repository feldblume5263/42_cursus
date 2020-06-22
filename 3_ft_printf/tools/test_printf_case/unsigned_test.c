/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:10:34 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/03 15:35:37 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	printf("***************************************\n");
	printf("******* printf_unsignedint_test *******\n");
	printf("***************************************\n");
	printf("made by junhpark @ 42Seoul");
	printf("\n");

	printf("\n***************************************\n");

	printf("\nprintf(\"%%u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%u|\n", 12345) - 14);

	printf("\nprintf(\"%%5u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%5u|\n", 12345) - 14);

	printf("\nprintf(\"%%7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%7u|\n", 12345) - 14);

	printf("\nprintf(\"%%3u\", 12345)\n");
	printf("\t\treturn : %u", printf("\t\tresult : |%3u|\n", 12345) - 14);

	printf("\nprintf(\"%%0u\", 12345)\n");
	/*printf("\t\tresult : |%0u|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%-u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-u|\n", 12345) - 14);

	printf("\nprintf(\"%%-5u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-5u|\n", 12345) - 14);

	printf("\nprintf(\"%%-7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-7u|\n", 12345) - 14);

	printf("\nprintf(\"%%-3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-3u|\n", 12345) - 14);

	printf("\nprintf(\"%%-0u\", 12345)\n");
	/*printf("\t\tresult : |%-0u|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%---7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%--7u|\n", 12345) - 14);

	printf("\nprintf(\"%%--3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%--3u|\n", 12345) - 14);

	printf("\nprintf(\"%%.u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%.u|\n", 12345) - 14);

	printf("\n**printf(\"%%.7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%.7u|\n", 12345) - 14);

	printf("\nprintf(\"%%.3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%.3u|\n", 12345) - 14);

	printf("\nprintf(\"%%.0u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%.0u|\n", 12345) - 14);

	printf("\n**printf(\"%%-.7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-.7u|\n", 12345) - 14);

	printf("\nprintf(\"%%-7.u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-7.u|\n", 12345) - 14);

	printf("\nprintf(\"%%-.3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-.3u|\n", 12345) - 14);

	printf("\nprintf(\"%%-3.u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-3.u|\n", 12345) - 14);

	printf("\nprintf(\"%%7.7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%7.7u|\n", 12345) - 14);

	printf("\nprintf(\"%%7.3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%7.3u|\n", 12345) - 14);

	printf("\nprintf(\"%%3.7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%3.7u|\n", 12345) - 14);

	printf("\n**printf(\"%%9.7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%9.7u|\n", 12345) - 14);

	printf("\n**printf(\"%%7.9u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%7.9u|\n", 12345) - 14);

	printf("\nprintf(\"%%-7.3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-7.3u|\n", 12345) - 14);

	printf("\nprintf(\"%%-9.7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-9.7u|\n", 12345) - 14);

	printf("\nprintf(\"%%-9.3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-9.3u|\n", 12345) - 14);

	printf("\nprintf(\"%%3.9u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%3.9u|\n", 12345) - 14);

	printf("\nprintf(\"%%-3.9u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-3.9u|\n", 12345) - 14);

	printf("\nprintf(\"%%0u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%0u|\n", 12345) - 14);

	printf("\nprintf(\"%%07u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%07u|\n", 12345) - 14);

	printf("\nprintf(\"%%05u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%05u|\n", 12345) - 14);

	printf("\nprintf(\"%%03u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%03u|\n", 12345) - 14);

	printf("\nprintf(\"%%0.9u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%0.9u|\n", 12345) - 14);

	printf("\nprintf(\"%%0.5u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%0.5u|\n", 12345) - 14);

	printf("\nprintf(\"%%3.0u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%u|\n", 12345) - 14);

	printf("\nprintf(\"%%5.0u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%5.0u|\n", 12345) - 14);

	printf("\nprintf(\"%%7.0u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%7.0u|\n", 12345) - 14);

	printf("\nprintf(\"%%7.3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%7.3u|\n", 12345) - 14);

	printf("\nprintf(\"%%7.5u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%7.5u|\n", 12345) - 14);

	printf("\nprintf(\"%%7.7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%7.7u|\n", 12345) - 14);

	printf("\nprintf(\"%%5.3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%5.3u|\n", 12345) - 14);

	printf("\nprintf(\"%%5.5u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%5.5u|\n", 12345) - 14);

	printf("\nprintf(\"%%5.7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%5.7u|\n", 12345) - 14);

	printf("\nprintf(\"%%3.3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%3.3u|\n", 12345) - 14);

	printf("\nprintf(\"%%3.5u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%3.5u|\n", 12345) - 14);

	printf("\nprintf(\"%%3.7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%3.7u|\n", 12345) - 14);

	printf("\nprintf(\"%%-0u\", 12345)\n");
	/*printf("|%-0u|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%-07u\", 12345)\n");
	/*printf("|%-07u|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%-05u\", 12345)\n");
	/*printf("|%-05u|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%-03u\", 12345)\n");
	/*printf("|%-03u|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%-0.9u\", 12345)\n");
	/*printf("|%-0.9u|\n", 12345) - 14);*/ printf("warning\n");

	printf("\nprintf(\"%%-0.5u\", 12345)\n");
	/*printf("|%-0.5u|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%-3.0u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-3.0u|\n", 12345) - 14);

	printf("\nprintf(\"%%-5.0u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-5.0u|\n", 12345) - 14);

	printf("\nprintf(\"%%-7.0u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-7.0u|\n", 12345) - 14);

	printf("\nprintf(\"%%-7.3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-7.3u|\n", 12345) - 14);

	printf("\nprintf(\"%%-7.5u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-7.5u|\n", 12345) - 14);

	printf("\nprintf(\"%%-7.7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-7.7u|\n", 12345) - 14);

	printf("\nprintf(\"%%-5.3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-5.3u|\n", 12345) - 14);

	printf("\nprintf(\"%%-5.5u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-5.5u|\n", 12345) - 14);

	printf("\nprintf(\"%%-5.7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-5.7u|\n", 12345) - 14);

	printf("\nprintf(\"%%-3.3u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-3.3u|\n", 12345) - 14);

	printf("\nprintf(\"%%-3.5u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-3.5u|\n", 12345) - 14);

	printf("\nprintf(\"%%-3.7u\", 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-3.7u|\n", 12345) - 14);

	printf("\nprintf(\"%%*u\", 5, 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%*u|\n", 5, 12345) - 14);

	printf("\nprintf(\"%%*u\", 3, 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%*u|\n", 3, 12345) - 14);

	printf("\nprintf(\"%%*u\", 7, 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%*u|\n", 7, 12345) - 14);

	printf("\nprintf(\"%%0*u\", 7, 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%0*u|\n", 7, 12345) - 14);

	printf("\nprintf(\"%%-0*u\", 7, 12345)\n");
	/*printf("\t\treturn : %u\n", printf("\t\tresult : |%-0*u|\n", 7, 12345) - 14);*/ printf("warning");

	printf("\nprintf(\"%%*.7u\", 5, 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%*.7u|\n", 5, 12345) - 14);

	printf("\nprintf(\"%%*.7u\", 9, 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%*.7u|\n", 9, 12345) - 14);

	printf("\n** printf(\"%%-*.7u\", 9, 12345)\n");
	printf("\t\treturn : %u\n", printf("\t\tresult : |%-*.7u|\n", 9, 12345) - 14);
}
