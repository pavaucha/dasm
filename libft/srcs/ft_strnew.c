/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:18:47 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/08 10:19:03 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((str = (char*)ft_memalloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (i < size)
	{
		*(str + i) = '\0';
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
