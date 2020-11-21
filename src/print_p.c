/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 19:38:18 by sadolph           #+#    #+#             */
/*   Updated: 2020/10/13 15:11:26 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	manage_flag(unsigned long long n, t_spec **spec_det, int len)
{
	char			*base;

	base = (*spec_det)->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	if (!((*spec_det)->flag_dash))
	{
		if (((*spec_det)->width) > len)
			ft_print_symbols(' ', (*spec_det)->width - len);
		write(1, "0x", 2);
		if (!(n == 0 && (*spec_det)->prec >= 0))
			ft_putnbr_hex(n, base, 16);
	}
	else
	{
		write(1, "0x", 2);
		if (!(n == 0 && (*spec_det)->prec >= 0))
			ft_putnbr_hex(n, base, 16);
		if (((*spec_det)->width) > len)
			ft_print_symbols(' ', (*spec_det)->width - len);
	}
}

void		print_p(va_list arg_list, t_spec **spec_det)
{
	unsigned long long	n;
	size_t				len;

	n = va_arg(arg_list, size_t);
	len = ft_numlen((long)n, 16) + 2;
	if (n == 0 && (*spec_det)->prec >= 0)
		len--;
	manage_flag(n, spec_det, len);
	if (((*spec_det)->width) > (int)len)
		(*spec_det)->length += (*spec_det)->width;
	else
		(*spec_det)->length += len;
}
