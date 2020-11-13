/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:14:35 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/13 19:11:55 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char			*make_hexa(int n, char *base)
{
	int			div;
	int			len;
	int			base_len;
	char		*res;

	div = n;
	len = (n == 0) ? 1 : 0;
	base_len = (unsigned int)ft_strlen((char *)base);
	while (div != 0)
	{
		div = div / base_len;
		len++;
	}
	if (len == 1)
		len++;
	if (!(res = ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	res[0] = '0';
	while (len > 0)
	{
		len--;
		res[len] = base[(n % base_len)];
		n = n / base_len;
	}
	return (res);
}

int				get_color_value(char *hexa)
{
	int			ret;
	int			idx;

	ret = 0;
	idx = -1;
	while (hexa[++idx])
	{
		if (hexa[idx] >= '0' && hexa[idx] <= '9')
			ret = ret * 16 + hexa[idx] - '0';
		else if (hexa[idx] == 'a')
			ret = ret * 16 + 10;
		else if (hexa[idx] == 'b')
			ret = ret * 16 + 11;
		else if (hexa[idx] == 'c')
			ret = ret * 16 + 12;
		else if (hexa[idx] == 'd')
			ret = ret * 16 + 13;
		else if (hexa[idx] == 'e')
			ret = ret * 16 + 14;
		else if (hexa[idx] == 'f')
			ret = ret * 16 + 15;
	}
	return (ret);
}

int				make_color(char **num)
{
	int			idx;
	int			temp;
	char		*hexa;
	char		*res;
	char		*hexa_temp;

	hexa = ft_strdup("");
	idx = 0;
	while (idx < 3)
	{
		hexa_temp = hexa;
		temp = ft_atoi(num[idx]);
		free(num[idx]);
		hexa = ft_strjoin(hexa, res = make_hexa(temp, "0123456789abcdef"));
		free(hexa_temp);
		free(res);
		idx++;
	}
	free(num);
	temp = get_color_value(hexa);
	free(hexa);
	return (temp);
}
