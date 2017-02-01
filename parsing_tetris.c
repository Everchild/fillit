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
			env->tetris[j].str = ft_strndup(env->file + i, TETRI_SIZE);
			i += TETRI_SIZE;
			if (env->file[i] && env->file[i] != '\n')
				ft_exit("error", INVALID_FILE);
			i++;
			j++;
		}
	}
}

static int			check_links(char *tetri, int index)
{
	int				ret;

	ret = 0;
	if (tetri[index - 5] && tetri[index - 5] == '#')
		ret++;
	if (tetri[index - 1] && tetri[index - 1] == '#')
		ret++;
	if (tetri[index + 1] && tetri[index + 1] == '#')
		ret++;
	if (tetri[index + 5] && tetri[index + 5] == '#')
		ret++;
	return (ret);
}

static void			check_tetri(t_env *env, t_tetri tetri)
{
	int				i;

	i = 0;
	while (tetri.str[i])
	{
		if (tetri.str[i] == '#')
		{
			tetri.nb_hashtags++;
			tetri.nb_links += check_links(tetri.str, i);
		}
		else if (tetri.str[i] == '\n')
		{
			if (i != 4 && i != 9 && i != 14 && i != 19)
				ft_exit("error", INVALID_FILE);
		}
		else if (tetri.str[i] != '.')
			ft_exit("error", INVALID_FILE);
		i++;
	}
	if (!(tetri.nb_hashtags == HASHTAG_PER_TETRI && (tetri.nb_links == 6 ||
		tetri.nb_links == 8)))
		ft_exit("error", INVALID_FILE);
	apply_type(env, tetri.str, tetri.type);
}

void				parsing_tetris(t_env *env)
{
	int				i;
	char			letter;

	i = 0;
	letter = 'A';
	register_tetris(env);
	while (env->tetris[i].str)
	{
		check_tetri(env, env->tetris[i]);
		env->tetris[i].letter = letter;
		env->nb_tetris++;
		letter++;
		i++;
	}
	i = 0;
	while (env->tetris[i].str)
	{
		ft_putstr(env->tetris[i].str);
		i++;
		if (env->tetris[i].str)
			ft_putchar('\n');
	}
}
