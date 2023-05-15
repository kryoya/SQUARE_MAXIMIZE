#include "read_file_name.h"

void	divide_space(char	*file_name, char	**filepath)
{
	int		i;
	int		w;
	int		h;

	i = 0;
	w = 0;
	h = 0;
	while (file_name[i] != '\n')
	{
		if (file_name[i] == ' ')
		{
			w = 0;
			h++;
		}
		else
		{
			filepath[h][w] = file_name[i];
			w++;
		}
		i++;
	}
	return ;
}

int	count_space(char	*file_name)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (file_name[i] != '\0')
	{
		if (file_name[i] == ' ')
			cnt++;
		i++;
	}
	return (cnt += 1);
}

void	count_line_size(char	*file_name, int	*line_size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file_name[i] != '\0')
	{
		if (file_name[i] == '\n')
			j++;
		line_size[j]++;
		i++;
	}
	return ;
}

char	**input_file_name(int	*ac)
{
	char	**filepath;
	char	file_name[1000];
	int		*line_size;

	init_file_name(file_name);
	read(0, file_name, sizeof(file_name));
	*ac = count_space(file_name);
	line_size = init_line_size(*ac);
	count_line_size(file_name, line_size);
	filepath = init_filepath(*ac, line_size);
	divide_space(file_name, filepath);
	*ac += 1;
	return (filepath);
}
