/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:09:08 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/03 15:50:25 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		main(void)
{
	printf("***************************************\n");
	printf("********** printf_string_test *********\n");
	printf("***************************************\n");
	printf("made by junhpark @ 42Seoul");
	printf("\n");

	printf("\n***************************************\n");

	printf("\nprintf(\"%%s\", \"abcde\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%s|\n", "abcde") - 14);

	printf("\nprintf(\"%%s\", \"박준홍\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%s|\n", "박준홍") - 14);

	printf("\nprintf(\"%%s\", \"서울\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%s|\n", "서울") - 14);

	printf("\nprintf(\"%%s\", \"중앙대학교\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%s|\n", "중앙대학교") - 14);

	printf("\nprintf(\"%%s\", \"42abcde\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%s|\n", "42abcde") - 14);

	char	*korean = "사십이서울";
	char	*English = "Fourtytwo Seoul";

	int ko_return = strlen(korean);
	int en_return = strlen(English);

	printf("\nstrlen(\"사십이서울\") = %d bytes / 5 letters\n", ko_return);
	printf("strlen(\"Fourtytwo Seoul\") = %d bytes / 15 letters\n\n", en_return);

	printf("\nprintf(\"%%*s\", 5, \"abcde\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%*s|\n", 5, "abcde") - 14);

	printf("\nprintf(\"%%*s\", 3, \"abcde\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%*s|\n", 3, "abcde") - 14);

	printf("\nprintf(\"%%*s\", 7 \"abcde\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%*s|\n", 7, "abcde") - 14);

	printf("\nprintf(\"%%7s\", \"abcde\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%7s|\n", "abcde") - 14);

	printf("\nprintf(\"%%-7s\", \"abcde\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%-7s|\n", "abcde") - 14);

	printf("\nprintf(\"%%*s\", -7 \"abcde\")\n");
	printf("\t\treturn : %d\n", printf("\t\tresult : |%*s|\n", -7, "abcde") - 14);
}
