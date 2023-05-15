#include "memory_sum.h"

char	*init_temp_map(t_mp	*mt)
{
	char	*temp_map;

	temp_map = (char *)malloc(sizeof(char) * (*mt).size);
	return (temp_map);
}

char	**init_map(t_mp	*mt)
{
	char	**map_ary;
	int		i;
	int		j;

	map_ary = (char **)malloc(sizeof(char *) * (*mt).enter);
	i = 0;
	while (i < (*mt).enter)
	{
		map_ary[i] = (char *)malloc(sizeof(char) * (*mt).line);
		i++;
	}
	i = 0;
	j = 0;
	while (i < (*mt).enter)
	{
		j = 0;
		while (j < (*mt).line)
		{
			map_ary[i][j] = '0';
			j++;
		}
		i++;
	}
	return (map_ary);
}

int	*init_memo(t_mp	*mt)
{
	int		**memo_ary;
	int		i;
	int		j;

	memo_ary = (int **)malloc(sizeof(int *) * (*mt).enter);
	i = 0;
	while (i < (*mt).enter)
	{
		memo_ary[i] = (int *)malloc(sizeof(int) * (*mt).line);
		i++;
	}
	i = 0;
	j = 0;
	while (i < (*mt).enter)
	{
		j = 0;
		while (j < (*mt).line)
		{
			memo_ary[i][j] = 0;
			j++;
		}
		i++;
	}
	return (memo_ary);
}

int	free_ary(t_mp	mt, char	**map_ary, int	**memo_ary)
{
	int		i;

	i = 0;
	while (i < mt.enter)
	{
		free(map_ary[i]);
		free(memo_ary[i]);
		i++;
	}
	free(map_ary);
	free(memo_ary);
	return (1);
}
