/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:45:15 by sbrochar          #+#    #+#             */
/*   Updated: 2017/02/03 11:45:17 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_bool				check_square(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 1) && (str + 5) && (str + 6) && *(str + 1) == '#'
		&& *(str + 5) == '#' && *(str + 6) == '#');
}

t_bool				check_classic_t(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 1) && (str + 2) && (str + 6) && *(str + 1) == '#'
		&& *(str + 2) == '#' && *(str + 6) == '#');
}

t_bool				check_rev_t(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 4) && (str + 5) && (str + 6) && *(str + 4) == '#'
		&& *(str + 5) == '#' && *(str + 6) == '#');
}

t_bool				check_left_t(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 4) && (str + 5) && (str + 10) && *(str + 4) == '#'
		&& *(str + 5) == '#' && *(str + 10) == '#');
}

t_bool				check_right_t(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 5) && (str + 6) && (str + 10) && *(str + 5) == '#'
		&& *(str + 6) == '#' && *(str + 10) == '#');
}
