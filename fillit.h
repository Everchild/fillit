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

# define TETRI_PLACED 3
# define INVALID_PLACEMENT 2

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

typedef t_bool		(*t_check_type_fct)(char *);
typedef int			(*t_place_type_fct)(char *, int, char c, int side);

typedef struct		s_place_type
{
	t_type_tetri	type;
	t_bool			(*check_type)(char *);
	int				(*place_tetri)(char *, int, char c, int side);
}					t_place_type;

typedef struct		s_tetri
{
	char			*str;
	int				nb_hashtags;
	int				nb_links;
	t_place_type	type;
	char			letter;
}					t_tetri;

typedef struct		s_env
{
	int				fd;
	char			file[MAX_CHARACTERS + 1];
	t_tetri			tetris[MAX_TETRIMINOS + 1];
	int				nb_tetris;
	char			*map;
	int				side;
	t_place_type	all_types[TT_COUNT];
}					t_env;

void				parsing_tetris(t_env *env);
void				fillit(t_env *env);
t_bool				check_horiz_i(char *tetri);
t_bool				check_classic_i(char *tetri);
t_bool				check_classic_t(char *tetri);
t_bool				check_rev_t(char *tetri);
t_bool				check_left_t(char *tetri);
t_bool				check_right_t(char *tetri);
t_bool				check_classic_j(char *tetri);
t_bool				check_right_j(char *tetri);
t_bool				check_rev_j(char *tetri);
t_bool				check_left_j(char *tetri);
t_bool				check_classic_l(char *tetri);
t_bool				check_rev_l(char *tetri);
t_bool				check_right_l(char *tetri);
t_bool				check_left_l(char *tetri);
t_bool				check_square(char *tetri);
t_bool				check_laid_s(char *tetri);
t_bool				check_up_s(char *tetri);
t_bool				check_laid_z(char *tetri);
t_bool				check_up_z(char *tetri);
int					place_horiz_i(char *map, int index, char c, int side);
int					place_classic_i(char *map, int index, char c, int side);
int					place_classic_t(char *map, int index, char c, int side);
int					place_rev_t(char *map, int index, char c, int side);
int					place_left_t(char *map, int index, char c, int side);
int					place_right_t(char *map, int index, char c, int side);
int					place_classic_j(char *map, int index, char c, int side);
int					place_right_j(char *map, int index, char c, int side);
int					place_rev_j(char *map, int index, char c, int side);
int					place_left_j(char *map, int index, char c, int side);
int					place_classic_l(char *map, int index, char c, int side);
int					place_rev_l(char *map, int index, char c, int side);
int					place_right_l(char *map, int index, char c, int side);
int					place_left_l(char *map, int index, char c, int side);
int					place_square(char *map, int index, char c, int side);
int					place_laid_s(char *map, int index, char c, int side);
int					place_up_s(char *map, int index, char c, int side);
int					place_laid_z(char *map, int index, char c, int side);
int					place_up_z(char *map, int index, char c, int side);

#endif
