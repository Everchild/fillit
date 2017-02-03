/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_il.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:44:59 by sbrochar          #+#    #+#             */
/*   Updated: 2017/02/03 11:45:01 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_bool				check_classic_i(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 5) && (str + 10) && (str + 15) && *(str + 5) == '#'
		&& *(str + 10) == '#' && *(str + 15) == '#');
}

t_bool				check_classic_l(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 5) && (str + 10) && (str + 11) && *(str + 5) == '#'
		&& *(str + 10) == '#' && *(str + 11) == '#');
}

t_bool				check_rev_l(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 1) && (str + 6) && (str + 11) && *(str + 1) == '#'
		&& *(str + 6) == '#' && *(str + 11) == '#');
}

t_bool				check_right_l(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 1) && (str + 2) && (str + 5) && *(str + 1) == '#'
		&& *(str + 2) == '#' && *(str + 5) == '#');
}

t_bool				check_left_l(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 3) && (str + 4) && (str + 5) && *(str + 3) == '#'
		&& *(str + 4) == '#' && *(str + 5) == '#');
}
