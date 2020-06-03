/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 13:09:21 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/03 13:11:08 by junhpark         ###   ########.fr       */
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
	printf("\n0. printf(\"%%d\", ...);\n");

	printf("\nprintf(\"%%d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%d|\n", 12345) - 14);

	printf("\n***************************************\n");
	printf("\n1. printf(\"%%(num)d\", ...);\n");

	printf("\nprintf(\"%%5d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%5d|\n", 12345) - 14);

	printf("\nprintf(\"%%7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%7d|\n", 12345) - 14);

	printf("\nprintf(\"%%3d\", 12345)\n");
	printf("\t\treturn : %d", printf("\t\tresult : |%3d|\n", 12345) - 14);

	printf("\nprintf(\"%%0d\", 12345)\n");
	/*printf("\t\tresult : |%0d|\n", 12345);*/ printf("warning\n");

	printf("\n***************************************\n");
	printf("\n2. printf(\"%%-(num)d\", ...);\n");

	printf("\nprintf(\"%%-d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-d|\n", 12345) - 14);

	printf("\nprintf(\"%%-5d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-5d|\n", 12345) - 14);

	printf("\nprintf(\"%%-7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-7d|\n", 12345) - 14);

	printf("\nprintf(\"%%-3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-3d|\n", 12345) - 14);

	printf("\nprintf(\"%%-0d\", 12345)\n");
	/*printf("\t\tresult : |%-0d|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%---7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%--7d|\n", 12345) - 14);

	printf("\nprintf(\"%%--3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%--3d|\n", 12345) - 14);

	printf("\n***************************************\n");
	printf("\n3. printf(\"%%.(num)d\", ...);\n");

	printf("\nprintf(\"%%.d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%.d|\n", 12345) - 14);

	printf("\n**printf(\"%%.7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%.7d|\n", 12345) - 14);

	printf("\nprintf(\"%%.3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%.3d|\n", 12345) - 14);

	printf("\nprintf(\"%%.0d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%.0d|\n", 12345) - 14);

	printf("\n**printf(\"%%-.7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-.7d|\n", 12345) - 14);

	printf("\nprintf(\"%%-7.d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-7.d|\n", 12345) - 14);

	printf("\nprintf(\"%%-.3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-.3d|\n", 12345) - 14);

	printf("\nprintf(\"%%-3.d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-3.d|\n", 12345) - 14);

	printf("\nprintf(\"%%7.7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%7.7d|\n", 12345) - 14);

	printf("\nprintf(\"%%7.3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%7.3d|\n", 12345) - 14);

	printf("\nprintf(\"%%3.7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%3.7d|\n", 12345) - 14);

	printf("\n**printf(\"%%9.7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%9.7d|\n", 12345) - 14);

	printf("\n**printf(\"%%7.9d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%7.9d|\n", 12345) - 14);

	printf("\nprintf(\"%%-7.3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-7.3d|\n", 12345) - 14);

	printf("\nprintf(\"%%-9.7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-9.7d|\n", 12345) - 14);

	printf("\nprintf(\"%%-9.3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-9.3d|\n", 12345) - 14);

	printf("\nprintf(\"%%3.9d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%3.9d|\n", 12345) - 14);

	printf("\nprintf(\"%%-3.9d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-3.9d|\n", 12345) - 14);

	printf("\n***************************************\n");
	printf("\n4. printf(\"%%0d\", ...);\n");

	printf("\nprintf(\"%%0d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%0d|\n", 12345) - 14);

	printf("\nprintf(\"%%07d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%07d|\n", 12345) - 14);

	printf("\nprintf(\"%%05d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%05d|\n", 12345) - 14);

	printf("\nprintf(\"%%03d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%03d|\n", 12345) - 14);

	printf("\nprintf(\"%%0.9d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%0.9d|\n", 12345) - 14);

	printf("\nprintf(\"%%0.5d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%0.5d|\n", 12345) - 14);

	printf("\nprintf(\"%%3.0d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%d|\n", 12345) - 14);

	printf("\nprintf(\"%%5.0d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%5.0d|\n", 12345) - 14);

	printf("\nprintf(\"%%7.0d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%7.0d|\n", 12345) - 14);

	printf("\nprintf(\"%%7.3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%7.3d|\n", 12345) - 14);

	printf("\nprintf(\"%%7.5d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%7.5d|\n", 12345) - 14);

	printf("\nprintf(\"%%7.7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%7.7d|\n", 12345) - 14);

	printf("\nprintf(\"%%5.3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%5.3d|\n", 12345) - 14);

	printf("\nprintf(\"%%5.5d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%5.5d|\n", 12345) - 14);

	printf("\nprintf(\"%%5.7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%5.7d|\n", 12345) - 14);

	printf("\nprintf(\"%%3.3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%3.3d|\n", 12345) - 14);

	printf("\nprintf(\"%%3.5d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%3.5d|\n", 12345) - 14);

	printf("\nprintf(\"%%3.7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%3.7d|\n", 12345) - 14);

	printf("\nprintf(\"%%-0d\", 12345)\n");
	/*printf("|%-0d|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%-07d\", 12345)\n");
	/*printf("|%-07d|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%-05d\", 12345)\n");
	/*printf("|%-05d|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%-03d\", 12345)\n");
	/*printf("|%-03d|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%-0.9d\", 12345)\n");
	/*printf("|%-0.9d|\n", 12345) - 14);*/ printf("warning\n");

	printf("\nprintf(\"%%-0.5d\", 12345)\n");
	/*printf("|%-0.5d|\n", 12345);*/ printf("warning\n");

	printf("\nprintf(\"%%-3.0d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-3.0d|\n", 12345) - 14);

	printf("\nprintf(\"%%-5.0d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-5.0d|\n", 12345) - 14);

	printf("\nprintf(\"%%-7.0d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-7.0d|\n", 12345) - 14);

	printf("\nprintf(\"%%-7.3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-7.3d|\n", 12345) - 14);

	printf("\nprintf(\"%%-7.5d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-7.5d|\n", 12345) - 14);

	printf("\nprintf(\"%%-7.7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-7.7d|\n", 12345) - 14);

	printf("\nprintf(\"%%-5.3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-5.3d|\n", 12345) - 14);

	printf("\nprintf(\"%%-5.5d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-5.5d|\n", 12345) - 14);

	printf("\nprintf(\"%%-5.7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-5.7d|\n", 12345) - 14);

	printf("\nprintf(\"%%-3.3d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-3.3d|\n", 12345) - 14);

	printf("\nprintf(\"%%-3.5d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-3.5d|\n", 12345) - 14);

	printf("\nprintf(\"%%-3.7d\", 12345)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-3.7d|\n", 12345) - 14);
}
