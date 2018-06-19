/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 17:43:05 by thomkim           #+#    #+#             */
/*   Updated: 2018/06/19 15:36:25 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_wchar(t_pf_env *e, char c)
{
	write(e->fd, &c, 1);
}

void	put_wc(t_pf_env *e, wchar_t c)
{
	if (c <= 0x7F)
		put_wchar(e, c);
	else if (c <= 0x7FF)
	{
		put_wchar(e, (c >> 6) + 0xC0);
		put_wchar(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		put_wchar(e, ((c >> 12) + 0xE0));
		put_wchar(e, ((c >> 6) & 0x3F) + 0x80);
		put_wchar(e, (c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		put_wchar(e, (c >> 18) + 0xF0);
		put_wchar(e, ((c >> 12) & 0x3F) + 0x80);
		put_wchar(e, ((c >> 6) & 0x3F) + 0x80);
		put_wchar(e, (c & 0x3F) + 0x80);
	}
	++e->ret;
}

void	print_wchar_minus(t_pf_env *e, wchar_t wc)
{
	put_wc(e, wc);
	while (e->flag.width-- > 1)
		e->ret += write(e->fd, " ", 1);
}

void	print_wchar(t_pf_env *e, wchar_t wc)
{
	if (e->flag.minus)
		print_wchar_minus(e, wc);
	else
	{
		while (e->flag.width-- > 1)
			e->ret += (e->flag.zero ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
		put_wc(e, wc);
	}
	++e->i;
}
