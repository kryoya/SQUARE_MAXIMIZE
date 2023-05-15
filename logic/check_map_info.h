#ifndef CHECK_MAP_INFO_H
# define CHECK_MAP_INFO_H
# include <stdbool.h>

typedef struct s_map
{
	int		enter;
	int		line;
	int		size;
	char	empty;
	char	obstacle;
	char	full;
}	t_mp;

int	check_map_info(char	*temp_map);

int	check_line_column(t_mp	*mt, char	*temp_map);

#endif
