#include "get_map_info.h"

int	get_num(char	*str, int	n)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < n)
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num);
}

void	input_map_data(t_mp	*mt, char	*temp_map)
{
	int		i;
	int		cnt;

	cnt = 0;
	while (temp_map[cnt] != '\n')
		cnt++;
	i = 0;
	while (1)
	{
		if (i == 0)
			(*mt).enter = get_num(temp_map, cnt - 3);
		else if (i == cnt - 3)
			(*mt).empty = temp_map[cnt - 3];
		else if (i == cnt - 2)
			(*mt).obstacle = temp_map[cnt - 2];
		else if (i == cnt - 1)
			(*mt).full = temp_map[cnt - 1];
		else if (i == cnt)
			break ;
		i++;
	}
}

void	count_column_size(t_mp	*mt, char	*temp_map)
{
	int		i;

	i = 0;
	while (temp_map[i] != '\n')
		i++;
	(*mt).line = 0;
	while (temp_map[i + 1] != '\n')
	{
		(*mt).line++;
		i++;
	}
	(*mt).line--;
}

int	get_map_info(t_mp	*mt, char	*temp_map)
{
	input_map_data(mt, temp_map);
	count_column_size(mt, temp_map);
	return (0);
}
