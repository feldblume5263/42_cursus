/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:57:54 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/17 16:31:53 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

int			wrirte_data_from_ap(char *data, va_list ap, int data_len)
{
	t_flag			*data_flag;
	int				print_len;

	data_flag = malloc(sizeof(t_flag) * 1);
	if (data[data_len - 1] == 'd')
		print_len = ft_int(data, ap, data_len, data_flag);
	return (print_len);
}

int			write_by_conv(char *format, va_list ap)
{
	char			*data;
	int				data_len;
	int				idx;

	idx = 0;
	while (format[idx])
	{
		data_len = 0;
		while (format[idx] != '%' && format[idx])
		{
			write(1, &(format[idx]), 1);
			idx++;
		}
		if (format[idx] == '%')
		{
			idx++;
			data_len = get_data_len(&(format[idx]));
			wrirte_data_from_ap((prepare_data(&(format[idx]), data_len)), ap, data_len);
			idx += data_len;
		}
	}
	return (/*get_return_len(format)*/0);
}

int			ft_printf(const char *format, ...)
{
	char			*res_string;
	int				str_len;
	va_list			ap;

	va_start(ap, format);
	str_len = write_by_conv((char *)format, ap);
	va_end(ap);
	return (str_len);
}

#include <stdio.h>

int			main(void)
{
	printf("\nShe's |%*.5d| my sunshine |%8.5d| in the |%-9.5d| rain\n",7, -40, 42, -412);
	ft_printf("\nShe's |%*.5d| my sunshine |%8.5d| in the |%-9.5d| rain\n",7, -40, 42, -412);
	return (0);
}
