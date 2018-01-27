#include "get_next_line.h"

int main(int argc, char **argv)
{
	char	*line;
	int		fd;

	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) >= 0)
		{
			ft_putstr("\nGNL RETOURNE :");
			ft_putstr(line);
			free(line);
			ft_putstr("\n\n\n");
		}
	}
	return (0);
}
