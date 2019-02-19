#include "reverse.h"

static int		ft_real_cor(char *name)
{
	int		i;

	i = ft_strlen(name);
	if (ft_strcmp((name + i - 4), ".cor") == 0)
		return (1);
	return (0);
}


int				parsing_champ(char *name, t_champ *champ)
{
    if (ft_real_cor(name) == 0)
	{
		ft_printf("<%s> is not a .cor\n", name);
		return (0);
	}
	if (open_read_file(name, champ) == -1)
		return (0);
    return (1);
}