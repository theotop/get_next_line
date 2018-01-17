/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:17:36 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/01/17 17:57:22 by tlevaufr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4

typedef struct		s_gnl_lst
{
		int			fd;
		char		buf[BUFF_SIZE];
		size_t		bytes_readed;
		s_struct	*next;
}					t_gnl_lst;

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>

#endif
