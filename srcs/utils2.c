#include "push_swap.h"

static int    ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_putstr_fd(char *str, int fd)
{
    if (!str)
        return ;
    write(fd, str, ft_strlen(str));
}

static void	print_nb(long nb, int fd)
{
    char    c;

	if (nb / 10)
	{
		print_nb(nb / 10, fd);
		print_nb(nb % 10, fd);
	}
	else
    {
        c = nb + '0';
        write(fd, &c, 1);
    }
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	print_nb(nb, fd);
}

void ft_putdouble_fd(double n, int fd)
{
    int integer_part;
    int decimal_part;

    integer_part = (int)n;
    ft_putnbr_fd(integer_part, fd);

    write(fd, ".", 1);

    decimal_part = (int)(n * 100) % 100;
    if (decimal_part < 10)
        write(fd, "0", 1);
    ft_putnbr_fd(decimal_part, fd);
}