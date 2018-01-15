#include "get_next_line.h"

t_gnl_lst	*list;

char		**concat_line(int fd, char **line)
{
}
t_gnl_lst	*scan_list(int fd, 

t_gnl_lst	*new_list(int fd)
{
	t_gnl_lst	*ptr;

	if (!(ptr = malloc(sizeof(t_gnl_lst))))
		return (NULL);
	ptr->fd = fd;
	read(fd, ptr->buf, [BUFF_SIZE]);
	ptr->bytes_readed = [BUFF_SIZE];
	ptr->next = NULL;
	return (ptr);
}

int			get_next_line(int fd, char **line)
{
	if (!line)
		return (-1);
	if (!list)		&list = new_list(fd);
	
}

int
