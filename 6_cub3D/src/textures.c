/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:15:20 by Feldblume         #+#    #+#             */
/*   Updated: 2020/11/04 20:22:19 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				*load_image(t_game *gm, char *path, t_img *tex, int idx)
{
	int			x;
	int			y;
	int			*ret;

	tex->img = mlx_xpm_file_to_image(gm->mlx, path, &tex->img_width, &tex->img_height);
	gm->config.tex[idx].width = tex->img_width;
	gm->config.tex[idx].height = tex->img_height;
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

	tex_idx = 0;
	while (tex_idx < TEXTURES)
	{
		gm->config.tex[tex_idx].tex_path = (char *)malloc(sizeof(char) * 30);
		tex_idx++;
	}
	gm->config.tex[TEX_NORTH].tex_path = "../textures/NO.xpm";
	gm->config.tex[TEX_SOUTH].tex_path = "../textures/SO.xpm";
	gm->config.tex[TEX_WEST].tex_path = "../textures/WE.xpm";
	gm->config.tex[TEX_EAST].tex_path = "../textures/EA.xpm";
	tex_idx = 0;
	while (tex_idx < TEXTURES)
	{
		//gm->config.tex[tex_idx].texture =
			load_image(gm, gm->config.tex[tex_idx].tex_path, &texture, tex_idx);
		//free(gm->config.tex[tex_idx].tex_path);
		tex_idx++;
	}
}
