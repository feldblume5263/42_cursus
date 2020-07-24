/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:02:09 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/12 17:41:23 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	while (format[data_len] && ((inspect_chunk(&(format[data_len]), \
		FLAG) == TRUE) || (format[data_len] >= '0' && format[data_len] <= '9')))
		data_len++;
	if (inspect_chunk(&(format[data_len]), CONV) == TRUE && format[data_len])
		data_len++;
	return (data_len);
}

char		*prepare_data(char *format, int data_len)
{
	char			*data;
	int				idx;

	if (!(data = (char *)malloc(sizeof(char) * (data_len + 1))))
		return (NULL);
	idx = 0;
	while (idx < data_len && format[idx])
	{
		data[idx] = format[idx];
		idx++;
	}
	data[idx] = NLL;
	return (data);
}
