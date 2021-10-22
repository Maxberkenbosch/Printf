#include <unistd.h>
int	ft_putchar_count_fd(char c, int fd, int total)
{
	total += write(fd, &c, 1);
	return (total);
}
