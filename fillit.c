/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:28:29 by sbrochar          #+#    #+#             */
/*   Updated: 2017/01/16 17:41:25 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

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
		i++;
	}
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
