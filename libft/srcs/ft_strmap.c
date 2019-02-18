/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:12:50 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:47:05 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (*(s + len) != '\0')
		len++;
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		*(str + i) = (*f)(*(s + i));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
