/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:28:09 by junhpark          #+#    #+#             */
/*   Updated: 2020/03/31 18:35:50 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*result;
	unsigned int	i;

	i = 0;
	if (!(result = malloc(count * size)))
		return (0);
	while (i < (count * size))
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}
