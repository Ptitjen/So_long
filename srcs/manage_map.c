/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:05:52 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/25 20:06:02 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

int	ft_strlen_map(char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i ++;
	return (i);
}

void	ft_free_and_close(t_game game)
{
	write (2, "Error\nMap not closed\n", 21);
	free(game.lst);
	free(game.map);
	exit (-1);
}

t_game	ft_check_size(t_game game, int fd)
{
	char	*str;
	int		ref_width;

	str = get_next_line(fd);
	ref_width = ft_strlen_map(str);
	ft_check_map_error (ref_width, str, 1, game);
	game.win_size.width = ref_width;
	game.win_size.height = 0;
	game.lst = malloc (1);
	game.lst = "\0";
	game.lst = ft_strjoin(game.lst, str);
	while (str != NULL)
	{
		str = get_next_line (fd);
		ft_check_map_error (ref_width, str, 2, game);
		game.lst = ft_strjoin(game.lst, str);
		game.win_size.height ++;
	}
	game.map = ft_split (game.lst, '\n');
	ft_map_not_closed(game);
	return (game);
}
