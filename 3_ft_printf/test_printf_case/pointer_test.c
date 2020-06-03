/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:09:47 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/03 16:04:33 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	char	*ptr;
	void	*void_ptr;

	printf("***************************************\n");
	printf("********* printf_pointer_test *********\n");
	printf("***************************************\n");
	printf("made by junhpark @ 42Seoul");
	printf("\n");

	printf("\n***************************************\n");

	printf("\nprintf(\"%%p\", ptr)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%p|\n", ptr) - 14);

	printf("\nprintf(\"%%p\", void_ptr)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%p|\n", void_ptr) - 14);

	printf("\nprintf(\"%%p\", NULL)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%p|\n", NULL) - 14);

	printf("\nprintf(\"%%p\", 15)\n");
	/*printf("\t\treturn : %d\n", printf("\t\tresult : |%p|\n", 15) - 14);*/ printf("warning\n");

	printf("\nprintf(\"%%p\", -15)\n");
	/*printf("\t\treturn : %d\n", printf("\t\tresult : |%p|\n", -15) - 14);*/ printf("warning\n");

	printf("\nprintf(\"%%.p\", ptr)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%.p|\n", ptr) - 14);

	printf("\nprintf(\"%%.3p\", ptr)\n");
	/*printf("\t\treturn : %d\n", printf("\t\tresult : |%.3p|\n", ptr) - 14);*/ printf("warning\n");

	printf("\nprintf(\"%%15p\", ptr)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%15p|\n", ptr) - 14);

	printf("\nprintf(\"%%-15p\", ptr)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-15p|\n", ptr) - 14);

	printf("\nprintf(\"%%*p\", 15, ptr)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%*p|\n", 15, ptr) - 14);

	printf("\nprintf(\"%%0*p\", 15, ptr)\n");
	/*printf("\t\treturn : %d\n", printf("\t\tresult : |%0*p|\n", 15, ptr) - 14);*/ printf("warning\n");

	printf("\nprintf(\"%%*p\", -15, ptr)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%*p|\n", -15, ptr) - 14);

	printf("\nprintf(\"%%-*p\", -15, ptr)\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-*p|\n", -15, ptr) - 14);
}
