/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:30:56 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/07 19:21:55 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				get_map(t_game *g, char *d)
{
	int			idx;

	idx = 0;
	if (g->conf.map[idx])
		idx++;
	g->conf.map = (char **)malloc(sizeof(char *) * 1);
	g->conf.map[idx] = ft_strdup(d);
	return (1);
}

int				get_color(t_game *g, char *d, int f)
{
	int			idx;
	int			ret;

	idx = 1;
	ret = 0;
	while (is_blank(d[idx]))
		idx++;
	while (d[idx])
	{
		if (d[idx] >= '0' && d[idx] <= '9')
			ret = 10 * ret + d[idx] - 48;
		idx++;
	}
	if (f == F)
		g->conf.floor_color = ret;
	else if (f == C)
		g->conf.ceiling_color = ret;
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

int				get_resolution(t_game *g, char *d)
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
	return (1);
}

int				put_config(t_game *g, char *d, int f)
{
	if (f == R)
	{
		if (!(get_resolution(g, d)))
			return (0);
	}
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
		if (!(get_map(g, d)))
			return (0);
	}
	return (1);
}
