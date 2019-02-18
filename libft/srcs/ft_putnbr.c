/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:29:25 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:44:20 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr(int n)
{
	long	save;
	char	sign;
	char	nb;

	save = n;
	sign = '-';
	if (n < 0)
	{
		save *= -1;
		write(1, &sign, 1);
	}
	if ((save / 10) > 0)
		ft_putnbr(save / 10);
	nb = (save % 10) + '0';
	write(1, &nb, 1);
}
