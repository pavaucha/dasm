/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:59:52 by lezhang           #+#    #+#             */
/*   Updated: 2018/01/09 10:12:48 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		ft_o_len(t_flags *flags, int len)
{
	if (flags->minus == 1 || (flags->point == 1 && flags->preci > -1))
		flags->zero = 0;
	if (flags->preci < len)
		flags->preci = 0;
	else
		len = flags->preci;
	if (flags->width < len)
		flags->width = 0;
	else
		len = flags->width;
	if (flags->preci != 0 || (flags->width != 0 && flags->zero == 1))
		flags->sharp = 0;
	if (flags->sharp == 1 && flags->preci == 0 && flags->width == 0)
		len++;
	return (len);
}

int				ft_o(const char **format, va_list ap, t_flags flags)
{
	uintmax_t	val;
	int			len[2];
	char		*s;

	if (**format == 'O')
		flags.size = l;
	val = ft_get_uint_val(ap, flags);
	len[1] = ft_num_len(val, 8);
	if (val == 0 && ((flags.preci == 0 && flags.point == 1) ||
				flags.sharp == 1))
		len[1] = 0;
	len[0] = ft_o_len(&flags, len[1]);
	if ((s = (char*)malloc(sizeof(char) * (len[0] + 1))) == NULL)
		return (-1);
	s[len[0]] = '\0';
	ft_o2(flags, &s, len, val);
	ft_putstr(s);
	ft_strdel(&s);
	return (len[0]);
}
