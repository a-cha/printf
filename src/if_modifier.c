/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_modifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:27:22 by sadolph           #+#    #+#             */
/*   Updated: 2020/10/13 15:11:43 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			if_modifier_di(va_list arg_list, t_spec **spec_det)
{
	long long n;

	n = 0;
	if (!((*spec_det)->modifier))
		n = (long long)va_arg(arg_list, int);
	else if (!(ft_strncmp((*spec_det)->modifier, "ll", 3)))
		n = va_arg(arg_list, long long);
	else if (!(ft_strncmp((*spec_det)->modifier, "l", 2)))
		n = va_arg(arg_list, long);
	else if (!(ft_strncmp((*spec_det)->modifier, "hh", 3)))
		n = (signed char)va_arg(arg_list, int);
	else if (!(ft_strncmp((*spec_det)->modifier, "h", 2)))
		n = (short)va_arg(arg_list, int);
	return (n);
}

unsigned long long	if_modifier_ux(va_list arg_list, t_spec **spec_det)
{
	unsigned long long n;

	n = 0;
	if (!((*spec_det)->modifier))
		n = (unsigned long long)va_arg(arg_list, unsigned int);
	else if (!(ft_strncmp((*spec_det)->modifier, "ll", 3)))
		n = va_arg(arg_list, unsigned long long);
	else if (!(ft_strncmp((*spec_det)->modifier, "l", 2)))
		n = va_arg(arg_list, unsigned long);
	else if (!(ft_strncmp((*spec_det)->modifier, "hh", 3)))
		n = (unsigned char)va_arg(arg_list, unsigned int);
	else if (!(ft_strncmp((*spec_det)->modifier, "h", 2)))
		n = (unsigned short)va_arg(arg_list, unsigned int);
	return (n);
}

long long			*if_modifier_n(va_list arg_list, t_spec **spec_det)
{
	long long *n;

	n = 0;
	if (!((*spec_det)->modifier))
		n = (long long *)va_arg(arg_list, int *);
	else if (!(ft_strncmp((*spec_det)->modifier, "ll", 3)))
		n = va_arg(arg_list, long long *);
	else if (!(ft_strncmp((*spec_det)->modifier, "l", 2)))
		n = (long long *)va_arg(arg_list, long *);
	else if (!(ft_strncmp((*spec_det)->modifier, "hh", 3)))
		n = (long long *)(signed char *)va_arg(arg_list, int *);
	else if (!(ft_strncmp((*spec_det)->modifier, "h", 2)))
		n = (long long *)(short *)va_arg(arg_list, int *);
	return (n);
}

wchar_t				if_modifier_c(va_list arg_list, t_spec **spec_det)
{
	wchar_t c;

	c = 0;
	if (!((*spec_det)->modifier))
		c = (unsigned char)va_arg(arg_list, int);
	else if (!(ft_strncmp((*spec_det)->modifier, "l", 2)))
		c = (wchar_t)va_arg(arg_list, wint_t);
	return (c);
}

wchar_t				*if_modifier_s(va_list arg_list, t_spec **spec_det,
																	size_t *len)
{
	wchar_t *s;
	size_t	i;

	s = 0;
	i = 0;
	if (!((*spec_det)->modifier))
	{
		s = (wchar_t *)va_arg(arg_list, char *);
		*len = ft_strlen((const char *)s);
	}
	else if (!(ft_strncmp((*spec_det)->modifier, "l", 2)))
	{
		s = va_arg(arg_list, wchar_t *);
		if (s)
			while (s[i])
				i++;
		*len = i;
	}
	if (!s)
		*len = 6;
	return (s);
}
