#include "../includes/cub.h"

void			draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double		deltaX;
	double		deltaY;
	double		step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[TO_COORD(x1, y1)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void			draw_lines(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < MAP_COLS)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, WINDOW_HEIGHT);
		i++;
	}
	draw_line(game, MAP_COLS * TILE_SIZE - 1, 0, MAP_COLS * TILE_SIZE - 1, WINDOW_HEIGHT);
	j = 0;
	while (j < MAP_ROWS)
	{
		draw_line(game, 0, j * TILE_SIZE, WINDOW_WIDTH, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, MAP_ROWS * TILE_SIZE - 1, WINDOW_WIDTH, MAP_ROWS * TILE_SIZE - 1);
}

void			draw_rectangle(t_game *game, int x, int y, int color)
{
	int			i;
	int			j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y  + i) * WINDOW_WIDTH + x + j] = color;
			j++;
		}
		i++;
	}
}

void			draw_rectangles(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < MAP_ROWS)
	{
		j = 0;
		while (j < MAP_COLS)
		{
			if (game->map[i][j] == 1)
				draw_rectangle(game, j, i, 0x000000);
			else if (game->map[i][j] == 0)
				draw_rectangle(game, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
