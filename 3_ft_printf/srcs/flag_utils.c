/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:19:57 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/02 20:19:33 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int			get_precision(char *data, int str_len, t_flag *data_flag)
{
	int				idx;
	int				precision;

	precision = -1;
	idx = 0;
	while (data[idx])
	{
		if (data[idx] == '.')
			precision = ft_atoi(&data[idx + 1]);
		idx++;
	}
	data_flag->len = (data_flag->width > precision ? data_flag->width : precision);
	data_flag->len = (data_flag->len > str_len ? data_flag->width : str_len);
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

int			get_width(char *data, int flag_width, int str_len)
{
	int				large_width;
	int				idx;

	large_width = 0;
	str_len = 0;
	if (flag_width < 0)
		flag_width *= (-1);
	large_width = flag_width;
	idx = 0;
	while (data[idx] && (data[idx] < '0' || data[idx] > '9'))
		idx++;
	if (ft_atoi(&(data[idx])) > large_width)
		large_width = ft_atoi(&(data[idx]));
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
