#include "fill_square.h"

void	search_biggest(int	**memo_ary, t_mp	*mt, t_mx	*max)
{
	int		w;
	int		h;

	h = 0;
	(*max).area = 0;
	while (h < (*mt).enter)
	{
		w = 0;
		while (w < (*mt).line)
		{
			if ((*max).area < memo_ary[h][w])
			{
				(*max).area = memo_ary[h][w];
				(*max).w = w;
				(*max).h = h;
			}
			w++;
		}
		h++;
	}
	return ;
}

int	check_memo(int	**memo_ary, int	w, int	h)
{
	int		tum;

	tum = memo_ary[h][w - 1];
	if (tum > memo_ary[h - 1][w])
		tum = memo_ary[h - 1][w];
	if (tum > memo_ary[h - 1][w - 1])
		tum = memo_ary[h - 1][w - 1];
	return (tum);
}

int	check_obstacle(t_mp *mt, int w, int h, char **map_ary)
{
	if (w == 0 || h == 0)
		return (1);
	if (map_ary[h][w - 1] == (*mt).obstacle)
		return (1);
	if (map_ary[h - 1][w] == (*mt).obstacle)
		return (1);
	if (map_ary[h - 1][w - 1] == (*mt).obstacle)
		return (1);
	return (0);
}

void	fill_memo(t_mp	*mt, char	**map_ary, int	**memo_ary)
{
	int		w;
	int		h;

	h = 0;
	while (h < (*mt).enter)
	{
		w = 0;
		while (w < (*mt).line)
		{
			if (check_obstacle(mt, w, h, map_ary))
				memo_ary[h][w] = 1;
			else if (map_ary[h][w] == (*mt).obstacle)
				memo_ary[h][w] = 0;
			else
				memo_ary[h][w] = check_memo(memo_ary, w, h) + 1;
			w++;
		}
		h++;
	}
	return ;
}

int	fill_square(t_mp	*mt, char	**map_ary, int	**memo_ary)
{
	int		w;
	int		h;
	t_mx	max;

	fill_memo(mt, map_ary, memo_ary);
	search_biggest(memo_ary, mt, &max);
	h = max.h - max.area + 1;
	while (h <= max.h)
	{
		w = max.w - max.area + 1;
		while (w <= max.w)
		{
			map_ary[h][w] = (*mt).full;
			w++;
		}
		h++;
	}
	printf_map(mt, map_ary);
	return (-2);
}
