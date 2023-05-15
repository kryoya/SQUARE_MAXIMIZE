#ifndef GET_MAP_INFO_H
# define GET_MAP_INFO_H

typedef struct s_map
{
	int		enter;
	int		line;
	int		size;
	char	empty;
	char	obstacle;
	char	full;
}	t_mp;

int	get_num(char	*str, int	n);

void	input_map_data(t_mp	*mt, char	*temp_map);

void	count_column_size(t_mp	*mt, char	*temp_map);

int	get_map_info(t_mp	*mt, char	*temp_map);

#endif
