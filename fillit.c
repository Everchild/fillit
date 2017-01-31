/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 10:43:21 by drecours          #+#    #+#             */
/*   Updated: 2017/01/30 15:10:50 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void			ft_create_map(t_env *env)
{
	char			*map;
	int				side;
	int				i;
	int				nb_caract;

	i = -1;
	side = ft_sqrt(nb_tetri * 4);
	nb_caract = side * (side + 1);
	if (!(map = (char *)ft_memalloc(sizeof(char) * (nb_caract + 1))))
		return (NULL);
	while (++i < nb_caract)
	{
		if (i == side || (i > side && (i - side) % (side + 1) == 0))
			map[i] = '\n';
		else
			map[i] = '.';
	}
	map[i] = '\0';
	return (map);
}

void				fillit(t_env *env)
{
	ft_create_map(env);
}
