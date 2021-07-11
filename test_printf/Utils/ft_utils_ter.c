#include "../ft_printf.h"

void	fill_tab_f(void (*tab_f[])(va_list *, t_Variable *vr))
{
	tab_f[0] = ft_pt_char;
	tab_f[1] = ft_pt_str;
	tab_f[2] = ft_pt_ptr;
	tab_f[3] = ft_pt_int;
	tab_f[4] = ft_pt_int;
	tab_f[5] = ft_pt_un_int;
	tab_f[6] = ft_pt_hexa_min;
	tab_f[7] = ft_pt_hexa_maj;
}

void	fill_tab_index(char tab_index[])
{
	tab_index[0] = 'c';
	tab_index[1] = 's';
	tab_index[2] = 'p';
	tab_index[3] = 'd';
	tab_index[4] = 'i';
	tab_index[5] = 'u';
	tab_index[6] = 'x';
	tab_index[7] = 'X';
	tab_index[8] = 0;
}

int	ft_size_n(long n)
{
	int	size_n;

	size_n = 0;
	if (n <= 0)
		size_n = 1;
	while (n != 0)
	{
		n /= 10;
		size_n++;
	}
	return (size_n);
}

int	ft_percent(char *format, int index, char *tab_index)
{
	int	percent;

	percent = 0;
	index--;
	while (index >= 0)
	{
		if (format[index] == '%')
			percent ++;
		if (ft_find_index(tab_index, format[index]) != -1)
		{
			if (percent % 2 == 1)
				return (1);
			else
				return (0);
		}
		index--;
	}
	if (percent % 2 == 1)
		return (1);
	return (0);
}
