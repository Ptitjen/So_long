/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   landscape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:04:19 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/25 10:48:51 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

t_game	ft_init_background(t_game game)
{
	game.background.height = TILE_SIZE;
	game.background.width = TILE_SIZE;
	game.background.list_i = ft_search_multi(game.map, '0');
	game.background.image = mlx_png_file_to_image(game.mlx, \
		"img/background.png", &game.background.width, &game.background.height);
	if (game.background.image == NULL)
	{
		write(1, "Erreur chargement image\n", 24);
		exit (-1);
	}
	return (game);
}

t_game	ft_init_wall(t_game game)
{
	game.wall.height = TILE_SIZE;
	game.wall.width = TILE_SIZE;
	game.wall.list_i = ft_search_multi(game.map, '1');
	game.wall.image = mlx_png_file_to_image(game.mlx, "img/wall32.png", \
		&game.wall.width, &game.wall.height);
	if (game.wall.image == NULL)
	{
		write(1, "Erreur chargement image\n", 24);
		exit (-1);
	}
	return (game);
}
