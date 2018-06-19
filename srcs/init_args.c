/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 17:08:49 by thomkim           #+#    #+#             */
/*   Updated: 2018/06/19 15:35:50 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_long_double(t_pf_env *e, long double *tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], long double);
		return ;
	}
	*tmp = va_arg(e->ap[0], long double);
}

void	init_prec_arg(t_pf_env *e, double *tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], double);
		return ;
	}
	*tmp = va_arg(e->ap[0], double);
}

void	init_int_arg(t_pf_env *e, long *tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], long);
		return ;
	}
	*tmp = va_arg(e->ap[0], long);
}

void	init_str_arg(t_pf_env *e, char **tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], char *);
		return ;
	}
	*tmp = va_arg(e->ap[0], char *);
}

void	init_char_arg(t_pf_env *e, int *tmp)
{
	if (e->tag.tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag.pos >= 0)
			*tmp = va_arg(e->ap[0], int);
		return ;
	}
	*tmp = va_arg(e->ap[0], int);
}
