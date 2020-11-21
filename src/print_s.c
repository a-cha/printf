/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 09:56:08 by sadolph           #+#    #+#             */
/*   Updated: 2020/10/13 15:11:18 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr_len(wchar_t *s, int n)
{
	write(1, s, n);
}

static void	flag_dash_presented(t_spec **spec_det, wchar_t *str, size_t len)
{
	if (!str)
		write(1, "(null)", len);
	else
		!((*spec_det)->modifier) ? write(1, str, len) : ft_putstr_len(str, len);
	if (((*spec_det)->width) > (int)len)
		ft_print_symbols(' ', (*spec_det)->width - (int)len);
}

void		print_s(va_list arg_list, t_spec **spec_det)
{
	wchar_t	*str;
	size_t	len;

	str = if_modifier_s(arg_list, spec_det, &len);
	if ((*spec_det)->prec != -1)
		len = (*spec_det)->prec > (int)len ? len : (*spec_det)->prec;
	if (!((*spec_det)->flag_dash))
	{
		if (((*spec_det)->width) > (int)len)
			ft_print_symbols(' ', (*spec_det)->width - (int)len);
		if (!str)
			write(1, "(null)", len);
		else
			!((*spec_det)->modifier) ? write(1, str, len) :
														ft_putstr_len(str, len);
	}
	else
		flag_dash_presented(spec_det, str, len);
	if (((*spec_det)->width) > (int)len)
		(*spec_det)->length += (*spec_det)->width;
	else
		(*spec_det)->length += len;
}
