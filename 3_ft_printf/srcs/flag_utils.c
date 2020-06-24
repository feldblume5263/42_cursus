/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:19:57 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/24 16:49:40 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int			get_precision(char *data, char *input_string, t_flag *data_flag)
{
	int				idx;
	int				precision;

	precision = 0;
	idx = 0;
	while (data[idx])
	{
		if (data[idx] == '.')
			precision = ft_atoi(&data[idx + 1]);
		idx++;
	}
	if (ft_strlen(input_string) > precision)
		precision = ft_strlen(input_string);
	if (precision > data_flag->width)
		precision = data_flag->width;
	return (precision);
}

int			find_zero(char *data)
{
	int				idx;

	idx = 0;
	while(data[idx])
	{
		if ((data[idx] >= '1' && data[idx] <= '9') || data[idx] == '.')
			return (FALSE);
		if (data[idx] == '0')
			return (TRUE);
		idx++;
	}
	return (FALSE);
}

int			get_width(char *data, int flag_width, char *input_string, int data_len)
{
	int				large_width;
	int				idx;

	large_width = 0;
	if (flag_width < 0)
		flag_width *= (-1);
	large_width = flag_width;
	idx = 0;
	while (data[idx] && (data[idx] < '0' || data[idx] > '9'))
		idx++;
	if (ft_atoi(&(data[idx])) > large_width)
		large_width = ft_atoi(&(data[idx]));
	if (ft_strlen(input_string) > large_width)
		large_width = ft_strlen(input_string);
	return (large_width);
}

int			get_range(char *data, int flag_width)
{
	int				idx;

	idx = 0;

	if (flag_width < 0)
		return (TRUE);
	while (data[idx])
	{
		if (data[idx] == '-')
			return (TRUE);
		idx++;
	}
	return (FALSE);
}

void		make_all_flag(t_flag *data_flag, char *data, int flag_width, char *input_string, int data_len)
{
	data_flag->left_range = get_range(data, flag_width);
	data_flag->width = get_width(data, flag_width, input_string, data_len);
	data_flag->precision = get_precision(data, input_string, data_flag);
	data_flag->zero_fill = find_zero(data);
}
