#ifndef BSQ_BASE_H
# define BSQ_BASE_H
# include "read_file_element.h"
# include "memory.h"
# include "check_map_info.h"
# include "check_map_element.h"
# include "fill_square.h"

typedef struct s_map
{
	int		enter;
	int		line;
	int		size;
	char	empty;
	char	obstacle;
	char	full;
}	t_mp;

typedef struct s_idx
{
	int		i;
	int		j;
}	t_idx;

char	**move_argv(int	ac, char	*av[]);

int	get_info_sum(char	*filepath, t_mp	*mt, t_idx	*idx);

#endif
