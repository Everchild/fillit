/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetris_sz.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:52:06 by sbrochar          #+#    #+#             */
/*   Updated: 2017/02/03 11:52:07 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int					place_laid_s(char *map, int index, char c, int side)
{
	if (map[index] && map[index + 1] && map[index + side]
		&& map[index + side + 1] && map[index] == '.' && map[index + 1] == '.'
		&& map[index + side] == '.' && map[index + side + 1] == '.')
	{
		map[index] = c;
		map[index + 1] = c;
		map[index + side] = c;
		map[index + side + 1] = c;
		return (TETRI_PLACED);
	}
	return (INVALID_PLACEMENT);
}

int					place_up_s(char *map, int index, char c, int side)
{
	if (map[index] && map[index + side + 1] && map[index + side + 2]
		&& map[index + side * 2 + 3] && map[index] == '.'
		&& map[index + side + 1] == '.' && map[index + side + 2] == '.'
		&& map[index + side * 2 + 3] == '.')
	{
		map[index] = c;
		map[index + side + 1] = c;
		map[index + side + 2] = c;
		map[index + side * 2 + 3] = c;
		return (TETRI_PLACED);
	}
	return (INVALID_PLACEMENT);
}

int					place_laid_z(char *map, int index, char c, int side)
{
	if (map[index] && map[index + 1] && map[index + side + 2]
		&& map[index + side + 3] && map[index] == '.' && map[index + 1] == '.'
		&& map[index + side + 2] == '.' && map[index + side + 3] == '.')
	{
		map[index] = c;
		map[index + 1] = c;
		map[index + side + 2] = c;
		map[index + side + 3] = c;
		return (TETRI_PLACED);
	}
	return (INVALID_PLACEMENT);
}

int					place_up_z(char *map, int index, char c, int side)
{
	if (map[index] && map[index + side] && map[index + side + 1]
		&& map[index + side * 2 + 1] && map[index] == '.'
		&& map[index + side] == '.' && map[index + side + 1] == '.'
		&& map[index + side * 2 + 1] == '.')
	{
		map[index] = c;
		map[index + side] = c;
		map[index + side + 1] = c;
		map[index + side * 2 + 1] = c;
		return (TETRI_PLACED);
	}
	return (INVALID_PLACEMENT);
}
