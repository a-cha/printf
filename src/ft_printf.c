/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadolph <sadolph@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:16:21 by sadolph           #+#    #+#             */
/*   Updated: 2020/10/13 15:11:49 by sadolph          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Here is the part of program that deals with two things:
** 1. Find specificator and print all before it
** 2. Parse specificator: analyze it and write down all details into structure
*/

static void	if_type_modifier(char *s, t_spec **spec_det)
{
	int i;

	i = 0;
	if (*s == 'l')
	{
		if (*(s + 1) == 'l')
			(*spec_det)->modifier = "ll";
		else
			(*spec_det)->modifier = "l";
	}
	else if (*s == 'h')
	{
		if (*(s + 1) == 'h')
			(*spec_det)->modifier = "hh";
		else
			(*spec_det)->modifier = "h";
	}
	while ((ft_strchr("lh", s[i])))
		i++;
	(*spec_det)->type = s[i];
}

static void	if_width_precision(char *s, t_spec **spec_det, char flag)
{
	if (*s == '*')
	{
		if (flag == 'w')
			(*spec_det)->if_width_star = 'y';
		else
			(*spec_det)->if_precision_star = 'y';
	}
	else if ((ft_isdigit(*s)))
	{
		if (flag == 'w')
			(*spec_det)->width = ft_atoi(s);
		else
			(*spec_det)->prec = ft_atoi(s);
	}
}

static void	if_flags_type(char *s, t_spec **spec_det)
{
	while (!(ft_isdigit_wo0(*s)) && !(ft_strchr(".*cspdiuxX%nlh", *s)))
	{
		if (*s == '-')
			(*spec_det)->flag_dash = 'y';
		else if (*s == '0')
			(*spec_det)->flag_0 = 'y';
		else if (*s == '#')
			(*spec_det)->flag_grid = 'y';
		else if (*s == ' ' || *s == '+')
			(*spec_det)->flag_sp_or_pl = *s;
		s++;
	}
	if_width_precision(s, spec_det, 'w');
	while (*s == '*' || (ft_isdigit(*s)))
		s++;
	if (*s == '.')
	{
		(*spec_det)->flag_dote = 'y';
		if_width_precision(++s, spec_det, 'p');
		while (*s == '*' || (ft_isdigit(*s)))
			s++;
	}
	if_type_modifier(s, spec_det);
}

static char	*find_spec(char *s, t_spec **lol)
{
	size_t l;
	size_t i;

	l = 0;
	while (s[l] && s[l] != '%')
		l++;
	write(1, s, l);
	(*lol)->length += l;
	if (*(s + l) == '%')
		if_flags_type(s + l + 1, lol);
	if (!s[l])
		return (s + l);
	i = 0;
	while (!(ft_strchr("cspdiuxX%n", s[l + 1 + i])))
		i++;
	return (s + l + i + 2);
}

int			ft_printf(const char *s, ...)
{
	t_spec	*spec_det;
	char	*str;
	va_list arg_list;
	size_t	res;

	if (!(spec_det = ft_lstnew_printf()))
		return (-1);
	va_start(arg_list, s);
	str = (char *)s;
	res = 0;
	while (*(str = find_spec(str, &spec_det)))
	{
		print_arg(arg_list, spec_det, res);
		res += spec_det->length;
		ft_struct_zero(&spec_det);
	}
	print_arg(arg_list, spec_det, res);
	res += spec_det->length;
	free(spec_det);
	spec_det = NULL;
	va_end(arg_list);
	return (res);
}
