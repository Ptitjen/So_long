/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:05:39 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/25 20:37:36 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

t_game	*ft_game_over(t_game *game)
{
	game->game_over = 1;
	mlx_clear_window (game->mlx, game->win);
	mlx_string_put (game->mlx, game->win, 2, TILE_SIZE / 2, 0xFFFFFF, \
	"GAME OVER");
	mlx_string_put (game->mlx, game->win, 2, TILE_SIZE * 5 / 2, 0xFFFFFF, \
	"Press ESC");
	ft_clean_close(game);
	return (game);
}

t_game	*ft_game_won(t_game *game)
{
	game->game_over = 1;
	mlx_clear_window (game->mlx, game->win);
	mlx_string_put (game->mlx, game->win, 2, TILE_SIZE / 2, 0xFFFFFF, \
	"YOU WIN!");
	mlx_string_put (game->mlx, game->win, 2, TILE_SIZE * 3 / 2, 0xFFFFFF, \
	"Score:");
	mlx_string_put (game->mlx, game->win, 2, TILE_SIZE * 5 / 2, 0xFFFFFF, \
	ft_itoa(game->score));
	mlx_string_put (game->mlx, game->win, 2, TILE_SIZE * 7 / 2, 0xFFFFFF, \
	"Press ESC");
	ft_clean_close(game);
	return (game);
}

void	ft_destroy_anim(t_game *game)
{
	int	i;

	i = 0;
	while (i < 24)
	{
		mlx_destroy_image(game->mlx, game->enemy.anim[i]);
		i ++;
	}
	i = 0;
	while (i < 24)
	{
		mlx_destroy_image(game->mlx, game->exit.anim[i]);
		i ++;
	}
		i = 0;
	while (i < 16)
	{
		mlx_destroy_image(game->mlx, game->food.anim[i]);
		i ++;
	}
}

void	ft_free_all(t_game *game)
{
	free(game->lst);
	free(game->map);
	free(game->wall.list_i.coord);
	free(game->background.list_i.coord);
	free(game->food.list_i.coord);
	free(game->exit.list_i.coord);
	free(game->exit.anim);
	free(game->food.anim);
	if (game->enemy.list_i.nb != 0)
	{
		free(game->enemy.list_i.coord);
		free(game->enemy.anim);
	}
}

void	ft_clean_close(t_game *game)
{
	ft_destroy_anim(game);
	ft_free_all(game);
	mlx_destroy_image(game->mlx, game->unicorn.image_down);
	mlx_destroy_image(game->mlx, game->unicorn.image_up);
	mlx_destroy_image(game->mlx, game->unicorn.image_left);
	mlx_destroy_image(game->mlx, game->unicorn.image_right);
	mlx_destroy_image(game->mlx, game->wall.image);
	mlx_destroy_image(game->mlx, game->background.image);
}
