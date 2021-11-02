#include "ft_printf.h"
int	ft_putunbr(unsigned int n, int fd)
{
	char				c;
	unsigned long int	nbr;
	int					total;

	nbr = n;
	total = 0;
	if (nbr >= 10)
	{
		total += ft_putnbr_count_fd((nbr / 10), fd);
		c = (nbr % 10) + '0';
		total += write(1, &c, 1);
	}
	if (nbr < 10)
	{
		c = (nbr % 10) + '0';
		total += write(1, &c, 1);
	}
	return (total);
}
