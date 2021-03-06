/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_blank.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 07:03:57 by mavui             #+#    #+#             */
/*   Updated: 2019/02/26 15:48:59 by mavui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlen_blank(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*(s + i) != '\0' && ft_isblank(*(s + i)) == 0)
		i++;
	return (i);
}
