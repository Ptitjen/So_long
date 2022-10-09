/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:16 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/28 12:03:17 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

void	ft_check_game_end(t_game *game)
{
	if (game->map[game->unicorn.y][game->unicorn.x] == 'X')
		game = ft_game_over(game);
	else if (game->map[game->unicorn.y][game->unicorn.x] == 'E'
	&& game->all_food_eaten == 0)
		game = ft_game_won(game);
}

int	ft_deal_key(int key, t_game *game)
{
	if (key == 53)
		ft_close_game(game);
	if (game->game_over != 1)
	{
		ft_init_wall_under_string(game, 1);
		*game = ft_change_direction(*game, key);
		game = ft_move_enemy (game);
		if (game->game_over != 1 && ft_check_if_move_ok (*game, key) == 1)
		{
			game = ft_move_unicorn(game, key);
			if (game->map[game->unicorn.y][game->unicorn.x] == 'C')
				game = ft_eat_food(game);
		}		
		mlx_put_image_to_window(game->mlx, game->win, game->unicorn.image, \
		game->unicorn.x * TILE_SIZE, game->unicorn.y * TILE_SIZE);
		ft_init_wall_under_string(game, 2);
		ft_check_game_end(game);
	}	
	return (0);
}

t_game	ft_game_init(t_game game, int fd)
{
	game.mlx = mlx_init();
	game = ft_check_size (game, fd);
	game = ft_init_unicorn (game);
	game = ft_init_enemy (game);
	game = ft_init_food (game, 2);
	game = ft_init_exit (game);
	game = ft_init_background (game);
	game = ft_init_wall (game);
	game.score = 0;
	game.game_over = 0;
	return (game);
}

int	ft_close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	write(1, "Game closed by player\n", 22);
	if (game->game_over != 1)
		ft_clean_close(game);
	exit(0);
}
