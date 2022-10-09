/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:58:21 by jeulliot          #+#    #+#             */
/*   Updated: 2022/02/22 16:04:30 by jeulliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_checklength(int nb)
{
	int	len;
	int	n;

	len = 0;
	n = nb;
	if (n < 0)
		len++;
	if (nb == 0)
		return (1);
	else
	{
		while (n != 0)
		{
			len ++;
			n = n / 10;
		}
		return (len);
	}
}

static int	ft_power(int len)
{
	int	i;
	int	p;

	p = 1;
	i = 1;
	while (i ++ < len)
		p *= 10;
	return (p);
}

static char	*ft_itoabis(char *tab, int n, int len)
{
	int	i;

	i = -1;
	if (n < 0)
		tab[++ i] = '-';
	while (i ++ < len - 1)
	{
		if (n >= 0)
			tab[i] = (n / ft_power(len - i)) + 48;
		else
			tab[i] = -(n / ft_power(len - i)) + 48;
		n = n - (ft_power(len - i) * (n / ft_power(len - i)));
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*tab;

	len = ft_checklength(n);
	tab = malloc(sizeof(char) * (len + 1));
	if (tab)
		tab = ft_itoabis(tab, n, len);
	return (tab);
}
