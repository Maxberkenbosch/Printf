#include "libft.h"
void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
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
