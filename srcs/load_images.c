/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:33:38 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/24 18:43:12 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

void	ft_load_food(t_game *game)
{
	int	n;

	n = 0;
	while (game->food.list_i.coord[n].x != -1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->food.image, \
		game->food.list_i.coord[n].x * TILE_SIZE, \
		game->food.list_i.coord[n].y * TILE_SIZE);
		n ++;
	}
}

void	ft_load_wall(t_game *game)
{
	int	n;

	n = 0;
	while (game->wall.list_i.coord[n].x != -1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall.image, \
		game->wall.list_i.coord[n].x * TILE_SIZE, \
		game->wall.list_i.coord[n].y * TILE_SIZE);
		n ++;
	}
}

void	ft_load_exit(t_game *game)
{
	int	n;

	n = 0;
	while (game->exit.list_i.coord[n].x != -1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit.image, \
		game->exit.list_i.coord[n].x * TILE_SIZE, \
		game->exit.list_i.coord[n].y * TILE_SIZE);
		n ++;
	}
}

void	ft_load_enemy(t_game *game)
{
	int	n;

	n = 0;
	while (game->enemy.list_i.coord[n].x != -1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.image, \
		game->enemy.list_i.coord[n].x * TILE_SIZE, \
		game->enemy.list_i.coord[n].y * TILE_SIZE);
		n ++;
	}
}

void	ft_load_background(t_game *game)
{
	int	n;

	n = 0;
	while (game->background.list_i.coord[n].x != -1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->background.image, \
		game->background.list_i.coord[n].x * TILE_SIZE, \
		game->background.list_i.coord[n].y * TILE_SIZE);
		n ++;
	}
}
