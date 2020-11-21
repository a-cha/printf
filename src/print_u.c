/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:08:16 by sadolph           #+#    #+#             */
/*   Updated: 2020/10/13 15:11:12 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_zeroprec(int width, int *len)
{
	*len = 0;
	ft_print_symbols(' ', width);
}

static void	manage_flag(unsigned long long n, t_spec **spec_det, int len,
																	int len_num)
{
	if (!((*spec_det)->flag_dash))
	{
		if (((*spec_det)->width) > len + len_num)
			ft_print_symbols(((*spec_det)->flag_0) && (*spec_det)->prec == -1 ?
			'0' : ' ', (*spec_det)->width - len_num - len);
		if (len_num)
			ft_print_symbols('0', len_num);
		ft_putnbr_hex(n, "0123456789abcdef", 10);
	}
	else
	{
		if (len_num)
			ft_print_symbols('0', len_num);
		ft_putnbr_hex(n, "0123456789abcdef", 10);
		if (((*spec_det)->width) > len + len_num)
			ft_print_symbols(' ', (*spec_det)->width - len - len_num);
	}
}

void		print_u(va_list arg_list, t_spec **spec_det)
{
	unsigned long long	n;
	int					len;
	int					len_num;

	n = if_modifier_ux(arg_list, spec_det);
	len = ft_numlen_uns((unsigned long long)n, 10);
	len_num = (*spec_det)->prec > len ? (*spec_det)->prec - (int)len : 0;
	if (((*spec_det)->flag_dote) && n == 0 && (*spec_det)->prec == 0)
		zero_zeroprec((*spec_det)->width, &len);
	else
		manage_flag(n, spec_det, len, len_num);
	if (((*spec_det)->width) > len + len_num)
		(*spec_det)->length += (*spec_det)->width;
	else
		(*spec_det)->length += len + len_num;
}
