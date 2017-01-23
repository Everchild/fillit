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

typedef enum		e_type
{
	ALL_TYPES
}					t_type;

typedef struct		s_tetri
{
	char			*str;
	int				nb_hashtags;
	int				nb_links;
	t_type			type;
}					t_tetri;

typedef struct		s_env
{
	int				fd;
	char			file[MAX_CHARACTERS + 1];
	char			*tetris[MAX_TETRIMINOS + 1];
}					t_env;

void				parsing_tetris(t_env *env);

#endif
