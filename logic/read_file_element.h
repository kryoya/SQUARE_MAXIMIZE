#ifndef READ_FILE_ELEMENT_H
# define READ_FILE_ELEMENT_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_map
{
	int		enter;
	int		line;
	int		size;
	char	empty;
	char	obstacle;
	char	full;
}	t_mp;

int	get_map_size(char	*filepath, t_mp	*mt);

int	read_to_temp(char	*filepath, t_mp	mt, char	*temp_map);

void	set_index(int	*w, int	*h, char	*str);

int	read_to_map(char	*filepath, char	**map_ary);

#endif
