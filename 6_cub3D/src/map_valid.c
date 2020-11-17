/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:05:08 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/17 19:05:50 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			check_blank(int **map, int rows, int cols)
{
	int			parm[2];

	parm[0] = -1;
	while (++parm[0] < rows)
	{
		parm[1] = -1;
		while (++parm[1] < cols)
		{
			if (map[parm[0]][parm[1]] == 7)
			{
				if (parm[0] - 1 >= 0)
					map[parm[0] - 1][parm[1]] == 0 ?
						exit_with_error("map space error!\n") : 0;
				if (parm[0] + 1 < rows)
					map[parm[0] + 1][parm[1]] == 0 ?
						exit_with_error("map space error!\n") : 0;
				if (parm[1] - 1 >= 0)
					map[parm[0]][parm[1] - 1] == 0 ?
						exit_with_error("map space error!\n") : 0;
				if (parm[1] + 1 < rows)
					map[parm[0]][parm[1] + 1] == 0 ?
						exit_with_error("map space error!\n") : 0;
			}
		}
	}
}

void			check_down_right(int **map, int start, int end, int flag)
{
	int			parm[2];

	parm[1] = end;
	while (--start >= 0)
	{
		parm[0] = 0;
		end = parm[1];
		while (--end >= 0)
		{
			if (flag == 0)
			{
				if (map[start][end] == 1)
					parm[0] = 1;
				if (map[start][end] == 0 && parm[0] == 0)
					exit_with_error("map wall error!\n");
			}
			else if (flag == 1)
			{
				if (map[end][start] == 1)
					parm[0] = 1;
				if (map[end][start] == 0 && parm[0] == 0)
					exit_with_error("map wall error!\n");
			}
		}
	}
}

void			check_up_left(int **map, int start, int end, int flag)
{
	int			parm[3];

	parm[0] = -1;
	while (++parm[0] < start)
	{
		parm[1] = -1;
		parm[2] = 0;
		while (++parm[1] < end)
		{
			if (flag == 0)
			{
				if (map[parm[0]][parm[1]] == 1)
					parm[2] = 1;
				if (map[parm[0]][parm[1]] == 0 && parm[2] == 0)
					exit_with_error("map wall error!\n");
			}
			else if (flag == 1)
			{
				if (map[parm[1]][parm[0]] == 1)
					parm[2] = 1;
				if (map[parm[1]][parm[0]] == 0 && parm[2] == 0)
					exit_with_error("map wall error!\n");
			}
		}
	}
}

void			resize_colums(t_game *gm)
{
	if ((double)gm->conf.width / (double)gm->conf.height
		> (double)gm->conf.colums / (double)gm->conf.rows)
	{
		gm->conf.colums = (double)gm->conf.rows *
			((double)gm->conf.width / (double)gm->conf.height);
	}
}

void			is_cub(char *file_name)
{
	int			idx;

	idx = 0;
	while (file_name[idx])
		idx++;
	idx--;
	if (file_name[idx] != 'b')
		exit_with_error("file is not .cub format\n");
	idx--;
	if (file_name[idx] != 'u')
		exit_with_error("file is not .cub format\n");
	idx--;
	if (file_name[idx] != 'c')
		exit_with_error("file is not .cub format\n");
	idx--;
	if (file_name[idx] != '.')
		exit_with_error("file is not .cub format\n");
	idx--;
}
