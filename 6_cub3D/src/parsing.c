/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:10:20 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/06 18:53:15 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				get_size_from_data(t_game *gm)
{

}

int				parse_data(t_game *gm, char *path)
{
	int			fd;
	char		*data_line;

	if ((fd = open(path, O_RDONLY)) < 0)
	get_size_from_data(gm);
}