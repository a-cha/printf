/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:34:13 by sadolph           #+#    #+#             */
/*   Updated: 2020/10/13 15:11:22 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_perc(t_spec **spec_det)
{
	if (!((*spec_det)->flag_dash))
	{
		if (((*spec_det)->width))
			ft_print_symbols(((*spec_det)->flag_0) ? '0' : ' ',
					(*spec_det)->width - 1);
		write(1, "%", 1);
	}
	else
	{
		write(1, "%", 1);
		if (((*spec_det)->width))
			ft_print_symbols(' ', (*spec_det)->width - 1);
	}
	if (((*spec_det)->width))
		(*spec_det)->length += (*spec_det)->width;
	else
		(*spec_det)->length += 1;
}
