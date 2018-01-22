#include "get_next_line.h"

size_t		size_to_write(t_gnl_lst *file, int read_value)
{
	size_t	nb_of_chars;

	nb_of_chars = 0;
	while (!ft_issep(file->buf[nb_of_chars + file->bytes_readed], "\n\0")\
		|| (nb_of_chars + file->bytes_readed) < read_value)
			nb_of_chars++;
	return (nb_of_chars);
}

char		**concat_line(t_gnl_lst *file, char **line_adress, int read_value)
{
	char	*new_line;
	size_t	t;

	t = 0;
	if (!new_line = strnew(size_to_write(file, read_value) + 1))
		return (NULL);
	while (!ft_issep(file->buf[file->bytes_readed], "\n\0") && file->bytes_readed < BUFF_SIZE)
		new_line[t++] = file->buf[file->bytes_readed++]
	new_line[t] = '\0';
	if (*line_adress)
	{
		if (!(*line_adress) = ft_strjoin((*line_adress), new_line))
			return (NULL);
		strdel(new_line);
		return (line_adress);
	}
	return (line_adress = &new_line);
}

int			**make_line(t_gnl_lst *file, char **line_adress)
{
	int		bypass_read;
	int		read_value;

	bypass_read = file->bytes_readed < BUFF_SIZE && file->bytes_readed > 0;
	while (bypass_read || read_value = read(file->fd, file->buf, BUFF_SIZE))
	{
		if (read_value == -1 || read_value == 0)
			return (read_value);
		file->bytes_readed = bypass_read ? file->bytes_readed : 0;
		concat_line(file, line_adress, read_value);
		bypass_read = (file->bytes_readed < BUFF_SIZE) ? 1 : 0;
	}
	return (read_value);
	/*return (read_value = read_value > 0 ? 1 : read_value); --> fait le job*/
}

t_gnl_lst	*new_or_find(const int fd, t_gnl_lst **list, int unfound)
{
	t_gnl_lst	*ptr;
	if (!list || unfound == 1)
	{
		if (!(ptr = malloc(sizeof(t_gnl_lst))))
			return (NULL);
		ptr->fd = fd;
		ptr->bytes_readed = BUFF_SIZE;
		ptr->next = unfound ? *list : NULL;
		list = &ptr;
		return (*list);
	}
	ptr = *list;
	while (ptr->next && ptr->fd != fd)
		ptr = ptr->next;
	if (fd == ptr->fd)
		return (ptr);
	return (new_or_find(fd, list, 1));
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl_lst	**list;
	int					status;

	if (!*line)
		return (-1);
	status = make_line(new_or_find(fd, list, 0), line));
		return (
	
}
