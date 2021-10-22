#include "libftprintf.h"

int	ft_checks(const char *format, int i, va_list args);

int	ft_part_1(const char *format, int i, va_list args);

int	ft_part_2(const char *format, int i, va_list args);

int	ft_x_X(const char *format, int i, unsigned int j);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start (args, format);
	total += ft_checks(format, i, args);
	va_end (args);
	return (total);
}

int	ft_checks(const char *format, int i, va_list args)
{
	int	total;

	total = 0;
	while (format[i])
	{
		if (format[i] != '%')
			total += write(1, &format[i], 1);
		if ((format[i] == '%' && format[i + 1] == '%')
			|| (format[i] == '%' && format[i + 1] == 'c')
			|| (format[i] == '%' && format[i + 1] == 's')
			|| (format[i] == '%' && (format[i + 1] == 'd'
					|| format[i + 1] == 'i'))
			|| (format[i] == '%' && (format[i + 1] == 'x'
					|| format[i + 1] == 'X'))
			|| (format[i] == '%' && format[i + 1] == 'p'))
		{
			total += ft_part_1(format, i, args);
			total += ft_part_2(format, i, args);
			i += 2;
			continue ;
		}
		i++;
	}
	return (total);
}

int	ft_part_1(const char *format, int i, va_list args)
{
	int		total;
	int		j;
	char	*k;

	total = 0;
	if (format[i] == '%' && format[i + 1] == '%')
		total += ft_putchar_count_fd(format[i], 1, total);
	if (format[i] == '%' && format[i + 1] == 'c')
	{
		j = va_arg(args, int);
		total += ft_putchar_count_fd(j, 1, total);
	}
	if (format[i] == '%' && format[i + 1] == 's')
	{
		k = va_arg(args, char *);
		total += ft_putstr_count_fd(k, 1);
	}
	if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
	{
		j = va_arg(args, int);
		total += ft_putnbr_count_fd(j, 1);
	}
	return (total);
}

int	ft_part_2(const char *format, int i, va_list args)
{
	int					total;
	unsigned int		j;
	unsigned long int	k;

	total = 0;
	if (format[i] == '%' && (format[i + 1] == 'x' || format[i + 1] == 'X'))
	{
		j = va_arg(args, unsigned int);
		total += ft_x_X(format, i, j);
	}
	if (format[i] == '%' && format[i + 1] == 'p')
	{
		total += write(1, "0x", 2);
		k = va_arg(args, unsigned long int);
		total += ft_puthex_count_lower(k, 1);
	}
	return (total);
}

int	ft_x_X(const char *format, int i, unsigned int j)
{
	int	total;

	total = 0;
	if (format[i] == '%' && format[i + 1] == 'x')
	{
		total += ft_puthex_count_lower(j, 1);
	}
	if (format[i] == '%' && format[i + 1] == 'X')
	{
		total += ft_puthex_count_upper(j, 1);
	}
	return (total);
}

int main()
{
	void 	*p;


	// ft_printf("Hallooo, %s hebben %d a %i levens%c\t.De chipcode van dit geitje is %x of %X oof %p?\n\n", "geitjes", 7, 8, '!', 45, 45, &p);
	// printf("Hallooo, %s hebben %d a %i levens%c\t.De chipcode van dit geitje is %x of %X oof %p?\n\n", "geitjes", 7, 8, '!', 45, 45, &p);
	ft_printf("\n%d\n", ft_printf("\nHallooo, %s hebben %d a %i levens%c\t.De chipcode van dit geitje is %x of %X of was het %p?\n\n", "geitjes", 7, 8, '!', 45, 45, &p));
	printf("\n%d\n", printf("\nHallooo, %s hebben %d a %i levens%c\t.De chipcode van dit geitje is %x of %X of was het %p?\n\n", "geitjes", 7, 8, '!', 45, 45, &p));

}