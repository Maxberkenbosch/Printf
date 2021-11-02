#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

int		ft_putchar_count_fd(char c, int fd, int total);
int		ft_putstr_count_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putnbr_count_fd(int n, int fd);
int		ft_puthex_count_lower(unsigned long int n, int fd);
int		ft_puthex_count_upper(unsigned int n, int fd);
int		ft_putunbr(unsigned int n, int fd);
size_t	ft_strlen(const char *s);

#endif
