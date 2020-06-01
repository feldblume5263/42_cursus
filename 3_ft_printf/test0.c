/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 12:05:29 by junhpark          #+#    #+#             */
/*   Updated: 2020/05/29 15:29:29 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void		print_numbers(int args, ...)
{
	va_list		ap;
	int			idx;
	int			num;

	va_start(ap, args);
	idx = 0;
	while (idx < args)
	{
		num = va_arg(ap, int);
		printf("%d ", num);
		idx++;
	}
	va_end(ap);
	printf("\n");
}

int			main(void)
{
	print_numbers(1, 10);
	print_numbers(2, 10, 20);
	print_numbers(3, 10, 20, 30);
	print_numbers(4, 10, 20, 30, 40);
	return (0);
}
