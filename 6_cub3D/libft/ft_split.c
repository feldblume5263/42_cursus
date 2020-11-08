/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 22:56:13 by junhpark          #+#    #+#             */
/*   Updated: 2020/04/12 15:41:49 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		count_start(char const *s, char c, size_t idx)
{
	size_t			count;

	count = 0;
	if (idx == 0 && s[idx] != c)
		count++;
	else if (s[idx] != c && s[idx - 1] == c)
		count++;
	return (count);
}

size_t		inspect_chunk_len(char const *s, char c, size_t idx)
{
	size_t			len;

	len = 0;
	while (s[idx] && s[idx] != c)
	{
		len++;
		idx++;
	}
	return (len);
}

char		**split_and_put_str(char const *s, char c, char **str)
{
	size_t			idx;
	size_t			chunk;
	size_t			word;
	size_t			chunk_len;

	idx = 0;
	chunk = 0;
	while (s[idx])
	{
		if (count_start(s, c, idx) == 1)
		{
			chunk_len = inspect_chunk_len(s, c, idx);
			if (!(str[chunk] = (char *)malloc(sizeof(char) * (chunk_len + 1))))
				return (0);
			word = 0;
			while (word < chunk_len)
				str[chunk][word++] = s[idx++];
			str[chunk++][word] = 0;
		}
		else
			idx++;
	}
	return (str);
}

char		**ft_split(char const *s, char c)
{
	char			**str;
	size_t			chunk;
	size_t			idx;

	if (!(s))
		return (NULL);
	chunk = 0;
	idx = 0;
	while (s[idx])
	{
		if (count_start(s, c, idx) == 1)
			chunk++;
		idx++;
	}
	if (!(str = (char **)malloc(sizeof(char *) * (chunk + 1))))
		return (NULL);
	str[chunk] = 0;
	if (!(str = split_and_put_str(s, c, str)))
		return (0);
	return (str);
}
