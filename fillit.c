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

static void			ft_create_map(t_env *env, int nb_caract)
{
	int				i;

	i = -1;
	while (++i < nb_caract)
	{
		if (i == env->side || (i > env->side && (i - env->side) % (env->side + 1) == 0))
			env->map[i] = '\n';
		else
			env->map[i] = '.';
	}
}

static void	ft_remove_tetri(t_env *env, t_tetri tetri, int nb_caract)
{
	int		i;

	i = 0;
	while (i < nb_caract)
	{
		if (env->map[i] == tetri.letter)
			env->map[i] = '.';
		i++;
	}
}

static t_bool	ft_backtrack(t_env *env, int nb_caract, int i)
{
	t_tetri		tetri;
	int			position;

	tetri = env->tetris[i];
	position = 0;
	if (i >= env->nb_tetris)
		return (TRUE);
	while (position < nb_caract)
	{
		if (tetri.type.place_tetri(env->map, position, tetri.letter, env->side) == TETRI_PLACED)
		{
			if (ft_backtrack(env, nb_caract, i + 1))
				return (TRUE);
			ft_remove_tetri(env, tetri, nb_caract);
		}
		position++;
	}
	return (FALSE);
}

static void	ft_complete_map(t_env *env)
{
	int				nb_caract;

	env->side = ft_sqrt(env->nb_tetris * 4);
	nb_caract = env->side * (env->side + 1);
	if (!(env->map = (char *)ft_memalloc(sizeof(char) * (nb_caract + 1))))
		ft_exit("error: failed to allocate memory", FAILED_TO_MALLOC);
	ft_create_map(env, nb_caract);
	while (ft_backtrack(env, nb_caract, 0) == FALSE)
	{
		env->side++;
		ft_memdel((void **)&env->map);
		if (!(env->map = (char *)ft_memalloc(sizeof(char) * ((env->side * (env->side + 1)) + 1))))
			ft_exit("error: failed to allocate memory", FAILED_TO_MALLOC);
		nb_caract = env->side * (env->side + 1);
		ft_create_map(env, nb_caract);
	}
}


void				fillit(t_env *env)
// sert uniquement à afficher les tetris avec leurs lettres, tu peux tout supprimer si besoin
{
	ft_complete_map(env);
	ft_putstr(env->map);
/*
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
*/
}
