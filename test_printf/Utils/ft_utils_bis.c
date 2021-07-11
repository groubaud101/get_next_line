#include "../ft_printf.h"

void	ft_increment_index(char *format, int *index)
{
	while (format[*index] == '0' || format[*index] == ' ')
		*index = *index + 1;
	if (format[*index] == '.')
		*index = *index + 1;
}

char	*ft_fill_nb(char *format, char *nbr, int index, int i)
{
	while (ft_isdigit(format[index + i]))
	{
		nbr[i] = format[index + i];
		i++;
	}
	return (nbr);
}

int	ft_stock_nb(char *format, int index)
{
	int		i;
	int		nb;
	char	*nbr;
	int		zero;

	i = 0;
	zero = 0;
	i = 0;
	ft_increment_index(format, &index);
	nbr = malloc(sizeof(int) * ft_size_nbr(format, index));
	if (!nbr)
		return (0);
	while (format[index + i] == '-')
	{
		if (i == 0)
			nbr[i++] = '-';
		else
			index++;
	}
	nb = ft_atoi(ft_fill_nb(format, nbr, index, i));
	free(nbr);
	return (nb);
}

int	ft_size_nbr(char *format, int index)
{
	int	i;

	i = 0;
	if (format[index] == '-')
	{
		i++;
		index++;
	}
	while (ft_isdigit(format[index++]))
		i++;
	return (i);
}

int	ft_print_nbr(long long nb, int accuracy, int nb_zero, int len_nb)
{
	int	cpt;

	cpt = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (accuracy > len_nb || nb_zero > len_nb)
	{
		write(1, "0", 1);
		cpt++;
		accuracy--;
		nb_zero--;
	}
	if (nb >= 10)
		ft_print_nbr(nb / 10, 0, 0, 0);
	ft_putchar(nb % 10 + 48);
	return (cpt);
}
