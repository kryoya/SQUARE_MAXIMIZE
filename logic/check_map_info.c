#include "check_map_info.h"

int	check_map_info(char	*temp_map)
{
	int		i;
	int		cnt;
	bool	num_ok;

	i = 0;
	cnt = 0;
	num_ok = true;
	while (temp_map[i] != '\n')
	{
		if (!(temp_map[0] >= '0' && temp_map[0] <= '9'))
			return (1);
		if (!(temp_map[i] >= ' ' && temp_map[i] <= '~'))
			return (1);
		if (temp_map[i] >= '0' && temp_map[i] <= '9' && num_ok)
			cnt++;
		else
			num_ok = false;
		i++;
	}
	if ((i - cnt) > 3)
		return (1);
	return (0);
}

int	check_line_column(t_mp	*mt, char	*temp_map)
{
	int		cnt_enter;
	int		cnt_line;
	int		i;

	cnt_enter = 0;
	cnt_line = 0;
	i = 0;
	while (temp_map[i] != '\n')
		i++;
	i++;
	while (i < (*mt).size)
	{
		if (temp_map[i] == '\n')
		{
			cnt_enter++;
			cnt_line = 0;
		}
		if (temp_map[i] == '\\' && cnt_line != (*mt).line)
			return (1);
		cnt_line++;
		i++;
	}
	if (cnt_enter != (*mt).enter)
		return (1);
	return (0);
}
