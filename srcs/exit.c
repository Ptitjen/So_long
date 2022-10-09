/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:16:19 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/28 15:42:25 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

void	ft_no_exit(t_game game)
{
	if (game.exit.list_i.nb == 0)
	{
		write (2, "Error\nNo exit\n", 14);
		free(game.lst);
		free(game.map);
		exit (-1);
	}
}

t_game	ft_init_exit(t_game game)
{
	char	*str;
	int		n;

	n = 0;
	game.exit.height = TILE_SIZE;
	game.exit.width = TILE_SIZE;
	game.exit.list_i = ft_search_multi(game.map, 'E');
	ft_no_exit(game);
	game.exit.anim = malloc (sizeof(void *) * 24);
	while (n < 24)
	{
		str = ft_strjoin("img/exit", ft_itoa(n + 1));
		str = ft_strjoin(str, ".png");
		game.exit.anim[n] = mlx_png_file_to_image(game.mlx, str, \
		&game.exit.width, &game.exit.height);
		n ++;
		free(str);
	}
	game.exit.image = game.exit.anim[0];
	game.exit.nb_image = 1;
	return (game);
}

t_game	ft_anim_exit(t_game game)
{	
	if (game.exit.nb_image == 24)
	{
		game.exit.image = game.exit.anim[0];
		game.exit.nb_image = 1;
	}
	else
	{
		game.exit.image = game.exit.anim[game.exit.nb_image - 1];
		game.exit.nb_image ++;
	}
	return (game);
}

int	ft_animate_exit(t_game *game)
{	
	int	n;

	n = 0;
	*game = ft_anim_exit(*game);
	if (game->game_over == 0)
	{
		while (game->exit.list_i.coord[n].x != -1)
		{
			mlx_put_image_to_window(game->mlx, game->win, \
			game->background.image, \
			game->exit.list_i.coord[n].x * TILE_SIZE, \
			game->exit.list_i.coord[n].y * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->win, game->exit.image, \
			game->exit.list_i.coord[n].x * TILE_SIZE, \
			game->exit.list_i.coord[n].y * TILE_SIZE);
			n ++;
		}
	}
	return (0);
}
