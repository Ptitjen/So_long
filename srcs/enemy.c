/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:03:28 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/25 20:32:02 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

t_game	ft_init_enemy(t_game game)
{
	char	*str;
	int		n;

	n = 0;
	game.enemy.height = TILE_SIZE;
	game.enemy.width = TILE_SIZE;
	game.enemy.list_i = ft_search_multi(game.map, 'X');
	game.enemy.anim = malloc (sizeof(void *) * 24);
	while (n < 24)
	{
		str = ft_strjoin("img/enemy", ft_itoa(n + 1));
		str = ft_strjoin(str, ".png");
		game.enemy.anim[n] = mlx_png_file_to_image(game.mlx, str, \
		&game.enemy.width, &game.enemy.height);
		n ++;
		free (str);
	}
	game.enemy.image = game.enemy.anim[0];
	game.enemy.nb_image = 1;
	return (game);
}

t_game	ft_anim_enemy(t_game game)
{	
	if (game.enemy.nb_image == 24)
	{
		game.enemy.image = game.enemy.anim[0];
		game.enemy.nb_image = 1;
	}
	else
	{
		game.enemy.image = game.enemy.anim[game.enemy.nb_image - 1];
		game.enemy.nb_image ++;
	}
	return (game);
}

int	ft_animate_enemy(t_game *game)
{	
	int	n;

	n = 0;
	*game = ft_anim_enemy(*game);
	if (game->game_over == 0)
	{
		while (game->enemy.list_i.coord[n].x != -1)
		{
			mlx_put_image_to_window(game->mlx, game->win, \
			game->background.image, \
			game->enemy.list_i.coord[n].x * TILE_SIZE, \
			game->enemy.list_i.coord[n].y * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->win, game->enemy.image, \
			game->enemy.list_i.coord[n].x * TILE_SIZE, \
			game->enemy.list_i.coord[n].y * TILE_SIZE);
			n ++;
		}
	}
	return (0);
}
