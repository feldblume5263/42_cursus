/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:02:03 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/18 04:53:55 by Feldblume        ###   ########.fr       */
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

void			get_path_flag_s(t_flag *flag, int f)
{
	if (f == S)
	{
		if (flag->path_i)
			exit_with_error("texture sprite entered twice\n");
		flag->path_i = 1;
	}
}

void			get_path_flag(t_flag *flag, int f)
{
	if (f == NO)
	{
		if (flag->path_n)
			exit_with_error("texture North entered twice\n");
		flag->path_n = 1;
	}
	else if (f == SO)
	{
		if (flag->path_s)
			exit_with_error("texture South entered twice\n");
		flag->path_s = 1;
	}
	else if (f == WE)
	{
		if (flag->path_w)
			exit_with_error("texture West entered twice\n");
		flag->path_w = 1;
	}
	else if (f == EA)
	{
		if (flag->path_e)
			exit_with_error("texture East entered twice\n");
		flag->path_e = 1;
	}
	get_path_flag_s(flag, f);
}

int				inspect_t(t_flag *flag)
{
	if (flag->path_n && flag->path_w &&
		flag->path_s && flag->path_e)
		return (1);
	else
		return (0);
}

void			init_parsing_flag(t_game *gm)
{
	gm->flag.r = 0;
	gm->flag.path_n = 0;
	gm->flag.path_s = 0;
	gm->flag.path_e = 0;
	gm->flag.path_w = 0;
	gm->flag.path_s = 0;
	gm->flag.path_i = 0;
	gm->flag.color_f = 0;
	gm->flag.color_c = 0;
	gm->flag.map = 0;
}
