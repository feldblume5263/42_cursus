#include "../includes/cub.h"

int				**make_map_file(t_game *gm, char **temp)
{
	int			row;
	int			col;

	if (!(gm->conf.map = (int **)malloc(sizeof(int *) * gm->conf.rows)))
		exit_with_error("map malloc error\n");
	row = -1;
	while (++row < gm->conf.rows)
	{
		if (!(gm->conf.map[row] = (int *)malloc(sizeof(int) * gm->conf.colums)))
			exit_with_error("map malloc error\n");
		col = -1;
		while (++col < (int)ft_strlen(temp[row]))
		{
			if (ft_strchr("NSEW", temp[row][col]))
			{
				gm->conf.p_x = gm->conf.tile_size * col;
				gm->conf.p_y = gm->conf.tile_size * row;
			}
			else
				gm->conf.map[row][col] = temp[row][col] == ' ' ? 7 : temp[row][col] - '0';
		}
		col--;
		while (++col < gm->conf.colums)
			gm->conf.map[row][col] = 7;
	}
	return (gm->conf.map);
}

void			map_init(t_game *gm, char *map_data)
{
	char		**temp;
	int			**map;

	gm->conf.tile_size = 64;
	temp = ft_split(map_data, 't');
	map = make_map_file(gm, temp);
	resize_resolution(gm);

	//ft_free_2d(temp);
	return ;
}
