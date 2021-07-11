#include "ft_printf.h"

void	ft_conditions_u(t_Variable *vr, int nbr, int len_nb)
{
	if (nbr == 0)
		len_nb = 0;
	if (vr->accuracy > vr->nb_zero && vr->nb_zero > 0)
		vr->nb_zero = 0;
	else if (vr->accuracy >= vr->field && vr->field > 0)
		vr->field = 0;
	else if (vr->nb_zero > vr->accuracy && vr->accuracy > 0
		&& vr->nb_zero > len_nb)
	{
		while (vr->nb_zero-- > vr->accuracy)
		{
			vr->cpt++;
			write(1, " ", 1);
		}
		vr->nb_zero = 0;
	}
	else if (vr->field > vr->accuracy && vr->accuracy > 0
		&& vr->accuracy > len_nb)
		ft_condition_u_bis(vr);
}

void	ft_condition_u_bis(t_Variable *vr)
{
	while (vr->field-- > vr->accuracy)
	{
		vr->cpt++;
		write(1, " ", 1);
	}
	vr->field = 0;
}

void	ft_pt_int_u_2(t_Variable *vr, int len_nb)
{
	while (vr->field > len_nb)
	{
		write(1, " ", 1);
		vr->cpt++;
		vr->field--;
	}
	while (vr->nb_zero-- > len_nb)
	{
		write(1, "0", 1);
		vr->cpt++;
		vr->accuracy = 0;
	}
	while (vr->accuracy-- > len_nb)
	{
		write(1, "0", 1);
		vr->cpt++;
	}
}

void	ft_pt_un_int(va_list *ap, t_Variable *vr)
{
	long	nbr;
	int		i;
	int		len_nb;

	i = 0;
	nbr = va_arg(*ap, int);
	if (nbr < 0)
		nbr += 4294967296;
	len_nb = ft_size_n(nbr);
	ft_conditions_u(vr, nbr, len_nb);
	ft_pt_int_u_2(vr, len_nb);
	vr->cpt += ft_print_nbr(nbr, vr->accuracy, vr->nb_zero, len_nb);
	while (vr->field * -1 > (len_nb + vr->cpt))
	{	
		vr->cpt++;
		write(1, " ", 1);
	}
	vr->cpt += len_nb;
}
