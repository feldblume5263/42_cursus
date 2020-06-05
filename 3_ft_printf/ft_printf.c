/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:57:54 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/06 00:27:59 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>

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
	while (inspect_chunk(&(format[data_len]), FLAG) == TRUE)
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
	int				ret_count;
	int				data_len;
	int				idx;

	idx = 0;
	while (format[idx])
	{
		while (format[idx] != '%' && format[idx])
		{
			write(1, &(format[idx]), 1);
			idx++;
		}
		idx++;
		data_len = get_data_len(&(format[idx]));
		printf("\nlen = %d\n", data_len);
		data = prepare_data(&(format[idx]), data_len);
	}
	return (0);
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

	return_value = ft_printf("\nBalea %05.5d Handcreme\n", 2014);
	printf("return value = %d\n", return_value);
}
