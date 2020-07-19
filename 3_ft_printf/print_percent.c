/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:18:06 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/19 18:06:38 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_percent(t_write *writes, t_flag *flag)
{
	int				write_idx;

	write_idx = 0;
	while (write_idx < writes->padding && flag->zero_fill == FALSE)
	{
		write(1, " ", 1);
		write_idx++;
	}
	while (write_idx < writes->padding && flag->zero_fill == TRUE)
	{
		write(1, "0", 1);
		write_idx++;
	}
	write(1, "%", 1);
	write_idx++;
	while (write_idx < writes->length)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

void		percent_rule(char *data, t_flag *flag, t_write *writes)
{
	int				width;
	int				str_len;

	str_len = 1;
	width = flag->width;
	writes->length = width;
	writes->padding = width - str_len;
	if (flag->left_range == TRUE)
		writes->padding = 0;
	writes->zero = get_zero(data, flag);
}

int			ft_percent(char *data, t_flag *flag)
{
	t_write			*writes;
	char			input_string;
	int				ret_value;

	if (!(writes = malloc(sizeof(t_write) * 1)))
		return (MALLOC_ERROR);
	flag->ischar = TRUE;
	get_flag(data, flag, &input_string);
	percent_rule(data, flag, writes);
	ret_value = write_percent(writes, flag);
	free(writes);
	free(flag);
	free(data);
	return (ret_value);
}
