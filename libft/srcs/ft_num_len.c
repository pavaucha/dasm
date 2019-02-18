/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 10:26:20 by lezhang           #+#    #+#             */
/*   Updated: 2018/01/26 15:19:33 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_num_len(uintmax_t val, int base)
{
	int		i;

	i = 0;
	if (val == 0)
		i = 1;
	while (val > 0)
	{
		val /= base;
		i++;
	}
	return (i);
}

int		ft_num_len_int(int val)
{
	int		i;
	long	temp;

	i = 0;
	if (val == 0)
		i = 1;
	temp = val;
	if (val < 0)
		temp *= -1;
	while (val > 0)
	{
		val /= 10;
		i++;
	}
	return (i);
}
