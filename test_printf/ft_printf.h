/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlescart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:55:59 by dlescart          #+#    #+#             */
/*   Updated: 2021/07/10 14:25:33 by dlescart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

//typedef struct t_Variable t_Variable;

typedef struct Variable
{
	int	index;
	int	field;
	int	accuracy;
	int	nb_zero;
	int	is_pair;
	int	is_space;
	int	cpt;
	int	tmp_i;
}				t_Variable;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putchar(char c);
void	ft_putnbr(long long nb);
int		ft_strlen(const char *s);
int		ft_find_index(char *tab, char element);
int		ft_isflag(char c);
int		ft_percent(char *format, int index, char *tab_index);
void	ft_is_space(char *format, int index, t_Variable *vr);
void	ft_zero(char *format, int *nb_zero, int *accuracy, int index);
int		ft_size_num(char *format, int i);
int		ft_size_nbr(char *format, int index);
void	ft_increment_index(char *format, int *index);
char	*ft_fill_nb(char *format, char *nbr, int index, int i);
int		ft_stock_nb(char *format, int index);
int		ft_conv_hexa_min(long long nbr, char *nb_hex);
int		ft_conv_hexa_maj(long long nbr, char *nb_hex);
void	ft_pt_hexa_min(va_list *ap, t_Variable *vr);
void	ft_pt_hexa_maj(va_list *ap, t_Variable *vr);
void	ft_pt_char(va_list *ap, t_Variable *vr);
void	ft_pt_str(va_list *ap, t_Variable *vr);
void	ft_pt_int(va_list *ap, t_Variable *vr);
int		ft_print_nbr(long long nb, int accuracy, int nb_zero, int len_nb);
void	ft_pt_un_int(va_list *ap, t_Variable *vr);
void	ft_condition_u_bis(t_Variable *vr);
void	ft_pt_ptr(va_list *ap, t_Variable *vr);
int		ft_printf(const char *format, ...);
void	fill_tab_f(void (*tab_f[])(va_list *, t_Variable *vr));
void	fill_tab_index(char tab_index[]);
void	ft_conditions(t_Variable *vr, int nbr, int len_nb);
void	ft_conditions_bis(t_Variable *vr, int nbr);
void	ft_pt_int(va_list *ap, t_Variable *vr);
void	ft_pt_int_2(t_Variable *vr, int nbr, int len_nb, int i);
void	ft_pt_int_3(t_Variable *vr, int nbr, int len_nb, int i);
int		ft_size_n(long n);

#endif
