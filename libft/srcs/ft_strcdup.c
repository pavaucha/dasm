/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 07:03:49 by mavui             #+#    #+#             */
/*   Updated: 2019/02/11 07:03:50 by mavui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strcdup(const char *s1, char c)
{
	int		i;
	int		len;
	char	*s2;

	i = 0;
	len = 0;
	while (*(s1 + len) != '\0' && *(s1 + i) != c)
		len++;
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (*(s1 + i) != '\0' && *(s1 + i) != c)
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	while (*(s1 + i) != '\0')
		*(s2 + i++) = '\0';
	return (s2);
}
