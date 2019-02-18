/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:16:24 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 13:23:47 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		same;

	i = 0;
	same = 1;
	if (n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (*(s1 + 0) != *(s2 + 0))
		same = 0;
	while ((i < n) && *(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;
	if (i == n)
		i--;
	if (*(s1 + i) != *(s2 + i))
		same = 0;
	return (same);
}
