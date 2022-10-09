/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:45:59 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/28 14:54:26 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

int	ft_is_line_of_1(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (0);
		i ++;
	}
	return (1);
}

void	ft_map_not_closed(t_game game)
{
	int	i;
	int	nb_last_line;
	int	length_line;

	i = 1;
	nb_last_line = game.win_size.height - 1;
	length_line = game.win_size.width - 1;
	if (ft_is_line_of_1(game.map[0]) == 0
		|| ft_is_line_of_1(game.map[nb_last_line]) == 0)
		ft_free_and_close(game);
	while (i < nb_last_line)
	{
		if (game.map[i][0] != '1' || game.map[i][length_line] != '1')
			ft_free_and_close(game);
		i ++;
	}
}

int	ft_wrong_char(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_map (str);
	while (i < len)
	{
		if (!(str[i] == '0' || str[i] == '1' || str[i] == 'C' || str[i] == 'E'
				|| str[i] == 'P' || str[i] == 'X'))
			return (1);
		i ++;
	}
	return (i);
}

void	ft_check_map_error(int ref_width, char *str, int check, t_game game)
{
	if (check == 1)
	{
		if (ref_width == -1 || ref_width == 0 || ft_wrong_char(str) == 1)
		{
			write (2, "Error\nSize or char error in your map\n", 37);
			if (ref_width > 0)
				free(game.lst);
			exit (-1);
		}
	}
	else
	{
		if ((ft_strlen_map(str) != ref_width && ft_strlen_map(str) != -1)
			|| ft_wrong_char(str) == 1)
		{
			write (2, "Error\nSize or char error in your map\n", 37);
			if (ref_width > 0)
				free(game.lst);
			exit (-1);
		}
	}
}

int	ft_check_arg_error(int argc, char **argv)
{
	int	fd;

	if (argc > 2)
	{
		write (2, "Error\nToo many arguments\n", 25);
		exit (-1);
	}
	if (argc == 1)
	{
		write (2, "Error\nMissing path for map\n", 27);
		exit (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write (2, "Error\nFile error\n", 17);
		exit (-1);
	}
	else
		return (fd);
}
