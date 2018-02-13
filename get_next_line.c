/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:13:06 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/02/13 21:10:47 by tlevaufr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		lst_del(const int fd, t_gnl_lst **list)
{
	t_gnl_lst *ptr;
	t_gnl_lst *ptr2;

	ptr = *list;
	if (ptr->fd == fd)
	{
		if (ptr->next)
		{
			list = &(ptr->next);
			free(ptr);
		}
		else
		{
			free(*list);
			*list = NULL;
			list = NULL;
		}
		return ;
	}
	while (ptr->next && ptr->next->fd != fd)
		ptr = ptr->next;
	ptr2 = (ptr->next && ptr->next->next) ? ptr->next->next : NULL;
	free(ptr->next);
	ptr->next = ptr2 ? ptr2 : NULL;
}

char		**concat_line(t_gnl_lst *file, char **line_adress)
{
	char	*new_line;
	size_t	t;
	size_t	chars;

	chars = 0;
	while (file->buf[chars + file->bytes_read] != '\n' && file->buf[chars +\
			file->bytes_read] && (chars + file->bytes_read) < file->read_value)
		chars++;
	t = 0;
	if (!(new_line = ft_strnew(chars + 1)))
		return (NULL);
	while (file->buf[file->bytes_read] && file->buf[file->bytes_read] != '\n'\
											&& file->bytes_read < BUFF_SIZE)
		new_line[t++] = file->buf[file->bytes_read++];
	new_line[t] = '\0';
	if (*line_adress)
	{
		*line_adress = ft_strjoin((*line_adress), new_line);
		ft_strdel(&new_line);
		return (line_adress);
	}
	*line_adress = new_line;
	return (line_adress);
}

int			make_line(t_gnl_lst *file, char **line_adress)
{
	int		bypass_read;

	bypass_read = file->bytes_read < file->read_value && file->bytes_read > 0;
	while (bypass_read ||\
				(file->read_value = (int)read(file->fd, file->buf, BUFF_SIZE)))
	{
		if (file->read_value == -1 || file->read_value == 0)
			return (file->read_value);
		file->bytes_read = bypass_read ? file->bytes_read : 0;
		concat_line(file, line_adress);
		bypass_read = file->bytes_read < (BUFF_SIZE) &&\
											file->bytes_read < file->read_value;
		if (file->read_value < BUFF_SIZE && file->bytes_read ==\
															file->read_value)
			return (0);
		if (file->buf[file->bytes_read] == '\n')
		{
			file->bytes_read++;
			return ((file->read_value > 0) ? 1 : file->read_value);
		}
	}
	return ((file->read_value > 0) ? 1 : file->read_value);
}

t_gnl_lst	*new_or_find(const int fd, t_gnl_lst **list, int unfound)
{
	t_gnl_lst	*ptr;

	if (!(*list) || unfound == 1)
	{
		if (!(ptr = malloc(sizeof(t_gnl_lst))))
			return (NULL);
		ptr->fd = fd;
		ptr->read_value = BUFF_SIZE;
		ptr->bytes_read = BUFF_SIZE;
		ft_bzero(ptr->buf, BUFF_SIZE);
		ptr->next = unfound ? *list : NULL;
		*list = ptr;
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
	static t_gnl_lst	*list;
	int					status;

	if (!line)
		return (-1);
	*line = NULL;
	status = make_line(new_or_find(fd, &list, 0), line);
	if (status == 0)
		lst_del(fd, &list);
	return (status);
}
