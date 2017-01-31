#include <fillit.h>

int					place_horiz_i(char *map, int index, char c, int side)
{
	while (map[index] && map[index + 1] && map[index + 2] && map[index + 3])
	{
		if (map[index] == '.' && map[index + 1] == '.' && map[index + 2] == '.'
			&& map[index + side - side + 3] == '.')
		{
			map[index] = c;
			map[index + 1] = c;
			map[index + 2] = c;
			map[index + 3] = c;
			return (TETRI_PLACED);
		}
		else
			index++;
	}
	return (INVALID_PLACEMENT);
}

int					place_classic_j(char *map, int index, char c, int side)
{
	while (map[index] && map[index + side + 1] && map[index + side * 2 + 1] &&
		map[index + side * 2 + 2])
	{
		if (map[index] == '.' && map[index + side + 1] == '.'
			&& map[index + side * 2 + 1] == '.'
			&& map[index + side * 2 + 2] == '.')
		{
			map[index] = c;
			map[index + side + 1] = c;
			map[index + side * 2 + 1] = c;
			map[index + side * 2 + 2] = c;
			return (TETRI_PLACED);
		}
		else
			index++;
	}
	return (INVALID_PLACEMENT);
}

int					place_right_j(char *map, int index, char c, int side)
{
	while (map[index] && map[index + side + 1] && map[index + side + 2]
		&& map[index + side + 3])
	{
		if (map[index] == '.' && map[index + side + 1] == '.'
			&& map[index + side + 2] == '.' && map[index + side + 3] == '.')
		{
			map[index] = c;
			map[index + side + 1] = c;
			map[index + side + 2] = c;
			map[index + side + 3] = c;
			return (TETRI_PLACED);
		}
		else
			index++;
	}
	return (INVALID_PLACEMENT);
}

int					place_rev_j(char *map, int index, char c, int side)
{
	while (map[index] && map[index + 1] && map[index + side + 1]
		&& map[index + side * 2 + 2])
	{
		if (map[index] == '.' && map[index + 1] == '.'
			&& map[index + side + 1] == '.' && map[index + side * 2 + 2] == '.')
		{
			map[index] = c;
			map[index + 1] = c;
			map[index + side + 1] = c;
			map[index + side * 2 + 2] = c;
			return (TETRI_PLACED);
		}
		else
			index++;
	}
	return (INVALID_PLACEMENT);
}

int					place_left_j(char *map, int index, char c, int side)
{
	while (map[index] && map[index + 1] && map[index + 2]
		&& map[index + side + 3])
	{
		if (map[index] == '.' && map[index + 1] == '.' && map[index + 2] == '.'
			&& map[index + side + 3] == '.')
		{
			map[index] = c;
			map[index + 1] = c;
			map[index + 2] = c;
			map[index + side + 3] = c;
			return (TETRI_PLACED);
		}
		else
			index++;
	}
	return (INVALID_PLACEMENT);
}
