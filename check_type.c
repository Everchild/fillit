#include <fillit.h>

static t_place_type	g_tetris[TT_COUNT] = { { TT_HORIZ_I, place_horiz_i },
	{ TT_CLASSIC_I, place_classic_i },
	{ TT_CLASSIC_T, place_classic_t },
	{ TT_REV_T, place_rev_t },
	{ TT_LEFT_T, place_left_t },
	{ TT_RIGHT_T, place_right_t },
	{ TT_CLASSIC_J, place_classic_j },
	{ TT_RIGHT_J, place_right_j },
	{ TT_REV_J, place_rev_j },
	{ TT_LEFT_J, place_left_j },
	{ TT_CLASSIC_L, place_classic_l },
	{ TT_REV_L, place_rev_l },
	{ TT_RIGHT_L, place_right_l },
	{ TT_LEFT_L, place_left_l },
	{ TT_SQUARE, place_square },
	{ TT_LAID_S, place_laid_s },
	{ TT_UP_S, place_up_s },
	{ TT_LAID_Z, place_laid_z },
	{ TT_UP_Z, place_up_z } };

void				apply_type(char *str, t_place_type tetri)
{
	int				i;

	i = 0;
	while (*str)
		str++;
	tetri.type = TT_COUNT;
	while (i < TT_COUNT)
	{
		if (g_tetris[i].type == tetri.type)
			tetri.place_tetri = g_tetris[i].place_tetri;
		i++;
	}
}
