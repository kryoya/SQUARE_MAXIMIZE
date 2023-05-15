#include "read_file_element.h"

int	get_map_size(char	*filepath, t_mp	*mt)
{
	char	tum_buf[256];
	int		fd;
	int		byte_num;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (-1);
	(*mt).size = 0;
	byte_num = 1;
	while (byte_num != 0)
	{
		byte_num = read(fd, &tum_buf[0], 256);
		(*mt).size += byte_num;
	}
	if (byte_num == -1)
		return (-1);
	close(fd);
	return (0);
}

int	read_to_temp(char	*filepath, t_mp	mt, char	*temp_map)
{
	int		fd;
	int		byte_num;

	fd = open(filepath, O_RDONLY);
	byte_num = 1;
	byte_num = read(fd, &temp_map[0], mt.size);
	if (byte_num == -1)
		return (-1);
	close(fd);
	return (0);
}

void	set_index(int	*w, int	*h, char	*str)
{
	if (*str == '\n')
	{
		*w = 0;
		*h += 1;
	}
	return ;
}

int	read_to_map(char	*filepath, char	**map_ary)
{
	char	*tum_buf;
	int		fd;
	int		byte_num;
	int		w;
	int		h;

	tum_buf = (char *)malloc(sizeof(char) * 1);
	fd = open(filepath, O_RDONLY);
	byte_num = 1;
	w = 0;
	h = 0;
	while (byte_num != 0)
	{
		set_index(&w, &h, tum_buf);
		byte_num = read(fd, tum_buf, 1);
		if (*tum_buf != '\n' && h > 0)
			map_ary[h - 1][w] = *tum_buf;
		w++;
	}
	if (byte_num == -1)
		return (-1);
	close(fd);
	free(tum_buf);
	return (0);
}
