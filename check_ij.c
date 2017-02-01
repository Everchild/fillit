#include <fillit.h>

t_bool				check_horiz_i(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 1) && (str + 2) && (str + 3) && *(str + 1) == '#'
		&& *(str + 2) == '#' && *(str + 3) == '#');
}

t_bool				check_classic_j(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 5) && (str + 9) && (str + 10) && *(str + 5) == '#'
		&& *(str + 9) == '#' && *(str + 10) == '#');
}

t_bool				check_right_j(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 5) && (str + 6) && (str + 7) && *(str + 5) == '#'
		&& *(str + 6) == '#' && *(str + 7) == '#');
}

t_bool				check_rev_j(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 1) && (str + 5) && (str + 10) && *(str + 1) == '#'
		&& *(str + 5) == '#' && *(str + 10) == '#');
}

t_bool				check_left_j(char *str)
{
	while (*str != '#')
		str++;
	return ((str + 1) && (str + 2) && (str + 7) && *(str + 1) == '#'
		&& *(str + 2) == '#' && *(str + 3) == '#');
}
