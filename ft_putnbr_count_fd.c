#include "libft.h"
int	ft_putnbr_count_fd(int n, int fd)
{
	char		c;
	long int	nbr;
	int			total;

	total = 0;
	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		total += ft_putnbr_count_fd((nbr / 10), fd);
		c = (nbr % 10) + '0';
		total += write(fd, &c, 1);
	}
	if (nbr < 10)
	{
		c = (nbr % 10) + '0';
		total += write(fd, &c, 1);
	}
	return (total);
}
