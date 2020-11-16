/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:02:03 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/16 17:40:20 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			get_path_flag(t_flag *flag, int f)
{
	if (f == NO)
		flag->path_n = 1;
	else if (f == SO)
		flag->path_s = 1;
	else if (f == WE)
		flag->path_w = 1;
	else if (f == EA)
		flag->path_e = 1;
	else if (f == S)
		flag->path_s = 1;
}

int				inspect_t(t_flag *flag)
{
	if (flag->path_n && flag->path_w &&
		flag->path_s && flag->path_e)
		return (1);
	else
		return(0);
}

void			init_parsing_flag(t_game *gm)
{
	gm->flag.r = 0;
	gm->flag.path_n = 0;
	gm->flag.path_s = 0;
	gm->flag.path_e = 0;
	gm->flag.path_w = 0;
	gm->flag.path_s = 0;
	gm->flag.color_f = 0;
	gm->flag.color_c = 0;
	gm->flag.map = 0;
}
