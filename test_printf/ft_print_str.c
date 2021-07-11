#include "ft_printf.h"

void	ft_pt_str(va_list *ap, t_Variable *vr)
{
	char	*str;

	vr->nb_zero = 0;
	str = va_arg(*ap, char *);
	if (!str)
	{
		write(1, "(null)", 7);
		vr->cpt += 6;
		return ;
	}
	while (vr->field-- > ft_strlen(str))
	{
		write(1, " ", 1);
		vr->cpt++;
	}
	if (vr->accuracy != 0 && vr->accuracy < ft_strlen(str))
	{
		write (1, str, vr->accuracy);
		vr->cpt += vr->accuracy;
	}
	else
		write(1, str, ft_strlen(str));
	vr->cpt += ft_strlen(str);
}
