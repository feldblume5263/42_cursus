/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:41:10 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/15 20:51:10 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_char(t_write *writes, char input_string)
{
	int				write_idx;

	write_idx = 0;
	while (write_idx < writes->padding)
	{
		write(1, " ", 1);
		write_idx++;
	}
	write(1, &input_string, 1);
	write_idx++;
	while (write_idx < writes->length)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

void		char_rule(t_flag *flag, t_write *writes)
{
	int				width;
	int				str_len;

	str_len = 1;
	width = flag->width;
	writes->length = width;
	writes->padding = width - str_len;
	if (flag->left_range == TRUE)
		writes->padding = 0;
	writes->zero = FALSE;
}

int			ft_char(char *data, va_list ap, t_flag *flag)
{
	t_write			*writes;
	char			input_string;
	int				ret_value;

	if (!(writes = malloc(sizeof(t_write) * 1)))
		return (MALLOC_ERROR);
	input_string = va_arg(ap, int);
	flag->ischar = TRUE;
	get_flag(data, flag, &input_string);
	char_rule(flag, writes);
	ret_value = write_char(writes, input_string);
	free(writes);
	free(flag);
	free(data);
	return (ret_value);
}
