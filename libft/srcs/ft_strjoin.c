/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:40:10 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/08 10:52:13 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	len_s1 = 0;
	len_s2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (*(s1 + len_s1) != '\0')
		len_s1++;
	while (*(s2 + len_s2) != '\0')
		len_s2++;
	str = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (str == NULL)
		return (NULL);
	*(str + len_s1 + len_s2) = '\0';
	while (len_s2-- > 0 && *(s2 + len_s2) != '\0')
		*(str + len_s1 + len_s2) = *(s2 + len_s2);
	while (len_s1-- > 0 && *(s1 + len_s1) != '\0')
		*(str + len_s1) = *(s1 + len_s1);
	return (str);
}
