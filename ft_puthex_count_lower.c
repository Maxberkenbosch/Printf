#include "ft_printf.h"
int	ft_puthex_count_lower(unsigned long int n, int fd)
{
	char				c;
	unsigned long int	nbr;
	int					total;

	nbr = n;
	total = 0;
	if (nbr >= 16)
	{
		total += ft_puthex_count_lower((nbr / 16), fd);
		if (nbr % 16 < 10)
			c = (nbr % 16) + '0';
		else
			c = (nbr % 16) + 87;
		total += write(fd, &c, 1);
	}
	if (nbr < 16)
	{
		if (nbr % 16 < 10)
			c = (nbr % 16) + '0';
		else
			c = (nbr % 16) + 87;
		total += write(fd, &c, 1);
	}
	return (total);
}
