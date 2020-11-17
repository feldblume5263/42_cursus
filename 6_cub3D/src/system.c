/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:44:18 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/18 04:53:26 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				safer_free_pp(void **pp)
{
	if (pp != NULL && *pp != NULL)
	{
		free(*pp);
		*pp = NULL;
	}
	return (1);
}

int				safer_free_p(void *p)
{
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	return (1);
}

void			exit_with_error(char *message)
{
	int			size;

	size = ft_strlen(message);
	write(1, message, size);
	exit(0);
}

void			img_init(t_game *gm)
{
	gm->img.img = mlx_new_image(gm->mlx, gm->conf.width, gm->conf.height);
	gm->img.data = (int *)mlx_get_data_addr(gm->img.img,
		&gm->img.bpp, &gm->img.size_l, &gm->img.endian);
}

void			window_init(t_game *gm)
{
	gm->mlx = mlx_init();
	gm->win = mlx_new_window(gm->mlx, gm->conf.width,
		gm->conf.height, "mlx 42");
}
