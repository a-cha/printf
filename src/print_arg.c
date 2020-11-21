/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:25:44 by sadolph           #+#    #+#             */
/*   Updated: 2020/10/13 15:11:38 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	what_type(va_list arg_list, t_spec *spec_det)
{
	if (spec_det->type == '%')
		print_perc(&spec_det);
	else if (spec_det->type == 'c')
		print_c(arg_list, &spec_det);
	else if (spec_det->type == 's')
		print_s(arg_list, &spec_det);
	else if (spec_det->type == 'u')
		print_u(arg_list, &spec_det);
	else if (spec_det->type == 'd' || spec_det->type == 'i')
		print_di(arg_list, &spec_det);
	else if (spec_det->type == 'x' || spec_det->type == 'X')
		print_x(arg_list, &spec_det);
	else if (spec_det->type == 'p')
		print_p(arg_list, &spec_det);
}

void		print_arg(va_list arg_list, t_spec *spec_det, size_t res)
{
	long long	*r;

	if ((spec_det->if_width_star))
	{
		spec_det->width = va_arg(arg_list, int);
		if (spec_det->width < 0)
		{
			spec_det->flag_dash = 'y';
			spec_det->width *= -1;
		}
	}
	if ((spec_det->flag_dote) && spec_det->prec == -1)
		spec_det->prec = 0;
	if ((spec_det->if_precision_star))
	{
		spec_det->prec = va_arg(arg_list, int);
		if (spec_det->prec < 0)
			spec_det->prec = -1;
	}
	if (spec_det->type == 'n')
	{
		r = if_modifier_n(arg_list, &spec_det);
		*r = (res + spec_det->length);
	}
	what_type(arg_list, spec_det);
}
