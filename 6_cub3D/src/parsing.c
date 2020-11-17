/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:10:20 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/17 16:26:44 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				flag_data(char *d, t_flag f)
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
	else if (is_map(d) && f.r && f.path_n && f.path_w &&
		f.path_s && f.path_e && f.color_f && f.color_c)
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

int				read_file(t_game *gm, char *path, char **map)
{
	int			fd;

	*map = ft_strdup("");
	init_parsing_flag(gm);
	if ((fd = open(path, O_RDONLY)) < 0)
		exit_with_error("fail to open file\n");
	return (fd);
}

char			*parse_data(t_game *gm, char *path)
{
	int			parm[3];
	char		*data_line;
	char		*map;

	parm[0] = read_file(gm, path, &map);
	while ((parm[1] = get_next_line(parm[0], &data_line)) > 0)
	{
		if (flag_blank(data_line) == 1 && parm[2] != M)
		{
			free(data_line);
			continue;
		}
		if ((parm[2] = flag_data(data_line, gm->flag)) > 0)
		{
			if (!(map = put_config(gm, data_line, parm[2], map)))
				exit_with_error("file error!\n");
		}
		else
			exit_with_error("file error!\n");
		free(data_line);
	}
	free(data_line);
	if (!(gm->flag.map))
		exit_with_error("file content error\n");
	return (map);
}
