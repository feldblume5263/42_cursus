#include "../includes/cub.h"

int				**make_map_file(t_game *gm, char **temp)
{
	int			row;
	int			col;
	int			**map;

	if (!(map = (int **)malloc(sizeof(int *) * gm->conf.rows)))
		exit_with_error("map malloc error\n");
	row = -1;
	while (++row < gm->conf.rows)
	{
		if (!(map[row] = (int *)malloc(sizeof(int) * gm->conf.colums)))
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
				map[row][col] = temp[row][col] == ' ' ? 7 : temp[row][col] - 48;
		}
		col--;
		while (++col < gm->conf.colums)
			map[row][col] = 7;
	}
	return (map);
}

void			map_init(t_game *gm, char *map_data)
{
	char		**temp;
	int			**map;

	temp = ft_split(map_data, 't');
	map = make_map_file(gm, temp);
	ft_memcpy(gm->map, map, sizeof(int) * gm->conf.rows * gm->conf.colums);
	int i = 0;
	int j = 0;
	while (i < gm->conf.rows)
	{
		j = 0;
		while (j < gm->conf.colums)
		{
			printf("%d", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return ;
}
