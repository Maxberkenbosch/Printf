#include "ft_printf.h"
int	ft_putstr_count_fd(char *s, int fd)
{
	int	total;

	total = 0;
	if (s)
	{
		total += write(fd, s, ft_strlen(s));
	}
	else
	{
		total += write(1, "(null)", 6);
	}
	return (total);
}
