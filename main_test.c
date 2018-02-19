#include "get_next_line.h"

int main(int argc, char **argv)
{
	char	*line;
	char	*line2;
	int		fd;
	int		fd2;
	int		gnl_ret;
	int		gnl_ret2;

	line = NULL;
	gnl_ret = 1;
	gnl_ret2 = 1;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (gnl_ret)
		{
			gnl_ret = get_next_line(fd, &line);
			ft_putstr("\ngnl renvoie: ");
			ft_putnbr(gnl_ret);
			ft_putstr("\nEt line vaut: ");
			ft_putstr(line);
			ft_putchar('\n');
			free(line);
		}
		gnl_ret = get_next_line(fd, &line);
		ft_putstr("\ngnl renvoie: ");
		ft_putnbr(gnl_ret);
		ft_putstr("\nEt line vaut: ");
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		while (gnl_ret || gnl_ret2)
		{
			gnl_ret = get_next_line(fd, &line);
			gnl_ret2 = get_next_line(fd2, &line2);
			ft_putstr("\nGNL :");
			ft_putstr(line);
			free(line);
			ft_putstr("\nGNL2 :");
			ft_putstr(line2);
			free(line2);
			ft_putstr("\n");
		}
	}
	return (0);
}
