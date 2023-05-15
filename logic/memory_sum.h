#ifndef MEMORY_SUM_H
# define MEMORY_SUM_H
# include <stdlib.h>

typedef struct s_map
{
	int		enter;
	int		line;
	int		size;
	char	empty;
	char	obstacle;
	char	full;
}	t_mp;

char	*init_temp_map(t_mp	*mt);

char	**init_map(t_mp	*mt);

int		*init_memo(t_mp	*mt);

int		free_ary(t_mp	mt, char	**map_ary, int	**memo_ary);

#endif
