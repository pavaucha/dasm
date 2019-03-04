/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:32:38 by pavaucha          #+#    #+#             */
/*   Updated: 2019/03/04 12:32:44 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse.h"

static int		ft_real_cor(char *name)
{
	int		i;

	i = ft_strlen(name);
	if (ft_strcmp((name + i - 4), ".cor") == 0)
		return (1);
	return (0);
}

static int		open_read_file(char *name, t_champ *champ)
{
	int			fd;

	if ((fd = open(name, O_RDONLY)) <= 0)
		return (-1);
	if (complete(fd, champ) != 0)
	{
		close(fd);
		return (-1);
    }
	return (1);
}

int				parsing_champ(char *name, t_champ *champ)
{
    if (ft_real_cor(name) == 0)
	{
		ft_printf("<%s> is not a .cor\n", name);
		return (-1);
	}
	if (open_read_file(name, champ) == -1)
		return (-1);
    return (1);
}
