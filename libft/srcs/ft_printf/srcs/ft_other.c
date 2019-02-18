/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:17:42 by lezhang           #+#    #+#             */
/*   Updated: 2018/01/09 11:58:07 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		ft_other_flags(t_flags *flags)
{
	if (flags->minus == 1)
		flags->zero = 0;
}

static void		ft_other_width(t_flags flags, int *len)
{
	if (flags.minus == 1)
	{
		while (flags.width > 1)
		{
			ft_putchar(' ');
			(*len)++;
			flags.width--;
		}
	}
	else if (flags.minus == 0)
	{
		while (flags.width > 1)
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

int				ft_other(const char **format, t_flags flags)
{
	int			len;

	len = 0;
	ft_other_flags(&flags);
	if (flags.minus == 0)
		ft_other_width(flags, &len);
	ft_putchar(**format);
	len++;
	if (flags.minus == 1)
		ft_other_width(flags, &len);
	return (len);
}
