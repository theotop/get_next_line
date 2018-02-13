/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:17:36 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/02/10 09:57:36 by Theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4

# include <string.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>

typedef struct				s_gnl_lst
{
		int					fd;
		int					read_value;
		char				buf[BUFF_SIZE];
		size_t				bytes_read;
		struct s_gnl_lst	*next;
}							t_gnl_lst;

int		get_next_line(const int fd, char **line);
#endif
