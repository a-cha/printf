/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:56:29 by sadolph           #+#    #+#             */
/*   Updated: 2020/10/31 21:22:50 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit_wo0(int c)
{
	return ((c >= 49 && c <= 57) ? 1 : 0);
}

void	ft_print_symbols(char symbol, int length)
{
	while (length--)
		write(1, &symbol, 1);
}

void	ft_putnbr_wo_sign(long long n)
{
	if (n == -9223372036854775807)
	{
		write(1, "9223372036854775807", 19);
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n > 9)
		ft_putnbr_wo_sign(n / 10);
	n = n % 10 + '0';
	write(1, &n, 1);
}

t_spec	*ft_lstnew_printf(void)
{
	t_spec *new;

	if ((new = (t_spec *)malloc(sizeof(t_spec))))
	{
		new->flag_dash = 0;
		new->flag_0 = 0;
		new->flag_dote = 0;
		new->flag_sp_or_pl = 0;
		new->flag_grid = 0;
		new->if_width_star = 0;
		new->width = 0;
		new->if_precision_star = 0;
		new->prec = -1;
		new->modifier = 0;
		new->type = 0;
		new->length = 0;
	}
	return (new);
}

void	ft_struct_zero(t_spec **spec_det)
{
	(*spec_det)->flag_dash = 0;
	(*spec_det)->flag_0 = 0;
	(*spec_det)->flag_dote = 0;
	(*spec_det)->flag_sp_or_pl = 0;
	(*spec_det)->flag_grid = 0;
	(*spec_det)->if_width_star = 0;
	(*spec_det)->width = 0;
	(*spec_det)->if_precision_star = 0;
	(*spec_det)->prec = -1;
	(*spec_det)->modifier = 0;
	(*spec_det)->type = 0;
	(*spec_det)->length = 0;
}
