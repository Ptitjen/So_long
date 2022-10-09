/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:51:19 by jeulliot          #+#    #+#             */
/*   Updated: 2022/03/28 12:06:52 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unicorn_game.h"

t_coord	ft_search_spot(char **str, char c)
{
	int		i;
	int		j;
	t_coord	spot;

	i = 0;
	spot.x = -1;
	spot.y = -1;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == c)
			{
				spot.x = j;
				spot.y = i;
				return (spot);
			}
			j ++;
		}
		i ++;
	}
	return (spot);
}

t_coord	*ft_add_to_list(t_coord *coord, int x, int y)
{
	t_coord	*tmp;
	int		len;
	int		i;

	len = 0;
	while (coord[len].x != -1)
		len ++;
	tmp = malloc(sizeof(t_coord) * (len + 2));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (coord[i].x != -1)
	{
		tmp[i] = coord[i];
		i ++;
	}
	tmp[i].x = x;
	tmp[i].y = y;
	tmp[i + 1].x = -1;
	tmp[i + 1].y = -1;
	free (coord);
	return (tmp);
}

t_list_item	ft_search_multi(char **str, char c)
{
	t_list_item	list_i;
	int			i;
	int			j;

	i = 0;
	list_i.nb = 0;
	list_i.coord = malloc(sizeof(t_coord));
	list_i.coord[0].x = -1;
	list_i.coord[0].y = -1;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == c)
			{
				list_i.nb ++;
				list_i.coord = ft_add_to_list(list_i.coord, j, i);
			}
			j ++;
		}
		i ++;
	}
	return (list_i);
}

int	ft_verify_nb_unicorn(char **str, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == c)
				count ++;
			j ++;
		}
		i ++;
	}
	return (count);
}

int	ft_check_if_move_ok(t_game game, int key)
{	
	if (ft_check_collision(game, key) == 0)
		return (0);
	if (ft_check_collision_exit(game, key) == 0)
		return (0);
	if (!(key == 13 || key == 0 || key == 1 || key == 2))
		return (0);
	return (1);
}
