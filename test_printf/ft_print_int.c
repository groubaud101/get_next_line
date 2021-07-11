#include "ft_printf.h"

void	ft_conditions_bis(t_Variable *vr, int nbr)
{
	if (nbr < 0)
		vr->accuracy++;
	while (vr->field-- > vr->accuracy)
	{
		vr->cpt++;
		write(1, " ", 1);
	}
	vr->field = 0;
}

void	ft_conditions(t_Variable *vr, int nbr, int len_nb)
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
		if (nbr < 0)
			vr->accuracy++;
		while (vr->nb_zero-- > vr->accuracy)
		{
			vr->cpt++;
			write(1, " ", 1);
		}
		vr->nb_zero = 0;
	}
	else if (vr->field > vr->accuracy && vr->accuracy > 0
		&& vr->accuracy > len_nb)
		ft_conditions_bis(vr, nbr);
}

void	ft_pt_int_2(t_Variable *vr, int nbr, int len_nb, int i)
{
	while (vr->field > len_nb)
	{
		write(1, " ", 1);
		vr->cpt++;
		vr->field--;
	}
	while (vr->nb_zero-- > len_nb)
	{
		if (nbr < 0 && i == 0)
		{
			write(1, "-", 1);
			i++;
		}
		write(1, "0", 1);
		vr->cpt++;
		vr->accuracy = 0;
	}
}

void	ft_pt_int_3(t_Variable *vr, int nbr, int len_nb, int i)
{
	while (vr->accuracy-- > len_nb)
	{
		if (nbr < 0 && i == 0)
		{
			write(1, "-", 1);
			i++;
		}
		write(1, "0", 1);
		vr->cpt++;
	}
}

void	ft_pt_int(va_list *ap, t_Variable *vr)
{
	int	nbr;
	int	i;
	int	len_nb;

	i = 0;
	nbr = va_arg(*ap, int);
	len_nb = ft_size_n(nbr);
	ft_conditions(vr, nbr, len_nb);
	ft_pt_int_2(vr, nbr, len_nb, i);
	ft_pt_int_3(vr, nbr, len_nb, i);
	vr->cpt += ft_print_nbr(nbr, vr->accuracy, vr->nb_zero, len_nb);
	while (vr->field * -1 > (len_nb + vr->cpt))
	{	
		vr->cpt++;
		write(1, " ", 1);
	}
	vr->cpt += len_nb;
}
