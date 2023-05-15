#include "check_map_element.h"

int	check_empty(t_mp	*mt, char	**map_ary)
{
	int		w;
	int		h;

	h = 0;
	while (h < (*mt).enter)
	{
		w = 0;
		while (w < (*mt).line)
		{
			if (map_ary[h][w] == (*mt).empty)
				return (0);
			w++;
		}
		h++;
	}
	return (1);
}

int	check_char(t_mp	*mt, char	**map_ary)
{
	int		w;
	int		h;

	h = 0;
	while (h < (*mt).enter)
	{
		w = 0;
		while (w < (*mt).line)
		{
			if (map_ary[h][w] != (*mt).empty)
				if (map_ary[h][w] != (*mt).obstacle)
					return (1);
			if (map_ary[h][w] == (*mt).full)
				return (1);
			w++;
		}
		h++;
	}
	return (0);
}

int	same_check(t_mp	*mt)
{
	if ((*mt).empty == (*mt).obstacle || (*mt).empty == (*mt).full)
		return (1);
	if ((*mt).obstacle == (*mt).full)
		return (1);
	return (0);
}

int	check_map_element(t_mp	*mt, char	**map_ary)//5
{
	if (same_check(mt))
		return (1);
	if (check_char(mt, map_ary))
		return (1);
	if (check_empty(mt, map_ary))
		return (1);
	return (0);
}
