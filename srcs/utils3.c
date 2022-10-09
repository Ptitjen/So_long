/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:40:41 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/24 19:53:10 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

t_game	*ft_update_enemy_up(t_game *game, int n)
{
	game->map[game->enemy.list_i.coord[n].y][game->enemy.list_i.coord[n].x] \
	= '0';
	game->map[game->enemy.list_i.coord[n].y - 1][game->enemy.list_i.coord[n].x] \
	= 'X';
	game->enemy.list_i.coord[n].y -= 1;
	game->background.list_i = ft_search_multi(game->map, '0');
	return (game);
}

t_game	*ft_update_enemy_right(t_game *game, int n)
{
	game->map[game->enemy.list_i.coord[n].y][game->enemy.list_i.coord[n].x] \
	= '0';
	game->map[game->enemy.list_i.coord[n].y][game->enemy.list_i.coord[n].x + 1] \
	= 'X';
	game->enemy.list_i.coord[n].x += 1;
	game->background.list_i = ft_search_multi(game->map, '0');
	return (game);
}

t_game	*ft_update_enemy_left(t_game *game, int n)
{
	game->map[game->enemy.list_i.coord[n].y][game->enemy.list_i.coord[n].x] \
	= '0';
	game->map[game->enemy.list_i.coord[n].y][game->enemy.list_i.coord[n].x - 1] \
	= 'X';
	game->enemy.list_i.coord[n].x -= 1;
	game->background.list_i = ft_search_multi(game->map, '0');
	return (game);
}

t_game	*ft_update_enemy_down(t_game *game, int n)
{
	game->map[game->enemy.list_i.coord[n].y][game->enemy.list_i.coord[n].x] \
	= '0';
	game->map[game->enemy.list_i.coord[n].y + 1][game->enemy.list_i.coord[n].x] \
	= 'X';
	game->enemy.list_i.coord[n].y += 1;
	game->background.list_i = ft_search_multi(game->map, '0');
	return (game);
}

int	ft_check_around(int x, int y, t_game *game, char dir)
{
	if (dir == 'u')
		if (game->map[y - 1][x] == '1' || game->map[y - 1][x] == 'E'
			|| game->map[y - 1][x] == 'C' || game->map[y - 1][x] == 'X')
			return (0);
	if (dir == 'l')
		if (game->map[y][x - 1] == '1' || game->map[y][x - 1] == 'E'
			|| game->map[y][x - 1] == 'C' || game->map[y][x - 1] == 'X')
			return (0);
	if (dir == 'r')
		if (game->map[y][x + 1] == '1' || game->map[y][x + 1] == 'E'
			|| game->map[y][x + 1] == 'C' || game->map[y][x + 1] == 'X')
			return (0);
	if (dir == 'd')
		if (game->map[y + 1][x] == '1' || game->map[y + 1][x] == 'E'
			|| game->map[y + 1][x] == 'C' || game->map[y + 1][x] == 'X')
			return (0);
	return (1);
}
