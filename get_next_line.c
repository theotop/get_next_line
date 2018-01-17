#include "get_next_line.h"


char		**concat_line(t_gnl_lst *file, char **line_adress)
{
	int		bypass_read;
	char	*line;
	
	bypass_read = (file->bytes_readed < BUFF_SIZE) ? 1 : 0;
	while (bypass_read || read(file->fd, file->buf, BUFF_SIZE))
	{
		bytes_readed = bypass_read ? bytes_readed : 0;
		line = &ft_strndup2(*(file->buf) + bytes_readed, (UNE FONCTION QUI ME 
			DIT COMBIEN JE DOIS ÉCRIRE, CHECKE LES \N
			SI ELLE N'EN TROUVE PAS ELLE RENVOIE BUFF_SIZE - bytes_readed))
	}
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

	if (!*line)
		return (-1);
	concat_line(new_or_find(fd, list, 0), line);
	
}


C\UC
2


