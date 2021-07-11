#include "../ft_printf.h"

int	ft_find_index(char *tab, char element)
{
	int	index;

	index = 0;
	while (tab[index])
	{
		if (tab[index] == element)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_isflag(char c)
{
	if (c == 'c' || c == 's' || c == 'd'
		 || c == 'i' || c == 'p' || c == 'x' || c == 'X' || c == 'u')
		 return (1);
	return (0);
}

void	ft_is_space(char *format, int index, t_Variable *vr)
{
	while (format[index] && format[index] != '%')
	{
		if (format[index] == ' ')
		{	
			write(1, " ", 1);
			vr->cpt++;
			if (vr->field > 0)
				vr->field--;
			else if (vr->nb_zero > 0)
				vr->nb_zero--;
			else if (vr->field < 0)
				vr->field++;
		}
		index--;
	}
}

void	ft_zero(char *format, int *nb_zero, int *accuracy, int index)
{
	int	cpt;

	cpt = 0;
	while (format[index] == '0' || format[index] == ' ')
		index++;
	if (format[index] == '.')
	{
		*accuracy = *nb_zero;
		*nb_zero = 0;
	}
}

int	ft_size_num(char *format, int i)
{
	int	j;

	j = 0;
	if (format[i + j] == '.')
		j++;
	while (ft_isdigit(format[i + j]) || format[i + j] == ' '
		|| format[i + j] == '-'
		|| format[i + j] == '*' || format[i + j] == 39 || format[i + j] == '#')
		j++;
	return (j);
}
