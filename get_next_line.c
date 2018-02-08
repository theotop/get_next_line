/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:13:06 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/02/08 18:07:01 by tlevaufr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		display_values(int bypass_read, int read_value, t_gnl_lst *file)
{
		ft_putstr("VALUES : \nbypass_read = ");
		ft_putnbr(bypass_read);
		ft_putstr("\nread_value = ");
		ft_putnbr(read_value);
		ft_putstr("\nbytes_read = ");
		ft_putnbr(file->bytes_read);
		ft_putstr("\nbuffer contains : ");
		ft_putstr(file->buf);
		ft_putstr("\n\n");
}

void		lst_del(const int fd, t_gnl_lst **list)
{
	t_gnl_lst *ptr;
	t_gnl_lst *ptr2;

	ft_putstr("début de lst_del\n");
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
		return;
	}
	while (ptr->next && ptr->next->fd != fd)
		ptr = ptr->next;
	ptr2 = (ptr->next && ptr->next->next) ? ptr->next->next : NULL;
	free(ptr->next);
	ptr->next = ptr2 ? ptr2 : NULL;
}

char		**concat_line(t_gnl_lst *file, char **line_adress, int read_value)
{
	char	*new_line;
	size_t	t;
	size_t	nb_of_chars;

	nb_of_chars = 0;
	ft_putchar(file->buf[nb_of_chars + file->bytes_read]);
	while (file->buf[nb_of_chars + file->bytes_read] && file->buf[nb_of_chars +\
	file->bytes_read] != '\n' && (nb_of_chars + file->bytes_read) < read_value)
			nb_of_chars++;
	t = 0;
	if (!(new_line = ft_strnew(nb_of_chars + 1)))
		return (NULL);
	while (file->buf[file->bytes_read] && file->buf[file->bytes_read] != '\n'\
			&& file->bytes_read < BUFF_SIZE)
		new_line[t++] = file->buf[file->bytes_read++];
	ft_putstr("c'est good\n");
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

int		make_line(t_gnl_lst *file, char **line_adress)
{
	int		bypass_read;
	int		read_value;

	bypass_read = file->bytes_read < (BUFF_SIZE) && file->bytes_read > 0;
	while (bypass_read || (read_value = (int)read(file->fd, file->buf, BUFF_SIZE)))
	{
		display_values(bypass_read, read_value, file);
		if (read_value == -1 || read_value == 0)
			return (read_value);
		file->bytes_read = bypass_read ? file->bytes_read : 0;
		concat_line(file, line_adress, read_value);
		bypass_read = file->bytes_read < (BUFF_SIZE) && file->bytes_read < read_value;
		if (read_value < BUFF_SIZE && file->bytes_read == read_value)
		{
			return (0);
		}
		if (file->buf[file->bytes_read] == '\n')
		{
			file->bytes_read++;
			display_values(bypass_read, read_value, file);
			return ((read_value > 0) ? 1 : read_value);
		}
	}
	return ((read_value > 0) ? 1 : read_value);
}

t_gnl_lst	*new_or_find(const int fd, t_gnl_lst **list, int unfound)
{
	t_gnl_lst	*ptr;

	ft_putstr("début de new_or_find\n");
	if (!(*list) || unfound == 1)
	{
		if (!(ptr = malloc(sizeof(t_gnl_lst))))
			return (NULL);
		ptr->fd = fd;
		ptr->bytes_read = BUFF_SIZE;
		ft_bzero(ptr->buf, BUFF_SIZE);
		ptr->next = unfound ? *list : NULL;
		*list = ptr;
		return (*list);
	}
	ft_putstr("list exists\n");
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
	ft_putstr("début de gnl\n");
	status = make_line(new_or_find(fd, &list, 0), line);
	if (status == 0)
		lst_del(fd, &list);
	ft_putstr("fin de gnl");
	return (status);
}
