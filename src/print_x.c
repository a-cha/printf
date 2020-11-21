/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 19:43:38 by sadolph           #+#    #+#             */
/*   Updated: 2020/10/13 15:11:01 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_zeroprec(int width, int *len)
{
	*len = 0;
	ft_print_symbols(' ', width);
}

static void	if_grid(t_spec **spec_det, char *flag)
{
	if ((*spec_det)->type == 'x')
		write(1, "0x", 2);
	else
		write(1, "0X", 2);
	if (*flag != 'e')
		*flag = '-';
}

static void	manage_fl(unsigned long long n, t_spec **spec_det, int *len,
																	int len_num)
{
	char	*base;

	base = (*spec_det)->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	if (((*spec_det)->flag_grid) && n != 0)
	{
		if_grid(spec_det, "e");
		*len += 2;
	}
	if (len_num)
		ft_print_symbols('0', len_num);
	ft_putnbr_hex(n, base, 16);
	if (((*spec_det)->width) > *len + len_num)
		ft_print_symbols(' ', (*spec_det)->width - *len - len_num);
}

static void	manage_fla(unsigned long long n, t_spec **spec_det, int *len,
																	int len_num)
{
	char	*base;
	char	flag;

	base = (*spec_det)->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	flag = 'r';
	if (!((*spec_det)->flag_dash))
	{
		if (((*spec_det)->flag_0) && ((*spec_det)->flag_grid)
			&& (*spec_det)->prec <= 0 && n != 0)
			if_grid(spec_det, &flag);
		if (((*spec_det)->flag_grid) && n != 0)
			*len += 2;
		if (((*spec_det)->width) > *len + len_num)
			ft_print_symbols(((*spec_det)->flag_0) && (*spec_det)->prec < 0
			? '0' : ' ', (*spec_det)->width - *len - len_num);
		if (((*spec_det)->flag_grid) && flag != '-' && n != 0)
			if_grid(spec_det, &flag);
		if (len_num)
			ft_print_symbols('0', len_num);
		ft_putnbr_hex(n, base, 16);
	}
	else
		manage_fl(n, spec_det, len, len_num);
}

void		print_x(va_list arg_list, t_spec **spec_det)
{
	unsigned long long	n;
	int					len;
	int					len_num;

	n = if_modifier_ux(arg_list, spec_det);
	len = ft_numlen_uns((unsigned long long)n, 16);
	len_num = (*spec_det)->prec > len ? (*spec_det)->prec - (int)len : 0;
	if (n == 0 && (*spec_det)->prec == 0)
		zero_zeroprec((*spec_det)->width, &len);
	else
		manage_fla(n, spec_det, &len, len_num);
	if (((*spec_det)->width) > len + len_num)
		(*spec_det)->length += (*spec_det)->width;
	else
		(*spec_det)->length += len + len_num;
}
