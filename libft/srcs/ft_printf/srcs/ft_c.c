/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 09:58:53 by lezhang           #+#    #+#             */
/*   Updated: 2018/01/09 11:53:54 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_c_flags(t_flags *flags)
{
	if (flags->minus == 1)
		flags->zero = 0;
}

static void		ft_c_width(t_flags flags, int *len)
{
	int		i;

	i = *len;
	if (flags.minus == 1)
	{
		while (flags.width > i)
		{
			ft_putchar(' ');
			(*len)++;
			flags.width--;
		}
	}
	else if (flags.minus == 0)
	{
		while (flags.width > i)
		{
			if (flags.zero == 0)
				ft_putchar(' ');
			else if (flags.zero == 1)
				ft_putchar('0');
			(*len)++;
			flags.width--;
		}
	}
}

static int		ft_wch(va_list ap, t_flags flags)
{
	wchar_t		wch;
	int			len;

	len = 0;
	wch = (wchar_t)va_arg(ap, wint_t);
	if ((len = ft_wchar_len(wch)) == -1)
		return (-1);
	if (flags.minus == 0)
		ft_c_width(flags, &len);
	if ((ft_wchar(wch)) == -1)
		return (-1);
	if (flags.minus == 1)
		ft_c_width(flags, &len);
	return (len);
}

int				ft_c(const char **format, va_list ap, t_flags flags)
{
	char		ch;
	int			len;

	if (flags.size == l || **format == 'C')
		return (ft_wch(ap, flags));
	ft_c_flags(&flags);
	ch = (char)va_arg(ap, int);
	len = 1;
	if (flags.minus == 0)
		ft_c_width(flags, &len);
	ft_putchar(ch);
	if (flags.minus == 1)
		ft_c_width(flags, &len);
	return (len);
}
