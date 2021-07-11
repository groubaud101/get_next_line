#include "ft_printf.h"

void	ft_pt_char(va_list *ap, t_Variable *vr)
{
	char	c;

	vr->accuracy = 0;
	vr->nb_zero = 0;
	while (vr->field-- > 1)
	{
		write(1, " ", 1);
		vr->cpt++;
	}
	c = va_arg(*ap, int);
	write(1, &c, 1);
	vr->cpt++;
}
