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
	int				i;
	int				j;

	i = 0;
	j = 0;
	read(env->fd, env->file, MAX_CHARACTERS + 1);
	if (env->file[MAX_CHARACTERS] != '\0')
		ft_exit("error", INVALID_FILE);
	while (env->file && env->file[i])
	{
		if (env->file[i])
		{
			env->tetris[j] = ft_strndup(env->file + i, TETRI_SIZE);
			i += TETRI_SIZE;
			if (env->file[i] && env->file[i] != '\n')
				ft_exit("error", INVALID_FILE);
			i++;
			j++;
		}
	}
}

/*static int			check_links(char *tetri, int index)
{
	tetri += index;
	return (6);
}*/

static void			check_tetris(t_env *env)
{
	int				i;
	int				j;
	t_tetri			tetri;

	i = 0;
	while (env->tetris && env->tetris[i])
	{
		j = 0;
		tetri.str = env->tetris[i];
		tetri.nb_hashtags = 0;
		tetri.nb_links = 0;
		while (tetri.str[j])
		{
			if (tetri.str[j] == '#')
			{
				tetri.nb_hashtags++;
//				tetri.nb_links += check_links(env->tetris[i], j);
				tetri.nb_links = 6; //temporary
			}
			else if (tetri.str[j] == '\n')
			{
				if (j != 4 && j != 9 && j != 14 && j != 19)
					ft_exit("error", INVALID_FILE);
			}
			else if (tetri.str[j] != '.')
				ft_exit("error", INVALID_FILE);
			j++;
		}
		if (!(tetri.nb_hashtags == HASHTAG_PER_TETRI && (tetri.nb_links == 6 ||
						tetri.nb_links == 8)))
			ft_exit("error", INVALID_FILE);
		i++;
	}
}

void				parsing_tetris(t_env *env)
{	int i = 0;
	register_tetris(env);
	check_tetris(env);
	while (env->tetris && env->tetris[i])
	{
		ft_putstr(env->tetris[i]);
		i++;
		if (env->tetris[i])
			ft_putchar('\n');
	}
}
