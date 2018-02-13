#include "libft.h"

void		display_gnl_values(int bypass_read, t_gnl_lst *file)
{
	ft_putstr("VALUES : \nbypass_read = ");
	ft_putnbr(bypass_read);
	ft_putstr("\nread_value = ");
	ft_putnbr(file->read_value);
	ft_putstr("\nbytes_read = ");
	ft_putnbr(file->bytes_read);
	ft_putstr("\nbuffer contains : ");
	ft_putstr(file->buf);
	ft_putstr("\n\n");
}
