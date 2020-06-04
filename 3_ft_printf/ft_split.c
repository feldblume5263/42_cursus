/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:19:19 by junhpark          #+#    #+#             */
/*   Updated: 2020/02/13 22:16:50 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		inspect(char *str, char *charset, int i, int len_char)
{
	int		j;
	int		k;
	int		flag;

	j = -1;
	flag = 0;
	while (charset[++j])
	{
		if (i == 0)
			if (str[i] != charset[j])
				flag++;
		if (i > 0)
		{
			if (str[i - 1] == charset[j])
			{
				k = -1;
				while (charset[++k])
				{
					if (str[i] != charset[k] && flag != len_char)
						flag++;
				}
			}
		}
	}
	return ((flag == len_char) ? 1 : 0);
}

int		find_charset(char *str, char *charset, int len_char)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (inspect(str, charset, i, len_char) == 1)
			count++;
		i++;
	}
	return (count);
}

int		pass_char(char *str, int index, char *charset, int len_char)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (count <= index)
	{
		count += inspect(str, charset, i, len_char);
		i++;
	}
	i--;
	return (i);
}

char	*ft_strncpy(char *str, char *charset, int leng, int add)
{
	char	*new;
	int		i[2];

	if (!(new = (char *)malloc(sizeof(char) * leng)))
		return (0);
	i[0] = 0;
	while (str[add])
	{
		i[1] = 0;
		while (charset[i[1]])
		{
			if (str[add] == charset[i[1]])
			{
				new[i[0]] = '\0';
				return (new);
			}
			i[1]++;
		}
		new[i[0]] = str[add];
		i[0]++;
		add++;
	}
	new[i[0]] = '\0';
	return (new);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i[2];
	int		char_len;
	int		leng;
	int		len_char;

	len_char = 0;
	while (charset[len_char])
		len_char++;
	char_len = find_charset(str, charset, len_char);
	if (!(arr = (char **)malloc(sizeof(char *) * (char_len + 1))))
		return (0);
	i[0] = -1;
	leng = 0;
	while (str[leng])
		leng++;
	if (len_char == 0)
		char_len = 1;
	while (++i[0] < char_len)
	{
		i[1] = pass_char(str, i[0], charset, len_char);
		arr[i[0]] = ft_strncpy(str, charset, leng, i[1]);
	}
	arr[i[0]] = 0;
	return (arr);
}
