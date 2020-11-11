/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:44:18 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/11 16:19:21 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

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
