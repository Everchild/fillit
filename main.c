/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:28:29 by sbrochar          #+#    #+#             */
/*   Updated: 2017/02/03 11:52:00 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void			init_struct(t_place_type *p, t_type_tetri type,
						t_check_type_fct check_type,
						t_place_type_fct place_type)
{
	p->type = type;
	p->check_type = check_type;
	p->place_tetri = place_type;
}

static void			init_all_types(t_place_type *all_types)
{
	init_struct(&all_types[0], TT_HORIZ_I, check_horiz_i, place_horiz_i);
	init_struct(&all_types[1], TT_CLASSIC_I, check_classic_i, place_classic_i);
	init_struct(&all_types[2], TT_CLASSIC_T, check_classic_t, place_classic_t);
	init_struct(&all_types[3], TT_REV_T, check_rev_t, place_rev_t);
	init_struct(&all_types[4], TT_LEFT_T, check_left_t, place_left_t);
	init_struct(&all_types[5], TT_RIGHT_T, check_right_t, place_right_t);
	init_struct(&all_types[6], TT_CLASSIC_J, check_classic_j, place_classic_j);
	init_struct(&all_types[7], TT_RIGHT_J, check_right_j, place_right_j);
	init_struct(&all_types[8], TT_REV_J, check_rev_j, place_rev_j);
	init_struct(&all_types[9], TT_LEFT_J, check_left_j, place_left_j);
	init_struct(&all_types[10], TT_CLASSIC_L, check_classic_l, place_classic_l);
	init_struct(&all_types[11], TT_REV_L, check_rev_l, place_rev_l);
	init_struct(&all_types[12], TT_RIGHT_L, check_right_l, place_right_l);
	init_struct(&all_types[13], TT_LEFT_L, check_left_l, place_left_l);
	init_struct(&all_types[14], TT_SQUARE, check_square, place_square);
	init_struct(&all_types[15], TT_LAID_S, check_laid_s, place_laid_s);
	init_struct(&all_types[16], TT_UP_S, check_up_s, place_up_s);
	init_struct(&all_types[17], TT_LAID_Z, check_laid_z, place_laid_z);
	init_struct(&all_types[18], TT_UP_Z, check_up_z, place_up_z);
}

static void			init_env(t_env *env, char *file)
{
	int				i;

	i = 0;
	env->fd = open(file, O_RDONLY);
	if (env->fd == FAILED_TO_OPEN)
		ft_exit("error", FAILED_TO_OPEN);
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
	init_all_types(&env->all_types[0]);
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
		fillit(&env);
		destroy_env(&env);
	}
	else
		ft_putendl("usage: ./fillit file");
	return (E_SUCCESS);
}
