/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:08:46 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/07 17:38:59 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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

int					ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t				ft_strlen(const char *str)
{
	size_t			count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}
