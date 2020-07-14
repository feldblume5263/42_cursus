/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:32:33 by junhpark          #+#    #+#             */
/*   Updated: 2020/04/08 17:43:15 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 0 && c == 0)
		return (str);
	if (ft_strlen(str) == 0 && str[i] != 0)
		return (str);
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
		if (c == 0 && str[i] == c)
			return (str + i);
	}
	return (0);
}
