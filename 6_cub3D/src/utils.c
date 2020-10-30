#include "../includes/cub.h"

double			get_distance(double x1, double y1, double x2, double y2)
{
	double		x;
	double		y;
	double		ret;

	x = x2 - x1;
	y = y2 - y1;
	ret = sqrt((x * x) + (y * y));
	return (ret);
}

double			noramalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

int				inspect_wall(t_game *gm, double x, double y)
{
	int			idx_x;
	int			idx_y;

	idx_x = floor(x / TILE_SIZE);
	idx_y = floor(y / TILE_SIZE);
	if (gm->map[idx_y][idx_x] > 0)
		return (1);
	else
		return (0);
}
