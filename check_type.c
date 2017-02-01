#include <fillit.h>

void				apply_type(t_env *env, char *str, t_place_type tetri)
{
	int				i;

	i = 0;
	while (*str)
		str++;
	tetri.type = TT_COUNT;
	while (i < TT_COUNT)
	{
		if (env->all_types[i].type == tetri.type)
			tetri.place_tetri = env->all_types[i].place_tetri;
		i++;
	}
}
