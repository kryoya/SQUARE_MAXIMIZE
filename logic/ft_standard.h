#ifndef FT_STANDARD_H
# define FT_STANDARD_H
#include <unistd.h>

typedef struct s_map
{
	int		enter;
	int		line;
	int		size;
	char	empty;
	char	obstacle;
	char	full;
}	t_mp;

int	ft_strlen(char	*str);

void	print_str(char	*str);

void	ft_putchar(char	c);

void	printf_map(t_mp	*mt, char	**map_ary);

#endif
