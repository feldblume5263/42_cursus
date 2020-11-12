/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:14:52 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/12 16:54:36 by junhpark         ###   ########.fr       */
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

void			put_data_into_map(t_game *gm, char **temp, int col, int row)
{
	if (ft_strchr("NSEW", temp[row][col]))
	{
		gm->conf.p_x = gm->conf.tile_size * col;
		gm->conf.p_y = gm->conf.tile_size * row;
		gm->conf.map[row][col] = 0;
	}
	else
		gm->conf.map[row][col] =
			temp[row][col] == ' ' ? 7 : temp[row][col] - '0';
}

int				**make_map_file(t_game *gm, char **temp)
{
	int			row;
	int			col;

	if (!(gm->conf.map = (int **)malloc(sizeof(int *) * gm->conf.rows)))
		exit_with_error("map malloc error\n");
	row = -1;
	while (++row < gm->conf.rows)
	{
		if (!(gm->conf.map[row] = (int *)malloc(sizeof(int) * gm->conf.colums)))
			exit_with_error("map malloc error\n");
		col = -1;
		while (++col < (int)ft_strlen(temp[row]))
			put_data_into_map(gm, temp, col, row);
		col--;
		while (++col < gm->conf.colums)
			gm->conf.map[row][col] = 7;
	}
	return (gm->conf.map);
}

void			map_init(t_game *gm, char *map_data)
{
	char		**temp;
	int			**map;

	temp = ft_split(map_data, 't');
	resize_colums(gm);
	gm->conf.tile_size = gm->conf.width / gm->conf.colums;
	map = make_map_file(gm, temp);
	check_up_left(map, gm->conf.rows, gm->conf.colums, 0);
	check_up_left(map, gm->conf.colums, gm->conf.rows, 1);
	check_down_right(map, gm->conf.rows, gm->conf.colums, 0);
	check_down_right(map, gm->conf.colums, gm->conf.rows, 1);
	check_blank(map, gm->conf.rows, gm->conf.colums);
	return ;
}
