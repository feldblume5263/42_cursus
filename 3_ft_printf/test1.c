/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:43:47 by junhpark          #+#    #+#             */
/*   Updated: 2020/05/29 17:05:56 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

/*
******************** 자료형이 다른 가변인자 함수 만들기  ********************
*/
void	print_value(char *types, ...)
{
	va_list		ap;
	int			idx;

	idx = 0;
	va_start(ap, types);
	while (types[idx])
	{
		if (types[idx] == 'd')
			printf("%d ", va_arg(ap, int));
		else if (types[idx] == 'f')
			printf("%f ", va_arg(ap, double));
		else if (types[idx] == 'c')
			printf("%c ", va_arg(ap, char));
		else if (types[idx] == 's')
			printf("%s ", va_arg(ap, char *));
		idx++;
	}
	va_end(ap);
	printf("\n");
}

int		main(void)
{
	print_value("d", 10);
	print_value("cd", 'a', 10);
	print_value("fcd", 1.234567, 'a', 10);
	print_value("sdcf", "Hello world!", 10, 'a', 1.234567);
	return (0);
}
