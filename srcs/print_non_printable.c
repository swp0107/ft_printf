/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_non_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:08:43 by thomkim           #+#    #+#             */
/*   Updated: 2018/06/19 15:36:07 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_twentyone_to_thirtyone(t_pf_env *e, char c)
{
	if (c == 21)
		write(e->fd, "[NAK]", 5);
	else if (c == 22)
		write(e->fd, "[SYN]", 5);
	else if (c == 23)
		write(e->fd, "[ETB]", 5);
	else if (c == 24)
		write(e->fd, "[CAN]", 5);
	else if (c == 25)
		write(e->fd, "[EM]", 4);
	else if (c == 26)
		write(e->fd, "[SUB]", 5);
	else if (c == 27)
		write(e->fd, "[ESC]", 5);
	else if (c == 28)
		write(e->fd, "[FS]", 4);
	else if (c == 29)
		write(e->fd, "[GS]", 4);
	else if (c == 30)
		write(e->fd, "[RS]", 4);
	else if (c == 31)
		write(e->fd, "[US]", 4);
}

void	print_eleven_to_twenty(t_pf_env *e, char c)
{
	if (c == 11)
		write(e->fd, "[VT]", 5);
	else if (c == 12)
		write(e->fd, "[FF]", 4);
	else if (c == 13)
		write(e->fd, "[CR]", 4);
	else if (c == 14)
		write(e->fd, "[SO]", 4);
	else if (c == 15)
		write(e->fd, "[SI]", 4);
	else if (c == 16)
		write(e->fd, "[DLE]", 5);
	else if (c == 17)
		write(e->fd, "[DC1]", 5);
	else if (c == 18)
		write(e->fd, "[DC2]", 5);
	else if (c == 19)
		write(e->fd, "[DC3]", 5);
	else if (c == 20)
		write(e->fd, "[DC4]", 5);
}

void	print_zero_to_ten(t_pf_env *e, char c)
{
	if (c == 0)
		write(e->fd, "[NUL]", 5);
	else if (c == 1)
		write(e->fd, "[SOH]", 5);
	else if (c == 2)
		write(e->fd, "[STX]", 5);
	else if (c == 3)
		write(e->fd, "[ETX]", 5);
	else if (c == 4)
		write(e->fd, "[EOT]", 5);
	else if (c == 5)
		write(e->fd, "[ENQ]", 5);
	else if (c == 6)
		write(e->fd, "[ACK]", 5);
	else if (c == 7)
		write(e->fd, "[BEL]", 5);
	else if (c == 8)
		write(e->fd, "[BS]", 4);
	else if (c == 9)
		write(e->fd, "[TAB]", 5);
	else if (c == 10)
		write(e->fd, "[LF]", 4);
}

void	spec_non_printable(t_pf_env *e)
{
	char	*tmp;
	int		i;

	init_str_arg(e, &tmp);
	i = -1;
	while (++i < e->flag.width)
	{
		if (tmp[i] >= 0 && tmp[i] <= 10)
			print_zero_to_ten(e, tmp[i]);
		else if (tmp[i] >= 11 && tmp[i] <= 20)
			print_eleven_to_twenty(e, tmp[i]);
		else if (tmp[i] >= 21 && tmp[i] <= 31)
			print_twentyone_to_thirtyone(e, tmp[i]);
		++e->ret;
	}
	++e->i;
}
