#include <fillit.h>

void				apply_type(t_env *env, char *str, t_place_type tetri)
{
	int				i;

	i = 0;
	while (*str != '#')
		str++;
	if (*str + 1 == '#' && *str + 5 == '#')
	{
		str++;
		if ()
	}
	else if (*str + 1 == '#')
	else if (*str + 2 == '#')
	else
		ft_exit("error", INVALID_FILE);
	while (i < TT_COUNT)
	{
		if (env->all_types[i].type == tetri.type)
			tetri.place_tetri = env->all_types[i].place_tetri;
		i++;
	}
}
