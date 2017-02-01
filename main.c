/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:28:29 by sbrochar          #+#    #+#             */
/*   Updated: 2017/01/16 17:41:25 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void			init_all_types(t_place_type all_types[TT_COUNT])
{
	all_types = { { TT_HORIZ_I, place_horiz_i },
	{ TT_CLASSIC_I, place_classic_i },
	{ TT_CLASSIC_T, place_classic_t },
	{ TT_REV_T, place_rev_t },
	{ TT_LEFT_T, place_left_t },
	{ TT_RIGHT_T, place_right_t },
	{ TT_CLASSIC_J, place_classic_j },
	{ TT_RIGHT_J, place_right_j },
	{ TT_REV_J, place_rev_j },
	{ TT_LEFT_J, place_left_j },
	{ TT_CLASSIC_L, place_classic_l },
	{ TT_REV_L, place_rev_l },
	{ TT_RIGHT_L, place_right_l },
	{ TT_LEFT_L, place_left_l },
	{ TT_SQUARE, place_square },
	{ TT_LAID_S, place_laid_s },
	{ TT_UP_S, place_up_s },
	{ TT_LAID_Z, place_laid_z },
	{ TT_UP_Z, place_up_z } };
}

static void			init_env(t_env *env, char *file)
{
	int				i;

	i = 0;
	env->fd = open(file, O_RDONLY);
	if (env->fd == FAILED_TO_OPEN)
		ft_exit("error: failed to open the file", FAILED_TO_OPEN);
	ft_bzero(env->file, MAX_CHARACTERS + 1);
	while (i <= MAX_TETRIMINOS)
	{
		env->tetris[i].str = NULL;
		env->tetris[i].nb_hashtags = 0;
		env->tetris[i].nb_links = 0;
		env->tetris[i].type.type = TT_COUNT;
		env->tetris[i].type.place_tetri = NULL;
		i++;
	}
	env->nb_tetris = 0;
	env->map = NULL;
	env->side = 0;
	init_all_types(env->all_types);
}

static void			destroy_env(t_env *env)
{
	int				i;

	i = 0;
	while (i < MAX_TETRIMINOS)
	{
		ft_memdel((void **)&(env->tetris[i]));
		i++;
	}
	ft_memdel((void **)&(env->map));
}

int					main(int argc, char **argv)
{
	t_env			env;

	if (argc == 2)
	{
		init_env(&env, argv[1]);
		parsing_tetris(&env);
//		fillit(&env);
		destroy_env(&env);
	}
	else
		ft_putendl("usage: ./fillit file");
	return (E_SUCCESS);
}
