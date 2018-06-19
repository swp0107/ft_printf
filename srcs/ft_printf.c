/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 10:14:02 by thomkim           #+#    #+#             */
/*   Updated: 2018/06/19 15:34:38 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flag(t_pf_flag *flag)
{
	flag->sp = 0;
	flag->plus = 0;
	flag->neg = 0;
	flag->minus = 0;
	flag->hash = 0;
	flag->zero = 0;
	flag->prec = -1;
	flag->width = 0;
}

void	print_conversion(const char *restrict fmt, t_pf_env *e)
{
	++e->i;
	get_tag(fmt, e);
	get_flag(fmt, e);
	get_spec(fmt, e);
}

int		ft_printf(const char *restrict fmt, ...)
{
	t_pf_env	e;

	ft_bzero(&e, sizeof(e));
	e.fd = 1;
	va_start(e.ap[0], fmt);
	va_copy(e.ap[1], e.ap[0]);
	while (fmt[e.i])
	{
		if (fmt[e.i] == '{')
			check_settings(fmt, &e);
		else if (fmt[e.i] == '%' && fmt[e.i + 1] != '%')
			print_conversion(fmt, &e);
		else if (fmt[e.i] == '%' && fmt[e.i + 1] == '%')
		{
			e.ret += write(e.fd, "%", 1);
			e.i += 2;
		}
		else
			e.ret += write(e.fd, &fmt[e.i++], 1);
	}
	va_end(e.ap[0]);
	return (e.ret);
}
