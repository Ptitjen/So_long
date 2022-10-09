/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:03:17 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/28 15:45:53 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

t_game	ft_init_unicorn(t_game game)
{
	t_coord	spot;

	game.unicorn.height = TILE_SIZE;
	game.unicorn.width = TILE_SIZE;
	spot = ft_search_spot (game.map, 'P');
	if (ft_verify_nb_unicorn(game.map, 'P') != 1)
	{
		write (2, "Error\nWrong number of unicorns\n", 31);
		free(game.lst);
		free(game.map);
		exit (-1);
	}
	game.unicorn.x = spot.x;
	game.unicorn.y = spot.y;
	game = ft_load_unicorn_images(game);
	if (game.unicorn.image_right == NULL || game.unicorn.image_left == NULL
		|| game.unicorn.image_down == NULL || game.unicorn.image_up == NULL)
	{
		write(1, "Erreur chargement image\n", 24);
		exit (-1);
	}		
	game.unicorn.image = game.unicorn.image_right;
	return (game);
}

int	ft_check_collision(t_game game, int key)
{
	if (key == 13)
		if (game.map[game.unicorn.y - 1][game.unicorn.x] == '1'
		|| game.unicorn.y <= 0)
			return (0);
	if (key == 0)
		if (game.map[game.unicorn.y][game.unicorn.x - 1] == '1'
		|| game.unicorn.x <= 0)
			return (0);
	if (key == 2)
		if (game.map[game.unicorn.y][game.unicorn.x + 1] == '1'
		|| game.unicorn.x >= game.win_size.width - 1)
			return (0);
	if (key == 1)
		if (game.map[game.unicorn.y + 1][game.unicorn.x] == '1'
		|| game.unicorn.y >= game.win_size.height - 1)
			return (0);
	return (1);
}

int	ft_check_collision_exit(t_game game, int key)
{
	int	ok;

	ok = 0;
	if (key == 13 && game.map[game.unicorn.y - 1][game.unicorn.x] == 'E'
		&& game.all_food_eaten != 0)
			ok = 1;
	else if (key == 0 && game.map[game.unicorn.y][game.unicorn.x - 1] == 'E'
		&& game.all_food_eaten != 0)
			ok = 1;
	else if (key == 2 && game.map[game.unicorn.y][game.unicorn.x + 1] == 'E'
		&& game.all_food_eaten != 0)
			ok = 1;
	else if (key == 1 && game.map[game.unicorn.y + 1][game.unicorn.x] == 'E'
		&& game.all_food_eaten != 0)
			ok = 1;
	if (ok == 1)
	{
		mlx_string_put (game.mlx, game.win, 10, game.win_size.height \
		* TILE_SIZE - TILE_SIZE / 3, 0xFFFFFF, "NOT YET!");
		return (0);
	}
	return (1);
}

t_game	ft_change_direction(t_game game, int key)
{
	if (key == 13)
		game.unicorn.image = game.unicorn.image_up;
	if (key == 0)
		game.unicorn.image = game.unicorn.image_left;
	if (key == 2)
		game.unicorn.image = game.unicorn.image_right;
	if (key == 1)
		game.unicorn.image = game.unicorn.image_down;
	mlx_put_image_to_window(game.mlx, game.win, game.background.image, \
	game.unicorn.x * TILE_SIZE, game.unicorn.y * TILE_SIZE);
	ft_load_exit(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.unicorn.image, \
	game.unicorn.x * TILE_SIZE, game.unicorn.y * TILE_SIZE);
	return (game);
}

t_game	*ft_move_unicorn(t_game *game, int key)
{		
	mlx_put_image_to_window(game->mlx, game->win, game->background.image, \
	game->unicorn.x * TILE_SIZE, game->unicorn.y * TILE_SIZE);
	if (key == 13)
		game->unicorn.y -= 1;
	if (key == 0)
		game->unicorn.x -= 1;
	if (key == 2)
		game->unicorn.x += 1;
	if (key == 1)
		game->unicorn.y += 1;
	game->score ++;
	mlx_put_image_to_window(game->mlx, game->win, game->background.image, \
	game->unicorn.x * TILE_SIZE, game->unicorn.y * TILE_SIZE);
	ft_load_exit(game);
	mlx_put_image_to_window(game->mlx, game->win, game->unicorn.image, \
	game->unicorn.x * TILE_SIZE, game->unicorn.y * TILE_SIZE);
	return (game);
}
