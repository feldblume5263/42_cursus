/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:57:54 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/07 23:02:32 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>

int			wrirte_data_from_ap(char *data, va_list ap, int data_len)
{
	int				print;
	char			*print_str;
	//printf ("\ndata = %s\n", data);
	if (data[data_len - 1] == 'd')
		print = va_arg(ap, int);
	print_str = ft_itoa(print);
	write(1, print_str, ft_strlen(print_str));
	return (0);
}

int			get_return_len(char *format)
{
	return (0);
}

int			inspect_chunk(char *chr, char *chunk)
{
	size_t			idx;

	idx = 0;
	while (chunk[idx])
	{
		if (chunk[idx] == *chr)
			return (TRUE);
		idx++;
	}
	return (FALSE);
}

int			get_data_len(char *format)
{
	int				data_len;

	data_len = 0;
	while ((inspect_chunk(&(format[data_len]), FLAG) == TRUE)
		|| (format[data_len] >= '0' && format[data_len] <= '9'))
		data_len++;
	data_len++;
	return (data_len);
}

char		*prepare_data(char *format, int data_len)
{
	char			*data;
	int				idx;

	data = (char *)malloc(sizeof(char) * (data_len + 1));
	idx = 0;
	while (idx < data_len)
	{
		data[idx] = format[idx];
		idx++;
	}
	data[idx] = NLL;
	return (data);
}

int			allocate_and_write_by_conv(char *format, va_list ap)
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
			wrirte_data_from_ap((data = prepare_data(&(format[idx]), data_len)), ap, data_len);
			//printf("\nlen = %d\n|%s|\n", data_len, data);
			idx += data_len;
		}
	}
	return (get_return_len(format));
}

int			ft_printf(const char *format, ...)
{
	char			*res_string;
	int				str_len;
	va_list			ap;

	va_start(ap, format);
	str_len = allocate_and_write_by_conv((char *)format, ap);
	va_end(ap);
	return (str_len);
}

int			main(void)
{
	int		return_value;

	return_value = ft_printf("\nShe's my sunshine %2.2d in the %3.3d rain\n", 42, 412);
	//printf("return = %d\n", return_value);
}
