#include "get_next_line.h"


char		**concat_line(int fd, t_gnl_lst *file, char **line_adress)
{
	char	*line;
	while (read(fd, file->buf, BUFF_SIZE)
}
t_gnl_lst	*new_or_find(const int fd, t_gnl_lst **list, int unfound)
{
	t_gnl_lst	*ptr;
	if (!list || unfound == 1)
	{
		if (!(ptr = malloc(sizeof(t_gnl_lst))))
			return (NULL);
		ptr->fd = fd;
		//read(fd, ptr->buf, BUFF_SIZE);
		ptr->bytes_readed = 0;
		ptr->next = unfound ? *list : NULL;
		list = &ptr;
		return (*list);
	}
	else
	{
		ptr = *list;
		while (ptr->next && ptr->fd != fd)
			ptr = ptr-> next;
		if (fd == ptr->fd)
			return (ptr);
		return (new_or_find(fd, list, 1));
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl_lst	**list;

	if (!*line)
		return (-1);
	new_or_find(fd, list, 0);
}

int
