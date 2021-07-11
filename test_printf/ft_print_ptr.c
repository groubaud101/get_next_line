#include "ft_printf.h"

void	ft_pt_ptr(va_list *ap, t_Variable *vr)
{
	unsigned long	nbr;
	int				i;
	char			nb_hex[100];

	write(1, "0x", 2);
	nbr = (unsigned long)va_arg(*ap, void *);
	i = ft_conv_hexa_min(nbr, nb_hex);
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
	while (i-- >= 0)
		write(1, &nb_hex[i], 1);
	vr->cpt += ft_strlen(nb_hex) + 2;
}
