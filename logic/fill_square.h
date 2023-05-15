#ifndef FILL_SQUARE_H
# define FILL_SQUARE_H
# include "ft_standard.h"

typedef struct s_max
{
	int		area;
	int		w;
	int		h;
}	t_mx;

void	search_biggest(int	**memo_ary, t_mp	*mt, t_mx	*max);

int	check_memo(int	**memo_ary, int	w, int	h);

int	check_obstacle(t_mp *mt, int w, int h, char **map_ary);

void	fill_memo(t_mp	*mt, char	**map_ary, int	**memo_ary);

int	fill_square(t_mp	*mt, char	**map_ary, int	**memo_ary);
#endif
