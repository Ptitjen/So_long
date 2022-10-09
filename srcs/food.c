/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:03:40 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/28 15:06:08 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

void	ft_no_food(t_game game, int choice)
{
	if (game.food.list_i.nb == 0 && choice == 2)
	{
		write (2, "Error\nNo food\n", 14);
		free(game.lst);
		free(game.map);
		exit (-1);
	}
}

t_game	ft_init_food(t_game game, int choice)
{
	char	*str;
	int		n;

	n = 0;
	game.food.height = TILE_SIZE;
	game.food.width = TILE_SIZE;
	game.food.list_i = ft_search_multi(game.map, 'C');
	ft_no_food(game, choice);
	if (choice == 2)
	{
		game.food.anim = malloc (sizeof(void *) * 16);
		while (n < 16)
		{
			str = ft_strjoin("img/food", ft_itoa(n + 1));
			str = ft_strjoin(str, ".png");
			game.food.anim[n] = mlx_png_file_to_image(game.mlx, str, \
			&game.food.width, &game.food.height);
			n ++;
			free (str);
		}
	}
	game.food.image = game.food.anim[0];
	game.food.nb_image = 1;
	game.all_food_eaten = game.food.list_i.nb;
	return (game);
}

t_game	*ft_eat_food(t_game *game)
{
	game->all_food_eaten --;
	game->map[game->unicorn.y][game->unicorn.x] = '0';
	*game = ft_init_background (*game);
	*game = ft_init_food (*game, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->background.image, \
	game->unicorn.x * TILE_SIZE, game->unicorn.y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->unicorn.image, \
	game->unicorn.x * TILE_SIZE, game->unicorn.y * TILE_SIZE);
	return (game);
}

t_game	ft_anim_food(t_game game)
{	
	if (game.food.nb_image == 16)
	{
		game.food.image = game.food.anim[0];
		game.food.nb_image = 1;
	}
	else
	{
		game.food.image = game.food.anim[game.food.nb_image - 1];
		game.food.nb_image ++;
	}
	return (game);
}

int	ft_animate_food(t_game *game)
{	
	int	n;

	n = 0;
	*game = ft_anim_food(*game);
	if (game->game_over == 0)
	{
		while (game->food.list_i.coord[n].x != -1)
		{
			mlx_put_image_to_window(game->mlx, game->win, \
			game->background.image, \
			game->food.list_i.coord[n].x * TILE_SIZE, \
			game->food.list_i.coord[n].y * TILE_SIZE);
			mlx_put_image_to_window(game->mlx, game->win, game->food.image, \
			game->food.list_i.coord[n].x * TILE_SIZE, \
			game->food.list_i.coord[n].y * TILE_SIZE);
			n ++;
		}
	}
	return (0);
}
