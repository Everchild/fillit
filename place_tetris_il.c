/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetris_il.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:52:28 by sbrochar          #+#    #+#             */
/*   Updated: 2017/02/03 11:52:29 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int					place_classic_i(char *map, int index, char c, int side)
{
	if (map[index] && map[index + side + 1] && map[index + side * 2 + 2]
		&& map[index + side * 3 + 3] && map[index] == '.'
		&& map[index + side + 1] == '.' && map[index + side * 2 + 2] == '.'
		&& map[index + side * 3 + 3] == '.')
	{
		map[index] = c;
		map[index + side + 1] = c;
		map[index + side * 2 + 2] = c;
		map[index + side * 3 + 3] = c;
		return (TETRI_PLACED);
	}
	return (INVALID_PLACEMENT);
}

int					place_classic_l(char *map, int index, char c, int side)
{
	if (map[index] && map[index + side + 1] && map[index + side * 2 + 2]
		&& map[index + side * 2 + 3] && map[index] == '.'
		&& map[index + side + 1] == '.' && map[index + side * 2 + 2] == '.'
		&& map[index + side * 2 + 3] == '.')
	{
		map[index] = c;
		map[index + side + 1] = c;
		map[index + side * 2 + 2] = c;
		map[index + side * 2 + 3] = c;
		return (TETRI_PLACED);
	}
	return (INVALID_PLACEMENT);
}

int					place_rev_l(char *map, int index, char c, int side)
{
	if (map[index] && map[index + 1] && map[index + side + 2]
		&& map[index + side * 2 + 3] && map[index] == '.'
		&& map[index + 1] == '.' && map[index + side + 2] == '.'
		&& map[index + side * 2 + 3] == '.')
	{
		map[index] = c;
		map[index + 1] = c;
		map[index + side + 2] = c;
		map[index + side * 2 + 3] = c;
		return (TETRI_PLACED);
	}
	return (INVALID_PLACEMENT);
}

int					place_right_l(char *map, int index, char c, int side)
{
	if (map[index] && map[index + 1] && map[index + 2] && map[index + side + 1]
		&& map[index] == '.' && map[index + 1] == '.' && map[index + 2] == '.'
		&& map[index + side + 1] == '.')
	{
		map[index] = c;
		map[index + 1] = c;
		map[index + 2] = c;
		map[index + side + 1] = c;
		return (TETRI_PLACED);
	}
	return (INVALID_PLACEMENT);
}

int					place_left_l(char *map, int index, char c, int side)
{
	if (map[index] && map[index + side - 1] && map[index + side]
		&& map[index + side + 1] && map[index] == '.'
		&& map[index + side - 1] == '.' && map[index + side] == '.'
		&& map[index + side + 1] == '.')
	{
		map[index] = c;
		map[index + side - 1] = c;
		map[index + side] = c;
		map[index + side + 1] = c;
		return (TETRI_PLACED);
	}
	return (INVALID_PLACEMENT);
}
