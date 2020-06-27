/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:19:57 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/27 16:14:42 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int			get_precision(char *data, char *input_string, t_flag *data_flag)
{
	int				idx;
	int				precision;
	int				str_len;

	str_len = ft_strlen(input_string);
	if (data_flag->minus_flag == TRUE)
		str_len++;
	precision = 0;
	idx = 0;
	while (data[idx])
	{
		if (data[idx] == '.')
			precision = ft_atoi(&data[idx + 1]);
		idx++;
	}
	if (str_len > precision)
		precision = str_len;
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

int			get_width(char *data, int flag_width, char *input_string)
{
	int				large_width;
	int				idx;
	int				str_len;

	str_len = ft_strlen(input_string);
	large_width = 0;
	if (flag_width < 0)
		flag_width *= (-1);
	large_width = flag_width;
	idx = 0;
	while (data[idx] && (data[idx] < '0' || data[idx] > '9'))
		idx++;
	if (ft_atoi(&(data[idx])) > large_width)
		large_width = ft_atoi(&(data[idx]));
	if (str_len > large_width)
		large_width = str_len;
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
