/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemple.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:29:48 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/01/26 14:03:52 by Theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int		readlinewidth(int fd)
{
	char	buff[2];
	size_t	nbread;

	(void)memset((void*)buff, 0, (size_t)2);
	nbread = read(fd, (void*)buff, (size_t)2);
	if (nbread == -1 || nbread == 0)
		return (-1);
	buff[1] = '\0';
	return(atoi(buff));
}
void	readandprintlines(int fd, size_t linewidth)
{
	char	*buff;
	size_t	nbread;

	if(!(buff = (char*)malloc(sizeof(*buff) * (linewidth + 1))))
		return;
	(void)memset((void*)buff, 0, linewidth + 1);
	while ((nbread = read(fd, (void*)buff, linewidth)) != 0)
	{
		printf("%s", buff);
		(void)memset((void*)buff, 0, linewidth);
	}
	free(buff);
	return;
}

int		main(void)
{
	int		fd;
	int		linewidth;

	fd = open("./file.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	linewidth = readlinewidth(fd);
	if (linewidth == -1 || linewidth == 0)
		return (-1);
	readandprintlines(fd, (size_t) linewidth);
	close(fd);
	return (0);
}
