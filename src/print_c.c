/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 09:34:59 by sadolph           #+#    #+#             */
/*   Updated: 2020/10/13 15:11:34 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list arg_list, t_spec **spec_det)
{
	wchar_t c;

	c = if_modifier_c(arg_list, spec_det);
	if (!((*spec_det)->flag_dash))
	{
		if (((*spec_det)->width))
			ft_print_symbols(' ', (*spec_det)->width - 1);
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		if (((*spec_det)->width))
			ft_print_symbols(' ', (*spec_det)->width - 1);
	}
	if (((*spec_det)->width))
		(*spec_det)->length += (*spec_det)->width;
	else
		(*spec_det)->length += 1;
}
