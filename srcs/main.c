/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:28:49 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/28 13:07:07 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	fd = ft_check_arg_error(argc, argv);
	game = ft_game_init(game, fd);
	close(fd);
	if (fd == -1)
		return (-1);
	game.win = mlx_new_window(game.mlx, game.win_size.width * TILE_SIZE, \
	game.win_size.height * TILE_SIZE, "Catch the rainbows and escape!");
	ft_draw_window(&game, 1);
	if (game.game_over == 0)
		mlx_loop_hook(game.mlx, ft_animate_all, &game);
	mlx_key_hook(game.win, ft_deal_key, &game);
	mlx_hook(game.win, 17, 0, ft_close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
