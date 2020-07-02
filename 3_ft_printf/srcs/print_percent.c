/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:41:00 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/02 17:08:31 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int			write_percent_with_flag(char ret_char, t_flag *data_flag)
{
	int				padding;
	int				write_idx;

	write_idx = 0;
	padding = get_padding(data_flag);
	write_idx += write_padding(padding);
	write_idx += write_percent_zero(data_flag, 1);
	write(1, &ret_char, 1);
	write_idx ++;
	while (write_idx < data_flag->width)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

void		make_percent_flag(t_flag *data_flag, char *data, int flag_width)
{
	data_flag->left_range = get_range(data, flag_width);
	data_flag->width = get_width(data, flag_width, 1);
	data_flag->precision = get_precision(data, 1, data_flag);
	data_flag->zero_fill = find_zero(data);
	data_flag->minus_flag = FALSE;

}

int			ft_percent(char *data, va_list ap, t_flag *data_flag)
{
	int				flag_width;
	int				idx;
	char			ret_char;

	flag_width = FALSE;
	idx = 0;
	while (data[idx])
	{
		if (data[idx] == '*')
			flag_width = va_arg(ap, int);
		idx++;
	}
	ret_char = '%';
	make_percent_flag(data_flag, data, flag_width);
	return (write_percent_with_flag(ret_char, data_flag));
}