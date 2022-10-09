/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:14:43 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/25 20:54:54 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

void	ft_draw_window(t_game *game, int i)
{
	mlx_clear_window (game->mlx, game->win);
	ft_load_exit(game);
	ft_load_food(game);
	ft_load_wall(game);
	ft_load_enemy(game);
	ft_load_background(game);
	mlx_string_put (game->mlx, game->win, 5, 2 * TILE_SIZE / 3, 0xFFFFFF, \
	ft_itoa(game->score));
	mlx_put_image_to_window(game->mlx, game->win, game->unicorn.image, \
	game->unicorn.x * TILE_SIZE, game->unicorn.y * TILE_SIZE);
}

t_game	ft_load_unicorn_images(t_game game)
{
	game.unicorn.image_up = mlx_png_file_to_image(game.mlx, \
	"img/player_up.png", &game.unicorn.width, &game.unicorn.height);
	game.unicorn.image_down = mlx_png_file_to_image(game.mlx, \
	"img/player_down.png", &game.unicorn.width, &game.unicorn.height);
	game.unicorn.image_left = mlx_png_file_to_image(game.mlx, \
	"img/player_left.png", &game.unicorn.width, &game.unicorn.height);
	game.unicorn.image_right = mlx_png_file_to_image(game.mlx, \
	"img/player_right.png", &game.unicorn.width, &game.unicorn.height);
	return (game);
}

void	ft_init_wall_under_string(t_game *game, int choice)
{
	if (choice == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall.image, \
		TILE_SIZE, (game->win_size.height - 1) * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->wall.image, \
		2 * TILE_SIZE, (game->win_size.height - 1) * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->wall.image, \
		0, (game->win_size.height - 1) * TILE_SIZE);
	}
	if (choice == 2)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall.image, \
		0, 0);
		mlx_put_image_to_window(game->mlx, game->win, game->wall.image, \
		TILE_SIZE, 0);
		mlx_put_image_to_window(game->mlx, game->win, game->wall.image, \
		2 * TILE_SIZE, 0);
		mlx_string_put (game->mlx, game->win, 5, 2 * TILE_SIZE / 3, \
		0xFFFFFF, ft_itoa(game->score));
	}
}

int	ft_random(void)
{
	static int	rand;
	static int	rand1;
	int			tab[12];

	tab[0] = 1;
	tab[1] = 13;
	tab[2] = 2;
	tab[3] = 0;
	tab[4] = 1;
	tab[5] = 13;
	tab[6] = 2;
	tab[7] = 0;
	tab[8] = 1;
	tab[9] = 13;
	tab[10] = 2;
	tab[11] = 0;
	if (rand >= 0 && rand <= 100)
		rand = rand + 3;
	if (rand > 100)
		rand = 0;
	if (rand1 == 4)
		rand1 = 0;
	else
		rand1 ++;
	return (tab[rand % 8 + rand1]);
}

int	ft_animate_all(t_game *game)
{
	ft_animate_enemy(game);
	ft_animate_food(game);
	ft_animate_exit(game);
	return (0);
}
