/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:31:14 by sadolph           #+#    #+#             */
/*   Updated: 2020/10/13 15:11:31 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_zeroprec(int *len, t_spec **spec_det)
{
	*len = 0;
	if (!((*spec_det)->flag_dash))
	{
		ft_print_symbols(' ', (*spec_det)->flag_sp_or_pl == '+'
		? (*spec_det)->width - 1 : (*spec_det)->width);
		if ((*spec_det)->flag_sp_or_pl == '+')
			write(1, "+", 1);
	}
	else
	{
		if ((*spec_det)->flag_sp_or_pl == '+')
			write(1, "+", 1);
		ft_print_symbols(' ', (*spec_det)->flag_sp_or_pl == '+'
		? (*spec_det)->width - 1 : (*spec_det)->width);
	}
}

static void	if_flag_sp_or_pl(long long n, t_spec **spec_det)
{
	if (n < 0)
		write(1, "-", 1);
	else if (((*spec_det)->flag_sp_or_pl))
	{
		if ((*spec_det)->flag_sp_or_pl == '+')
			write(1, "+", 1);
		else
			write(1, " ", 1);
	}
}

static void	manage_flags2(long long n, t_spec **spec_det, int len, int len_num)
{
	if (n < 0 || ((*spec_det)->flag_sp_or_pl))
	{
		if_flag_sp_or_pl(n, spec_det);
		len++;
	}
	if (len_num)
		ft_print_symbols('0', len_num);
	ft_putnbr_wo_sign(n);
	if (((*spec_det)->width) > len + len_num)
		ft_print_symbols(' ', (*spec_det)->width - len - len_num);
}

static void	manage_flags(long long n, t_spec **spec_det, int len, int len_num)
{
	char flag;

	flag = 'r';
	if (!((*spec_det)->flag_dash))
	{
		if (((*spec_det)->flag_0) && (n < 0 || ((*spec_det)->flag_sp_or_pl))
		&& (*spec_det)->prec < 0)
		{
			if_flag_sp_or_pl(n, spec_det);
			flag = '-';
		}
		if (((*spec_det)->width) > len + len_num)
			ft_print_symbols(((*spec_det)->flag_0) && (*spec_det)->prec == -1
			? '0' : ' ', (*spec_det)->width - len_num - len -
			(((*spec_det)->flag_sp_or_pl) || n < 0 ? 1 : 0));
		if ((n < 0 || ((*spec_det)->flag_sp_or_pl)) && flag != '-')
			if_flag_sp_or_pl(n, spec_det);
		if (len_num)
			ft_print_symbols('0', len_num);
		ft_putnbr_wo_sign(n);
	}
	else
		manage_flags2(n, spec_det, len, len_num);
}

void		print_di(va_list arg_list, t_spec **spec_det)
{
	long long	n;
	int			len;
	int			len_num;

	n = if_modifier_di(arg_list, spec_det);
	len = ft_numlen((long)n, 10);
	len_num = (*spec_det)->prec > len ? (*spec_det)->prec - (int)len : 0;
	if (n == 0 && (*spec_det)->prec == 0)
		zero_zeroprec(&len, spec_det);
	else
		manage_flags(n, spec_det, len, len_num);
	if (n < 0 || ((*spec_det)->flag_sp_or_pl))
		len++;
	if (((*spec_det)->width) > len + len_num)
		(*spec_det)->length += (*spec_det)->width;
	else
		(*spec_det)->length += len + len_num;
}
