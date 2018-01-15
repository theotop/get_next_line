#include "get_next_line.h"

int main(int argc, char **argv)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	if (argc == 2)
	{
		while(tab[i])
		{
			get_next_line(open(argv[1], O_RDONLY), &tab[i])
			ft_putstr_nl(*tab);
			i++;
		}
	}
	return (0);
}
