/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:27:49 by sadolph           #+#    #+#             */
/*   Updated: 2020/11/21 12:16:10 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "libft.h"

typedef struct		s_spec
{
	char			flag_dash;
	char			flag_0;
	char			flag_dote;
	char			flag_sp_or_pl;
	char			flag_grid;
	char			if_width_star;
	int				width;
	char			if_precision_star;
	int				prec;
	char			*modifier;
	char			type;
	size_t			length;
}					t_spec;

int					ft_printf(const char *s, ...);
void				print_arg(va_list arg_list, t_spec *spec_det, size_t res);
void				print_c(va_list arg_list, t_spec **spec_det);
void				print_s(va_list arg_list, t_spec **spec_det);
void				print_u(va_list arg_list, t_spec **spec_det);
void				print_di(va_list arg_list, t_spec **spec_det);
void				print_x(va_list arg_list, t_spec **spec_det);
void				print_p(va_list arg_list, t_spec **spec_det);
void				print_perc(t_spec **spec_det);
long long			if_modifier_di(va_list arg_list, t_spec **spec_det);
unsigned long long	if_modifier_ux(va_list arg_list, t_spec **spec_det);
long long			*if_modifier_n(va_list arg_list, t_spec **spec_det);
wchar_t				if_modifier_c(va_list arg_list, t_spec **spec_det);
wchar_t				*if_modifier_s(va_list arg_list, t_spec **spec_det,
																size_t *len);
int					ft_isdigit_wo0(int c);
void				ft_print_symbols(char symbol, int length);
void				ft_putnbr_wo_sign(long long n);
t_spec				*ft_lstnew_printf(void);
void				ft_struct_zero(t_spec **spec_det);

#endif
