/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ocp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:54:14 by pavaucha          #+#    #+#             */
/*   Updated: 2019/03/06 14:54:15 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse.h"
#include "libft.h"

char		*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*new_s;
	void	*s;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new_s = ft_strnew(len)))
		return (NULL);
	ft_strcpy(new_s, (char*)s1);
	ft_strcat(new_s, (char*)s2);
	ft_strdel((void*)&s1);
	ft_strdel((void*)&s2);
	return (new_s);
}

static char	*ft_take_ocp(t_champ champ, int *i)
{
	char	*ocp;
	char	*tmp;

	if ((ocp = ft_itoa_base(champ.instructions[*i], 2, 1)) == NULL)
		return (NULL);
	if (ft_strlen(ocp) < 8)
	{
		tmp = ocp;
		if ((ocp = ft_strjoin("0", ocp)) == NULL)
			return (NULL);
		ft_strdel(&tmp);
	}
	return (ocp);
}

int			get_ocp(int fd, t_champ champ, int *i)
{
	char	*ocp;
	int		j;

	if (complete_ocp(champ, fd, i) == 1)
		return (1);
	if ((ocp = ft_take_ocp(champ, i)) == NULL)
		return (-1);
	*i = *i + 1;
	j = write_instruction(champ, ocp, i, fd);
	ft_strdel(&ocp);
	return (j);
}
