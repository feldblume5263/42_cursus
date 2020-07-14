/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:17:20 by junhpark          #+#    #+#             */
/*   Updated: 2020/04/12 15:45:06 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;
	unsigned int	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return (big);
	i = 0;
	while (big[i] && (i + little_len) <= n)
	{
		j = 0;
		count = 0;
		while (j < little_len)
		{
			if (big[i + j] == little[j])
				count++;
			if (count == little_len)
				return (&big[i]);
			j++;
		}
		i++;
	}
	return (0);
}
