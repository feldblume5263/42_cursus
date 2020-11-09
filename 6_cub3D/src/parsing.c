/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:10:20 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/09 18:06:47 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				is_map(char *d)
{
	int			idx;

	idx = 0;
	while (d[idx])
	{
		if (!(ft_strchr(" 012NSEW", d[idx])))
			return (0);
		idx++;
	}
	return (1);
}

int				flag_data(char *d)
{
	if (d[0] == 'R' && d[1] == ' ')
		return (R);
	else if (d[0] == 'N' && d[1] == 'O' && d[2] == ' ')
		return (NO);
	else if (d[0] == 'S' && d[1] == 'O' && d[2] == ' ')
		return (SO);
	else if (d[0] == 'W' && d[1] == 'E' && d[2] == ' ')
		return (WE);
	else if (d[0] == 'E' && d[1] == 'A' && d[2] == ' ')
		return (EA);
	else if (d[0] == 'S' && d[1] == ' ')
		return (S);
	else if (d[0] == 'F' && d[1] == ' ')
		return (F);
	else if (d[0] == 'C' && d[1] == ' ')
		return (C);
	else if (is_map(d))
		return (M);
	else
		return (-1);
}

int				flag_blank(char *d)
{
	int			idx;

	idx = 0;
	while (d[idx])
	{
		if (!(is_blank(d[idx])))
			return (0);
		idx++;
	}
	return (1);
}

char			*parse_data(t_game *gm, char *path)
{
	int			fd;
	char		*data_line;
	int			temp;
	int			flag;
	char		*map;

	map = ft_strdup("");
	if ((fd = open(path, O_RDONLY)) < 0)
		exit_with_error("fail to open file\n");
	while ((temp = get_next_line(fd, &data_line)) > 0)
	{
		if (flag_blank(data_line) == 1 && flag != M)
		{
			free(data_line);
			continue;
		}
		if ((flag = flag_data(data_line)) > 0)
		{
			if (!(map = put_config(gm, data_line, flag, map)))
				exit_with_error("file error!\n");
		}
		else
			exit_with_error("file error!\n");
	}
	return (map);
}
