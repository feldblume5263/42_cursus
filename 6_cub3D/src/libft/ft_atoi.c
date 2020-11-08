/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:51:47 by junhpark          #+#    #+#             */
/*   Updated: 2020/04/09 18:42:13 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					pass_ch_len_num(const char *str)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (!(str[i] >= '0' && str[i] <= '9') && str[i])
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		i++;
		count++;
	}
	return (count);
}

int					find_error(const char *str)
{
	int				count;
	int				i;

	count = 0;
	i = 0;
	while (!(str[i] >= '0' && str[i] <= '9') && str[i])
	{
		if (count == 0)
		{
			if (str[i] == '+' || str[i] == '-')
				count++;
			else if (!((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
				count = count + 2;
		}
		else
			count++;
		i++;
	}
	if (count <= 1)
		return (0);
	else
		return (1);
}

int					make_ten(int size)
{
	int				ten;

	ten = 1;
	if (size == 0)
		return (0);
	if (size == 1)
		return (ten);
	while (size > 1)
	{
		ten *= 10;
		size--;
	}
	return (ten);
}

long long			mk_num(const char *str, int num_len)
{
	int				i;
	long long		result;

	result = 0;
	i = 0;
	while (!(str[i] >= '0' && str[i] <= '9') && str[i])
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result += (str[i] - 48) * make_ten(num_len);
		i++;
		num_len--;
	}
	return (result);
}

int					ft_atoi(const char *str)
{
	long long		result;
	int				num_len;
	int				i;

	result = 0;
	if (find_error(str) == 1)
		return (0);
	num_len = pass_ch_len_num(str);
	if (num_len == 0)
		return (0);
	result = mk_num(str, num_len);
	i = 0;
	while (!(str[i] >= '0' && str[i] <= '9') && str[i])
	{
		if (str[i] == '-')
			result *= -1;
		i++;
	}
	return ((int)result);
}
