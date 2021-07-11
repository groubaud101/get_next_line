#include "ft_printf.h"

int	ft_conv_hexa_maj(long long nbr, char *nb_hex)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	if (nbr < 0)
		nbr += 4294967296;
	if (nbr == 0)
		nb_hex[i++] = '0';
	while (nbr != 0)
	{
		temp = nbr % 16;
		if (temp < 10)
			nb_hex[i++] = temp + 48;
		else
			nb_hex[i++] = temp + 55;
		nbr /= 16;
	}
	nb_hex[i] = '\0';
	return (i);
}

void	ft_pt_hexa_maj(va_list *ap, t_Variable *vr)
{
	long long	nbr;
	int			i;
	char		nb_hex[100];

	nbr = va_arg(*ap, int);
	i = ft_conv_hexa_maj(nbr, nb_hex);
	while (vr->field-- > ft_strlen(nb_hex))
	{
		write(1, " ", 1);
		vr->cpt++;
	}
	while (vr->nb_zero-- > ft_strlen(nb_hex))
	{
		write(1, "0", 1);
		vr->cpt++;
	}
	while (vr->accuracy-- > ft_strlen(nb_hex))
	{
		write(1, "0", 1);
		vr->cpt++;
	}
	while (i >= 0)
		write(1, &nb_hex[i--], 1);
	vr->cpt += ft_strlen(nb_hex);
}
