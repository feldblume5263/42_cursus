/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:30:56 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/18 04:54:54 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char			*store_map_file(t_game *g, char *d, char *temp)
{
	char		*temp2;
	char		*temp3;
	int			size;

	d = get_blank_map(d);
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

int				get_color_p(t_game *g, char *d, int f)
{
	int			idx[2];
	char		**ret;

	idx[0] = 1;
	while (is_blank(d[idx[0]]))
		idx[0]++;
	ret = ft_split(d + idx[0], ',');
	idx[1] = make_color(ret, count_com(d + idx[0]));
	if (f == F)
	{
		if (g->flag.color_f)
			exit_with_error("floor color entered twice\n");
		g->conf.floor_color = idx[1];
		g->flag.color_f = 1;
	}
	else if (f == C)
	{
		if (g->flag.color_c)
			exit_with_error("ceil color entered twice\n");
		g->conf.ceiling_color = idx[1];
		g->flag.color_c = 1;
	}
	else
		return (0);
	return (1);
}

int				get_path(t_game *g, char *d, int f)
{
	char		*temp;

	temp = get_pure_path(d);
	if (f == NO)
		g->conf.tex[TEX_SOUTH].tex_path = ft_strdup(temp);
	else if (f == SO)
		g->conf.tex[TEX_NORTH].tex_path = ft_strdup(temp);
	else if (f == WE)
		g->conf.tex[TEX_EAST].tex_path = ft_strdup(temp);
	else if (f == EA)
		g->conf.tex[TEX_WEST].tex_path = ft_strdup(temp);
	else if (f == S)
		g->conf.tex[TEX_SPRITE].tex_path = ft_strdup(temp);
	get_path_flag(&(g->flag), f);
	free(temp);
	return (1);
}

void			get_resolution(t_game *g, char *d)
{
	int			idx;

	idx = 2;
	while (is_blank(d[idx]) && d[idx])
		idx++;
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
}

char			*put_config(t_game *g, char *d, int f, char *temp)
{
	char		*free_temp;

	free_temp = temp;
	if (f == R)
	{
		if (g->flag.r)
			exit_with_error("resolution enterd twice\n");
		resol_valid(d);
		get_resolution(g, d);
		resize_resol(g);
		g->flag.r = 1;
	}
	else if (f == NO || f == SO || f == WE || f == EA || f == S)
		get_path(g, d, f);
	else if (f == F || f == C)
		get_color_p(g, d, f);
	else if (f == M && g->flag.r && g->flag.color_c &&
		g->flag.color_f && inspect_t(&(g->flag)))
	{
		g->flag.map = 1;
		if (!(temp = store_map_file(g, d, temp)))
			exit_with_error("map error\n");
	}
	return (temp);
}
