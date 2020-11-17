/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:14:35 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/17 23:53:23 by Feldblume        ###   ########.fr       */
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

int				count_com(char *d)
{
	int			i[3];

	i[0] = -1;
	i[1] = 0;
	i[2] = 0;
	while (d[++i[0]])
	{
		if (!((d[i[0]] >= '0' && d[i[0]] <= '9') ||
			d[i[0]] == ' ' || d[i[0]] == ','))
			return (0);
		if (!(find_wrong_num(d)))
			return (0);
		if (d[i[0]] >= '0' && d[i[0]] <= '9')
			i[2]++;
		if (d[i[0]] == ',')
		{
			if (i[2] == 0)
				return (0);
			i[1]++;
			i[2] = 0;
		}
	}
	if (i[2] == 0 || i[1] != 2)
		return (0);
	return (1);
}

void			number_valid(int num)
{
	if (num < 0 || num > 255)
		exit_with_error("color error\n");
}

int				make_color(char **num, int valid)
{
	int			idx;
	int			temp;
	char		*hexa;
	char		*res;
	char		*hexa_temp;

	if (!(valid))
		exit_with_error("color error\n");
	hexa = ft_strdup("");
	idx = -1;
	while (++idx < 3)
	{
		hexa_temp = hexa;
		temp = ft_atoi(num[idx]);
		number_valid(temp);
		free(num[idx]);
		res = make_hexa(temp, "0123456789abcdef");
		hexa = ft_strjoin(hexa, res);
		free(hexa_temp);
		free(res);
	}
	free(num);
	temp = get_color_value(hexa);
	free(hexa);
	return (temp);
}
