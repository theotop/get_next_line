#include "get_next_line.h"

int main(int argc, char **argv)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	if (argc == 2)
	{
		while (get_next_line(open(argv[1], O_RDONLY), &tab))
		{
			ft_putstr(tab);
			ft_putchar('\n');
		}
	}
	return (0);
}
