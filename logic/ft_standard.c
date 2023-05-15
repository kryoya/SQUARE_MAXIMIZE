#include "ft_standard.h"

int	ft_strlen(char	*str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	print_str(char	*str)
{
	write(1, str, sizeof(char) * ft_strlen(str));
	return ;
}

void	ft_putchar(char	c)
{
	write(1, &c, 1);
	return ;
}

void	printf_map(t_mp	*mt, char	**map_ary)
{
	int		w;
	int		h;

	h = 0;
	while (h < (*mt).enter)
	{
		w = 0;
		while (w < (*mt).line)
		{
			ft_putchar(map_ary[h][w]);
			w++;
		}
		ft_putchar('\n');
		h++;
	}
	return ;
}
