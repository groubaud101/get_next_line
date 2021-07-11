/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsehl <tsehl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:40:12 by dlescart          #+#    #+#             */
/*   Updated: 2021/07/10 14:28:19 by dlescart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_initialize_struct(t_Variable *vr)
{
	vr->is_pair = 0;
	vr->is_space = 0;
	vr->index = 0;
	vr->cpt = 0;
	vr->accuracy = 0;
	vr->nb_zero = 0;
	vr->field = 0;
	vr->tmp_i = 0;
}

void	ft_main2(char *format, t_Variable	*vr)
{			
	if ((ft_isdigit(format[vr->index]) && format[vr->index] != '0')
		|| format[vr->index] == '-')
	{
		vr->field = ft_stock_nb((char *)format, vr->index);
		vr->index += ft_size_num((char *)format, vr->index);
	}
	if (format[vr->index] == '0')
	{
		vr->nb_zero = ft_stock_nb((char *)format, vr->index);
		ft_zero((char *)format, &vr->nb_zero, &vr->accuracy, vr->index);
		vr->index += ft_size_num((char *)format, vr->index);
	}
	if (format[vr->index] == '.')
	{
		vr->accuracy = ft_stock_nb((char *)format, vr->index);
		if (vr->accuracy == 0)
		{
			vr->field = vr->nb_zero;
			vr->nb_zero = 0;
		}
	}
}

void	ft_main(char *format, t_Variable *vr, char *tab_index)
{
	while (format[vr->index] == ' ')
		vr->index++;
	if (format[vr->index] == '%' && ft_percent((char *)
			format, vr->index, tab_index))
	{
		vr->cpt++;
		write(1, "%", 1);
		while (format[vr->index + 1] != '%' && format[vr->index + 1])
		{
			write(1, &format[vr->index + 1], 1);
			vr->index++;
			vr->cpt++;
		}
		vr->index++;
	}
	ft_main2((char *)format, vr);
	vr->index += ft_size_num((char *)format, vr->index);
	vr->tmp_i = ft_find_index(tab_index, format[vr->index]);
}

void	ft_pt_format(char *format, t_Variable *vr)
{
	write(1, &format[vr->index], 1);
	vr->cpt++;
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_Variable	vr;
	void		(*tab_f[8])(va_list *, t_Variable*);
	char		tab_index[9];

	fill_tab_f(tab_f);
	fill_tab_index(tab_index);
	ft_initialize_struct(&vr);
	va_start(ap, format);
	while (format[vr.index])
	{
		if (vr.index != 0 && format[vr.index - 1] == '%')
		{
			ft_main((char *)format, &vr, tab_index);
			if (vr.tmp_i != -1)
				(*tab_f[vr.tmp_i])(&ap, &vr);
			vr.field = 0;
			vr.accuracy = 0;
		}
		else if (format[vr.index] != '%')
			ft_pt_format((char *)format, &vr);
		vr.index++;
	}
	va_end(ap);
	return (vr.cpt);
}
