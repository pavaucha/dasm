#include "reverse.h"

static int		ft_real_cor(char *name)
{
	int		i;

	i = ft_strlen(name);
	if (ft_strcmp((name + i - 4), ".cor") == 0)
		return (1);
	return (0);
}


int				parsing_champ(char *champ)
{
    if (ft_real_cor(champ) == 0)
	{
		ft_printf("<%s> is not a .cor\n", champ);
		return (0);
	}
	if (ft_open_read_file(champ) == 0)
	{
		ft_printf("Can't open or read your file <%s>\n", champ);
		return (0);
	}
    return (0);
}