/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:10:36 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/03 15:58:09 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	printf("***************************************\n");
	printf("*********** printf_int_test ***********\n");
	printf("***************************************\n");
	printf("made by junhpark @ 42Seoul");
	printf("\n");

	printf("\n***************************************\n");

	printf("\nprintf(\"%%x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%x|\n", 152736) - 14);

	printf("\nprintf(\"%%5x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%5x|\n", 152736) - 14);

	printf("\nprintf(\"%%7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%7x|\n", 152736) - 14);

	printf("\nprintf(\"%%3x\", 152736)\n");
	printf("\t\treturn : %x", printf("\t\tresult : |%3x|\n", 152736) - 14);

	printf("\nprintf(\"%%0x\", 152736)\n");
	/*printf("\t\tresult : |%0x|\n", 152736);*/ printf("warning\n");

	printf("\nprintf(\"%%-x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-x|\n", 152736) - 14);

	printf("\nprintf(\"%%-5x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-5x|\n", 152736) - 14);

	printf("\nprintf(\"%%-7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-7x|\n", 152736) - 14);

	printf("\nprintf(\"%%-3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-3x|\n", 152736) - 14);

	printf("\nprintf(\"%%-0x\", 152736)\n");
	/*printf("\t\tresult : |%-0x|\n", 152736);*/ printf("warning\n");

	printf("\nprintf(\"%%---7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%--7x|\n", 152736) - 14);

	printf("\nprintf(\"%%--3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%--3x|\n", 152736) - 14);

	printf("\nprintf(\"%%.x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%.x|\n", 152736) - 14);

	printf("\n**printf(\"%%.7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%.7x|\n", 152736) - 14);

	printf("\nprintf(\"%%.3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%.3x|\n", 152736) - 14);

	printf("\nprintf(\"%%.0x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%.0x|\n", 152736) - 14);

	printf("\n**printf(\"%%-.7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-.7x|\n", 152736) - 14);

	printf("\nprintf(\"%%-7.x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-7.x|\n", 152736) - 14);

	printf("\nprintf(\"%%-.3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-.3x|\n", 152736) - 14);

	printf("\nprintf(\"%%-3.x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-3.x|\n", 152736) - 14);

	printf("\nprintf(\"%%7.7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%7.7x|\n", 152736) - 14);

	printf("\nprintf(\"%%7.3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%7.3x|\n", 152736) - 14);

	printf("\nprintf(\"%%3.7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%3.7x|\n", 152736) - 14);

	printf("\n**printf(\"%%9.7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%9.7x|\n", 152736) - 14);

	printf("\n**printf(\"%%7.9x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%7.9x|\n", 152736) - 14);

	printf("\nprintf(\"%%-7.3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-7.3x|\n", 152736) - 14);

	printf("\nprintf(\"%%-9.7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-9.7x|\n", 152736) - 14);

	printf("\nprintf(\"%%-9.3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-9.3x|\n", 152736) - 14);

	printf("\nprintf(\"%%3.9x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%3.9x|\n", 152736) - 14);

	printf("\nprintf(\"%%-3.9x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-3.9x|\n", 152736) - 14);

	printf("\nprintf(\"%%0x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%0x|\n", 152736) - 14);

	printf("\nprintf(\"%%07x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%07x|\n", 152736) - 14);

	printf("\nprintf(\"%%05x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%05x|\n", 152736) - 14);

	printf("\nprintf(\"%%03x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%03x|\n", 152736) - 14);

	printf("\nprintf(\"%%0.9x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%0.9x|\n", 152736) - 14);

	printf("\nprintf(\"%%0.5x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%0.5x|\n", 152736) - 14);

	printf("\nprintf(\"%%3.0x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%x|\n", 152736) - 14);

	printf("\nprintf(\"%%5.0x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%5.0x|\n", 152736) - 14);

	printf("\nprintf(\"%%7.0x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%7.0x|\n", 152736) - 14);

	printf("\nprintf(\"%%7.3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%7.3x|\n", 152736) - 14);

	printf("\nprintf(\"%%7.5x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%7.5x|\n", 152736) - 14);

	printf("\nprintf(\"%%7.7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%7.7x|\n", 152736) - 14);

	printf("\nprintf(\"%%5.3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%5.3x|\n", 152736) - 14);

	printf("\nprintf(\"%%5.5x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%5.5x|\n", 152736) - 14);

	printf("\nprintf(\"%%5.7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%5.7x|\n", 152736) - 14);

	printf("\nprintf(\"%%3.3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%3.3x|\n", 152736) - 14);

	printf("\nprintf(\"%%3.5x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%3.5x|\n", 152736) - 14);

	printf("\nprintf(\"%%3.7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%3.7x|\n", 152736) - 14);

	printf("\nprintf(\"%%-0x\", 152736)\n");
	/*printf("|%-0x|\n", 152736);*/ printf("warning\n");

	printf("\nprintf(\"%%-07x\", 152736)\n");
	/*printf("|%-07x|\n", 152736);*/ printf("warning\n");

	printf("\nprintf(\"%%-05x\", 152736)\n");
	/*printf("|%-05x|\n", 152736);*/ printf("warning\n");

	printf("\nprintf(\"%%-03x\", 152736)\n");
	/*printf("|%-03x|\n", 152736);*/ printf("warning\n");

	printf("\nprintf(\"%%-0.9x\", 152736)\n");
	/*printf("|%-0.9x|\n", 152736) - 14);*/ printf("warning\n");

	printf("\nprintf(\"%%-0.5x\", 152736)\n");
	/*printf("|%-0.5x|\n", 152736);*/ printf("warning\n");

	printf("\nprintf(\"%%-3.0x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-3.0x|\n", 152736) - 14);

	printf("\nprintf(\"%%-5.0x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-5.0x|\n", 152736) - 14);

	printf("\nprintf(\"%%-7.0x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-7.0x|\n", 152736) - 14);

	printf("\nprintf(\"%%-7.3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-7.3x|\n", 152736) - 14);

	printf("\nprintf(\"%%-7.5x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-7.5x|\n", 152736) - 14);

	printf("\nprintf(\"%%-7.7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-7.7x|\n", 152736) - 14);

	printf("\nprintf(\"%%-5.3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-5.3x|\n", 152736) - 14);

	printf("\nprintf(\"%%-5.5x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-5.5x|\n", 152736) - 14);

	printf("\nprintf(\"%%-5.7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-5.7x|\n", 152736) - 14);

	printf("\nprintf(\"%%-3.3x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-3.3x|\n", 152736) - 14);

	printf("\nprintf(\"%%-3.5x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-3.5x|\n", 152736) - 14);

	printf("\nprintf(\"%%-3.7x\", 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-3.7x|\n", 152736) - 14);

	printf("\nprintf(\"%%*x\", 5, 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%*x|\n", 5, 152736) - 14);

	printf("\nprintf(\"%%*x\", 3, 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%*x|\n", 3, 152736) - 14);

	printf("\nprintf(\"%%*x\", 7, 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%*x|\n", 7, 152736) - 14);

	printf("\nprintf(\"%%0*x\", 7, 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%0*x|\n", 7, 152736) - 14);

	printf("\nprintf(\"%%-0*x\", 7, 152736)\n");
	/*printf("\t\treturn : %x\n", printf("\t\tresult : |%-0*x|\n", 7, 152736) - 14);*/ printf("warning");

	printf("\nprintf(\"%%*.7x\", 5, 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%*.7x|\n", 5, 152736) - 14);

	printf("\nprintf(\"%%*.7x\", 9, 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%*.7x|\n", 9, 152736) - 14);

	printf("\n** printf(\"%%-*.7x\", 9, 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-*.7x|\n", 9, 152736) - 14);

	printf("\n** printf(\"%%*.7x\", -9, 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%*.7x|\n", -9, 152736) - 14);

	printf("\n** printf(\"%%-*.7x\", -9, 152736)\n");
	printf("\t\treturn : %x\n", printf("\t\tresult : |%-*.7x|\n", -9, 152736) - 14);
}
