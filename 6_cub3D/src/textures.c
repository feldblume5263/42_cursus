/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:15:20 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/05 17:52:05 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				*load_image(t_game *gm, char *path, t_img *tex, int idx)
{
	int			x;
	int			y;
	int			*ret;

	tex->img = mlx_xpm_file_to_image(gm->mlx, path, &tex->img_width, &tex->img_height);
	gm->conf.tex[idx].width = tex->img_width;
	gm->conf.tex[idx].height = tex->img_height;
	tex->data = (int *)mlx_get_data_addr
		(tex->img, &tex->bpp, &tex->size_l, &tex->endian);
	ret = (int *)malloc(sizeof(int) * (tex->img_width * tex->img_height));
	y = 0;
	while (y < tex->img_height)
	{
		x = 0;
		while (x < tex->img_width)
		{
			ret[tex->img_width * y + x] = tex->data[tex->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(gm->mlx, tex->img);
	return (ret);
}

void			load_texture(t_game *gm)
{
	int			tex_idx;
	t_img		texture;

	gm->conf.tex[TEX_NORTH].tex_path = strdup("./textures/NO.xpm");
	gm->conf.tex[TEX_SOUTH].tex_path = strdup("./textures/SO.xpm");
	gm->conf.tex[TEX_WEST].tex_path = strdup("./textures/WE.xpm");
	gm->conf.tex[TEX_EAST].tex_path = strdup("./textures/EA.xpm");
	tex_idx = 0;
	while (tex_idx < TEXTURES - 1)
	{
		gm->conf.tex[tex_idx].texture =
			load_image(gm, gm->conf.tex[tex_idx].tex_path, &texture, tex_idx);
		free(gm->conf.tex[tex_idx].tex_path);
		tex_idx++;
	}
}