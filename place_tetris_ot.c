#include <fillit.h>

int					place_square(char *map, int index, char c, int side)
{
	while (map[index] && map[index + 1] && map[index + side + 1]
		&& map[index + side + 2])
	{
		if (map[index] == '.' && map[index + 1] == '.'
			&& map[index + side + 1] == '.' && map[index + side + 2] == '.')
		{
			map[index] = c;
			map[index + 1] = c;
			map[index + side + 1] = c;
			map[index + side + 2] = c;
			return (TETRI_PLACED);
		}
		else
			index++;
	}
	return (INVALID_PLACEMENT);
}

int					place_classic_t(char *map, int index, char c, int side)
{
	while (map[index] && map[index + 1] && map[index + 2]
		&& map[index + side + 2])
	{
		if (map[index] == '.' && map[index + 1] == '.' && map[index + 2] == '.'
			&& map[index + side + 2] == '.')
		{
			map[index] = c;
			map[index + 1] = c;
			map[index + 2] = c;
			map[index + side + 2] = c;
			return (TETRI_PLACED);
		}
		else
			index++;
	}
	return (INVALID_PLACEMENT);
}

int					place_rev_t(char *map, int index, char c, int side)
{
	while (map[index] && map[index + side] && map[index + side + 1]
		&& map[index + side + 2])
	{
		if (map[index] == '.' && map[index + side] == '.'
			&& map[index + side + 1] == '.' && map[index + side + 2] == '.')
		{
			map[index] = c;
			map[index + side] = c;
			map[index + side + 1] = c;
			map[index + side + 2] = c;
			return (TETRI_PLACED);
		}
		else
			index++;
	}
	return (INVALID_PLACEMENT);
}

int					place_left_t(char *map, int index, char c, int side)
{
	while (map[index] && map[index + side] && map[index + side + 1]
		&& map[index + side * 2 + 2])
	{
		if (map[index] == '.' && map[index + side] == '.'
			&& map[index + side + 1] == '.' && map[index + side * 2 + 2] == '.')
		{
			map[index] = c;
			map[index + side] = c;
			map[index + side + 1] = c;
			map[index + side * 2 + 2] = c;
			return (TETRI_PLACED);
		}
		else
			index++;
	}
	return (INVALID_PLACEMENT);
}

int					place_right_t(char *map, int index, char c, int side)
{
	while (map[index] && map[index + side + 1] && map[index + side + 2]
		&& map[index + side * 2 + 2])
	{
		if (map[index] == '.' && map[index + side + 1] == '.'
			&& map[index + side + 2] == '.' && map[index + side * 2 + 2] == '.')
		{
			map[index] = c;
			map[index + side + 1] = c;
			map[index + side + 2] = c;
			map[index + side * 2 + 2] = c;
			return (TETRI_PLACED);
		}
		else
			index++;
	}
	return (INVALID_PLACEMENT);
}
