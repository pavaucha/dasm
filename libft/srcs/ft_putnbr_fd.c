/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:05:09 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:44:24 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	save;
	char	sign;
	char	nb;

	save = n;
	sign = '-';
	if (n < 0)
	{
		save *= -1;
		write(fd, &sign, 1);
	}
	if ((save / 10) > 0)
		ft_putnbr_fd((save / 10), fd);
	nb = (save % 10) + '0';
	write(fd, &nb, 1);
}
