/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:06:52 by mavui             #+#    #+#             */
/*   Updated: 2019/02/26 16:06:54 by mavui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_wstr_len(wchar_t *wch, int width)
{
	int		i;
	int		len;
	int		temp;

	i = 0;
	len = 0;
	while (wch[i] != '\0' && i < width)
	{
		temp = ft_wchar_len(wch[i]);
		if (temp == -1)
			return (-1);
		else
			len += temp;
		i++;
	}
	return (len);
}
