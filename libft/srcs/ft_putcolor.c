/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:40:39 by lezhang           #+#    #+#             */
/*   Updated: 2018/01/31 13:35:45 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

void	ft_putcolor(char *color, char *str)
{
	if (color != NULL)
	{
		ft_putstr(color);
		ft_putstr(str);
		ft_putstr(RESET_COLOR);
	}
	else
		ft_putstr(str);
}
