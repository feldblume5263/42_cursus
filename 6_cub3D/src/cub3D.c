/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:41:12 by Feldblume         #+#    #+#             */
/*   Updated: 2020/10/15 15:54:21 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../includes/mlx.h"

#define USE_MATH_DEFINES
# define TILE_SIZE 32
# define MAP_ROWS 11
# define MAP_COLS 15
# define TILE_SIZE 32
# define WINDOW_WIDTH MAP_COLS * TILE_SIZE
# define WINDOW_HEIGHT MAP_ROWS * TILE_SIZE
# define TO_COORD(X, Y) ((int)floor(Y) * WINDOW_WIDTH + (int)floor(X))

typedef struct	s_img
{
	void		*img;
	int			*data;

	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;

	int			map[MAP_ROWS][MAP_COLS];
}				t_game;

typedef struct	s_player
{
	double		x;
	double		y;
	double		radius;
	double		turnDirection;
	double		walkDirection;
	double		rotationAngle;
	double		moveSpeed;
	double		rotationSpeed;
}				t_player;


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

void			player_init(t_player *player)
{
	player->turnDirection = 0;
	player->walkDirection = 0;
	player->rotationAngle = M_PI / 2;
	player->moveSpeed = 3.0;
	player->rotationSpeed = 3 * (M_PI / 180);
}

void			img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}


void			window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "mlx 42");
}

void				map_parsing(t_game *game)
{
	int		walls[MAP_ROWS][MAP_COLS] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, walls, sizeof(int) * MAP_ROWS * MAP_COLS);
	return ;
}

int				player_loop(t_player *player)
{
	player->radius = 0;
	return (0);
}

int				main_loop(t_game *game)
{
	t_player	player;

	player_init(&player);
	draw_rectangles(game);
	draw_lines(game);
	mlx_loop_hook(game->mlx, &player_loop, &player);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);

	return (0);
}

int				main(void)
{
	t_game		game;


	map_parsing(&game);
	window_init(&game);
	img_init(&game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
