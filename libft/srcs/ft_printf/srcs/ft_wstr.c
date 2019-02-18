/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:06:09 by lezhang           #+#    #+#             */
/*   Updated: 2018/01/05 15:33:27 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_wstr(wchar_t *wch, int width)
{
	int		i;
	int		len;
	int		temp;

	i = 0;
	len = 0;
	while (wch[i] != '\0' && i < width)
	{
		temp = ft_wchar(wch[i]);
		if (temp == -1)
			return (-1);
		else
			len += temp;
		i++;
	}
	return (len);
}
