/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:48:43 by sbrochar          #+#    #+#             */
/*   Updated: 2017/01/16 17:41:29 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <libft.h>

# define MAX_TETRIMINOS 26
# define MAX_CHARACTERS 545
# define HASHTAG_PER_TETRI 4
# define TETRI_SIZE 20

# define E_SUCCESS 1
# define FAILED_TO_OPEN -1
# define INVALID_FILE -2
# define FAILED_TO_MALLOC -3

typedef enum		e_type_tetri
{
	TT_HORIZ_I,
	TT_CLASSIC_I,
	TT_CLASSIC_T,
	TT_REV_T,
	TT_LEFT_T,
	TT_RIGHT_T,
	TT_CLASSIC_J,
	TT_RIGHT_J,
	TT_REV_J,
	TT_LEFT_J,
	TT_CLASSIC_L,
	TT_REV_L,
	TT_RIGHT_L,
	TT_LEFT_L,
	TT_SQUARE,
	TT_LAID_S,
	TT_UP_S,
	TT_LAID_Z,
	TT_UP_Z,
	TT_COUNT
}					t_type_tetri;

typedef struct		s_apply_tetri
{
	t_type_tetri	type;
	void			(*place_tetri)(t_type_tetri);
}					t_apply_tetri;

typedef struct		s_tetri
{
	char			*str;
	int				nb_hashtags;
	int				nb_links;
	t_type_tetri	type;
}					t_tetri;

typedef struct		s_env
{
	int				fd;
	char			file[MAX_CHARACTERS + 1];
	t_tetri			tetris[MAX_TETRIMINOS + 1];
}					t_env;

void				parsing_tetris(t_env *env);

#endif
