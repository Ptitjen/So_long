/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:11:12 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/28 11:08:25 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

t_game	*ft_change_coord_enemy(t_game *game, int n, int key)
{
	if (key == 13)
		game = ft_update_enemy_up(game, n);
	if (key == 0)
		game = ft_update_enemy_left(game, n);
	if (key == 2)
		game = ft_update_enemy_right(game, n);
	if (key == 1)
		game = ft_update_enemy_down(game, n);
	return (game);
}

int	ft_check_collision_enemy(t_game *game, t_coord coord, int key)
{
	if (key == 13)
		if (ft_check_around(coord.x, coord.y, game, 'u') == 0
			|| (game->unicorn.x == coord.x && game->unicorn.y == coord.y - 1))
			return (0);
	if (key == 0)
		if (ft_check_around(coord.x, coord.y, game, 'l') == 0
			|| (game->unicorn.x == coord.x - 1 && game->unicorn.y == coord.y))
			return (0);
	if (key == 2)
		if (ft_check_around(coord.x, coord.y, game, 'r') == 0
			|| (game->unicorn.x == coord.x + 1 && game->unicorn.y == coord.y))
			return (0);
	if (key == 1)
		if (ft_check_around(coord.x, coord.y, game, 'd') == 0
			|| (game->unicorn.x == coord.x && game->unicorn.y == coord.y + 1))
			return (0);
	return (1);
}

t_game	*ft_move_enemy(t_game *game)
{
	int			n;	
	int			key;

	n = 0;
	while (game->enemy.list_i.coord[n].x != -1)
	{
		key = ft_random();
		if (ft_check_collision_enemy(game, game->enemy.list_i.coord[n], key) \
		== 1)
		{			
			game = ft_change_coord_enemy(game, n, key);
			ft_load_enemy(game);
			ft_load_background(game);
		}
		mlx_put_image_to_window(game->mlx, game->win, game->background.image, \
		game->enemy.list_i.coord[n].x * TILE_SIZE, \
		game->enemy.list_i.coord[n].y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.image, \
		game->enemy.list_i.coord[n].x * TILE_SIZE, \
		game->enemy.list_i.coord[n].y * TILE_SIZE);
		n ++;
	}
	return (game);
}
