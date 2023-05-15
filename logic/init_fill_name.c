#include "init_fill_name.h"

void	init_file_name(char	*file_name)
{
	int		i;

	i = 0;
	while (i < 1000)
	{
		file_name[i] = 0;
		i++;
	}
	return ;
}

int	*init_line_size(int	enter)
{
	int		*line_size;
	int		i;

	line_size = (int *)malloc(sizeof(int) * enter);
	i = 0;
	while (i < enter)
	{
		line_size[i] = 0;
		i++;
	}
	return (line_size);
}

char	**init_filepath(int	enter, int	*line_size)
{
	char	**filepath;
	int		i;

	filepath = (char **)malloc(sizeof(char *) * enter);
	i = 0;
	while (i < enter)
	{
		filepath[i] = (char *)malloc(sizeof(char) * line_size[i]);
		i++;
	}
	return (filepath);
}
