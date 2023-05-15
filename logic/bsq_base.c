#include "bsq_base.h"

char	**move_argv(int	ac, char	*av[])
{
	int		i;
	char	**filepath;

	filepath = av;
	i = 1;
	while (i < ac)
	{
		filepath[i - 1] = av[i];
		i++;
	}
	return (filepath);
}

int	get_info_sum(char	*filepath, t_mp	*mt, t_idx	*idx)
{
	char	*temp_map;
	char	**map_ary;
	int		**memo_ary;

	while ((*idx).j == 0)
	{
		if (get_map_size(filepath, mt) == -1)
			return (1);
		temp_map = init_temp_map(mt);
		read_to_temp(filepath, *mt, temp_map);
		if (check_map_info(temp_map))
			break ;
		get_map_info(mt, temp_map);
		if (check_line_column(mt, temp_map))
			break ;
		map_ary = init_map(mt);
		memo_ary = init_memo(mt);
		read_to_map(filepath, map_ary);
		if (!(check_map_element(mt, map_ary)))
			(*idx).j = fill_square(mt, map_ary, memo_ary);
		(*idx).j += free_ary(*mt, map_ary, memo_ary);
	}
	free(temp_map);
	return ((*idx).j);
}
