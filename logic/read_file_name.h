#ifndef READ_FILE_NAME_H
# define READ_FILE_NAME_H
#include <unistd.h>
#include "init_fill_name.h"

void	divide_space(char	*file_name, char	**filepath);

int	count_space(char	*file_name);

void	count_line_size(char	*file_name, int	*line_size);

char	**input_file_name(int	*ac);

#endif
