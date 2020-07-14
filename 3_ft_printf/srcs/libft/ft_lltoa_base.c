/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:35:33 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/04 19:56:00 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_lllen_base(long long num)
{
	size_t				len;
	unsigned long long	cp_num;

	len = 0;
	cp_num = num;
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

char			*ft_lltoa_base(long long num)
{
	size_t				len;
	size_t				idx;
	unsigned long long	cp_num;
	char				*result;

	len = get_lllen_base(num);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = 0;
	cp_num = num < 0 ? (unsigned long long)(num * -1) : (unsigned long long)num;
	idx = -1;
	while (++idx < len)
	{
		if (idx == len - 1 && num < 0)
		{
			result[0] = '-';
			break ;
		}
		if (cp_num % 16 >= 0 && cp_num % 16 <= 9)
			result[len - idx - 1] = cp_num % 16 + '0';
		else if (cp_num % 16 >= 10 && cp_num % 16 <= 15)
			result[len - idx - 1] = cp_num % 16 - 10 + 'a';
		cp_num /= 16;
	}
	return (result);
}
