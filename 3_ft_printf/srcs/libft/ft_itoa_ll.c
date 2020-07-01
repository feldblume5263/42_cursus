/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:00:57 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/30 16:46:48 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len_ll(long long num)
{
	size_t		len;
	long long	cp_num;

	len = 0;
	cp_num = (long long)num;
	if (cp_num < 0)
	{
		len++;
		cp_num *= -1;
	}
	while (cp_num >= 10)
	{
		len++;
		cp_num /= 10;
	}
	return (++len);
}

char			*ft_itoa_ll(long long num)
{
	size_t		len;
	size_t		idx;
	long long	cp_num;
	char		*result;

	len = get_len_ll(num);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = 0;
	idx = 0;
	cp_num = num < 0 ? num * -1 : num;
	while (idx < len)
	{
		if (idx == len - 1 && num < 0)
		{
			result[0] = '-';
			break ;
		}
		result[len - idx - 1] = cp_num % 10 + '0';
		cp_num /= 10;
		idx++;
	}
	return (result);
}
