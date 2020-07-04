/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:19:15 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/04 19:58:19 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_ulen_base_up(unsigned int num)
{
	size_t				len;
	unsigned int		cp_num;

	len = 0;
	cp_num = (unsigned int)num;
	if (cp_num < 0)
	{
		len++;
		cp_num *= -1;
	}
	while (cp_num >= 16)
	{
		len++;
		cp_num /= 16;
	}
	return (++len);
}

char			*ft_utoa_base_up(unsigned int num)
{
	size_t				len;
	size_t				idx;
	unsigned int		cp_num;
	char				*result;

	len = get_ulen_base_up(num);
	cp_num = (unsigned long long)num;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = 0;
	idx = 0;
	while (idx < len)
	{
		if (cp_num % 16 >= 0 && cp_num % 16 <= 9)
			result[len - idx - 1] = cp_num % 16 + '0';
		else if (cp_num % 16 >= 10 && cp_num % 16 <= 15)
			result[len - idx - 1] = cp_num % 16 - 10 + 'A';
		cp_num /= 16;
		idx++;
	}
	return (result);
}
