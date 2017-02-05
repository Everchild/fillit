/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 10:43:21 by drecours          #+#    #+#             */
/*   Updated: 2017/02/03 11:54:29 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void			ft_init_map(t_env *env, int size_map)
{
	int				i;

	i = -1;
	while (++i < size_map)
	{
		if (i == env->side
			|| (i > env->side && (i - env->side) % (env->side + 1) == 0))
			env->map[i] = '\n';
		else
			env->map[i] = '.';
	}
}

static void			ft_remove_tetri(t_env *env, t_tetri tetri, int size_map)
{
	int				i;

	i = 0;
	while (i < size_map)
	{
		if (env->map[i] == tetri.letter)
			env->map[i] = '.';
		i++;
	}
}

static t_bool		ft_backtrack(t_env *env, int size_map, int i)
{
	t_tetri			tetri;
	int				position;

	tetri = env->tetris[i];
	position = 0;
	if (i >= env->nb_tetris)
		return (TRUE);
	while (position < size_map)
	{
		if (tetri.type.place_tetri(env->map, position, tetri.letter, env->side)
			== TETRI_PLACED)
		{
			if (ft_backtrack(env, size_map, i + 1))
				return (TRUE);
			ft_remove_tetri(env, tetri, size_map);
		}
		position++;
	}
	return (FALSE);
}

void				fillit(t_env *env)
{
	int				size_map;

	env->side = ft_sqrt(env->nb_tetris * 4);
	size_map = env->side * (env->side + 1);
	if (!(env->map = (char *)ft_memalloc(sizeof(char) * (size_map + 1))))
		ft_exit("error", FAILED_TO_MALLOC);
	ft_init_map(env, size_map);
	while (!ft_backtrack(env, size_map, 0))
	{
		env->side++;
		ft_memdel((void **)&env->map);
		if (!(env->map = (char *)ft_memalloc(sizeof(char) * (size_map + 1))))
			ft_exit("error", FAILED_TO_MALLOC);
		size_map = env->side * (env->side + 1);
		ft_init_map(env, size_map);
	}
	ft_putstr(env->map);
}
