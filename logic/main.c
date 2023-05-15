#include "bsq_base.h"
#include "ft_standard.h"
#include "read_file_name.h"

typedef struct s_map
{
	int		enter;
	int		line;
	int		size;
	char	empty;
	char	obstacle;
	char	full;
}	t_mp;

typedef struct s_max
{
	int		area;
	int		w;
	int		h;
}	t_mx;

typedef struct s_idx
{
	int		i;
	int		j;
}	t_idx;

int	main(int	ac, char	*av[])
{
	char	**filepath;
	t_mp	mt;
	t_idx	idx;

	if (ac == 1)
		filepath = input_file_name(&ac);
	else
		filepath = move_argv(ac, av);
	idx.i = 0;
	while (idx.i < ac - 1)
	{
		idx.j = 0;
		idx.j = get_info_sum(filepath[idx.i], &mt, &idx);
		if (idx.j >= 0)
			print_str("map error\n");
		else if (idx.i != ac - 2)
			ft_putchar('\n');
		idx.i++;
	}
	return (0);
}
