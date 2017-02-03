/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:45:08 by sbrochar          #+#    #+#             */
/*   Updated: 2017/02/03 11:45:11 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_bool				check_laid_s(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 1) && (str + 4) && (str + 5) && *(str + 1) == '#'
		&& *(str + 4) == '#' && *(str + 5) == '#');
}

t_bool				check_up_s(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 5) && (str + 6) && (str + 11) && *(str + 5) == '#'
		&& *(str + 6) == '#' && *(str + 11) == '#');
}

t_bool				check_laid_z(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 1) && (str + 6) && (str + 7) && *(str + 1) == '#'
		&& *(str + 6) == '#' && *(str + 7) == '#');
}

t_bool				check_up_z(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 4) && (str + 5) && (str + 9) && *(str + 4) == '#'
		&& *(str + 5) == '#' && *(str + 9) == '#');
}
