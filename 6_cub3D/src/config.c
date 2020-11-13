/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:30:56 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/13 19:19:36 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			check_player_num(t_game *g, char *d)
{
	int			idx;

	idx = -1;
	while (d[++idx])
	{
		if (ft_strchr("NSWE", d[idx]))
		{
			if (g->conf.p_flag == 1)
				exit_with_error("you have 2 player\n");
			else
				g->conf.p_flag = 1;
		}
	}
}

char			*store_map_file(t_game *g, char *d, char *temp)
{
	char		*temp2;
	char		*temp3;
	int			size;

	size = (int)ft_strlen(d);
	if (!(temp2 = ft_strjoin(d, "t")))
		exit_with_error("map malloc error!\n");
	if (!(temp3 = ft_strjoin(temp, temp2)))
		exit_with_error("map malloc error!\n");
	g->conf.rows++;
	check_player_num(g, d);
	if (*temp && temp)
	{
		free(temp);
		temp = NULL;
	}
	free(temp2);
	free(temp);
	g->conf.colums = (int)ft_strlen(d) > g->conf.colums ? size : g->conf.colums;
	return (temp3);
}

int				get_color(t_game *g, char *d, int f)
{
	int			idx;
	char		**ret;
	int			color;

	idx = 1;
	while (is_blank(d[idx]))
		idx++;
	ret = ft_split(d + idx, ',');
	color = make_color(ret);
	if (f == F)
		g->conf.floor_color = color;
	else if (f == C)
		g->conf.ceiling_color = color;
	else
		return (0);
	return (1);
}

int				get_path(t_game *g, char *d, int f)
{
	int			idx;

	idx = 2;
	while (is_blank(d[idx]))
		idx++;
	if (f == NO)
		g->conf.tex[TEX_NORTH].tex_path = ft_strdup(d + idx);
	else if (f == SO)
		g->conf.tex[TEX_SOUTH].tex_path = ft_strdup(d + idx);
	else if (f == WE)
		g->conf.tex[TEX_WEST].tex_path = ft_strdup(d + idx);
	else if (f == EA)
		g->conf.tex[TEX_EAST].tex_path = ft_strdup(d + idx);
	else if (f == S)
		g->conf.tex[TEX_SPRITE].tex_path = ft_strdup(d + idx);
	return (1);
}

void			get_resolution(t_game *g, char *d)
{
	int			idx;

	idx = 2;
	if (!(d[idx] >= '0' && d[idx] <= '9'))
		exit_with_error("resolution error!\n");
	while (!(is_blank(d[idx])) && d[idx])
	{
		if (!(d[idx] >= '0' && d[idx] <= '9'))
			exit_with_error("resolution error!\n");
		g->conf.width = g->conf.width * 10 + d[idx] - 48;
		idx++;
	}
	while (is_blank(d[idx]) && d[idx])
		idx++;
	while (!(is_blank(d[idx])) && d[idx])
	{
		if (!(d[idx] >= '0' && d[idx] <= '9'))
			exit_with_error("resolution error!\n");
		g->conf.height = g->conf.height * 10 + d[idx] - 48;
		idx++;
	}
	if (g->conf.width == 0 || g->conf.height == 0)
		exit_with_error("resolution error!\n");
	g->conf.width = g->conf.width > 5120 ? 5120 : g->conf.width;
	g->conf.height = g->conf.height > 2880 ? 2880 : g->conf.height;
}

char			*put_config(t_game *g, char *d, int f, char *temp)
{
	char		*free_temp;

	free_temp = temp;
	if (f == R)
		get_resolution(g, d);
	else if (f == NO || f == SO || f == WE || f == EA || f == S)
	{
		if (!(get_path(g, d, f)))
			return (0);
	}
	else if (f == F || f == C)
	{
		if (!(get_color(g, d, f)))
			return (0);
	}
	else if (f == M)
	{
		if (!(temp = store_map_file(g, d, temp)))
			return (0);
	}
	return (temp);
}
