#include "libft.h"
void	ft_putunbr_fd(unsigned int n, int fd)
{
	char				c;
	unsigned long int	nbr;

	nbr = n;
	if (nbr >= 10)
	{
		ft_putnbr_fd((nbr / 10), fd);
		c = (nbr % 10) + '0';
		ft_putchar_fd(c, fd);
	}
	if (nbr < 10)
	{
		c = (nbr % 10) + '0';
		ft_putchar_fd(c, fd);
	}
}
