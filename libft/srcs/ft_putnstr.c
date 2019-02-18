/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:21:09 by lezhang           #+#    #+#             */
/*   Updated: 2018/01/09 12:21:42 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnstr(char const *s, int len)
{
	int		i;

	i = 0;
	if (s == NULL)
		return ;
	while (*(s + i) != '\0' && i < len)
		i++;
	write(1, s, i);
}
