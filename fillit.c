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

/*static void			ft_create_map(t_env *env)
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
}*/

void				fillit(t_env *env)
// sert uniquement à afficher les tetris avec leurs lettres, tu peux tout supprimer si besoin
{
//	ft_create_map(env);
	int				i;
	int				j;
	t_tetri			tetri;
	char			*str;
	int				index;

	i = 0;
	while (i < env->nb_tetris)
	{
		tetri = env->tetris[i];
		str = ft_memalloc(sizeof(char) * (20 + 1));
		j = 0;
		while (j < 20)
		{
			str[j] = '.';
			if (j == 4 || j == 9 || j == 14 || j == 19)
				str[j] = '\n';
			j++;
		}
		index = 0;
		while (tetri.type.place_tetri(str, index, tetri.letter, 4) == INVALID_PLACEMENT)
			index++;
		ft_putstr(str);
		i++;
		if (i < env->nb_tetris)
			ft_putchar('\n');
		ft_memdel((void **)&str);
	}
}
