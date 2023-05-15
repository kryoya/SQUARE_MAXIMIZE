#ifndef CHECK_MAP_ELEMENT_H
# define CHECK_MAP_ELEMENT_H

typedef struct s_map
{
	int		enter;
	int		line;
	int		size;
	char	empty;
	char	obstacle;
	char	full;
}	t_mp;

int	check_empty(t_mp	*mt, char	**map_ary);

int	check_char(t_mp	*mt, char	**map_ary);

int	same_check(t_mp	*mt);

int	check_map_element(t_mp	*mt, char	**map_ary);

#endif
