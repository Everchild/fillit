/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:09:41 by sbrochar          #+#    #+#             */
/*   Updated: 2017/01/16 17:41:31 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void			register_tetris(t_env *env)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	read(env->fd, env->file, MAX_CHARACTERS + 1);
	if (env->file[MAX_CHARACTERS] != '\0')
		ft_exit("error", NON_VALID_FILE);
	while (env->file && env->file[i])
	{
		if (env->file[i])
		{
			env->tetris[j] = ft_strndup(env->file + i, TETRI_SIZE);
			i += TETRI_SIZE;
			if (env->file[i] && env->file[i] != '\n')
				ft_exit("error", NON_VALID_FILE);
			i++;
			j++;
		}
	}
}

void				parsing_tetris(t_env *env)
{	int i = 0;
	register_tetris(env);
	while (env->tetris && env->tetris[i])
	{
		ft_putstr(env->tetris[i]);
		i++;
		if (env->tetris[i])
			ft_putchar('\n');
	}
}
