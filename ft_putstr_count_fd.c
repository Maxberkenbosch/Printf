#include <unistd.h>
#include "libft.h"
int	ft_putstr_count_fd(char *s, int fd)
{
	int	total;

	total = 0;
	if (!s)
		return (0);
	total += write(fd, s, ft_strlen(s));
	return (total);
}
