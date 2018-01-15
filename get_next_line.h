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

#endif
