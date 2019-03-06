#include "reverse.h"
#include "libft.h"

static char	*ft_take_ocp(t_champ champ, int *i)
{
	char			*ocp;
	char			*tmp;
	
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

int         get_ocp(int fd, t_champ champ, int *i)
{
	char			*ocp;

	if (complete_ocp(champ, fd, i) == 1)
		return (1);
	if ((ocp = ft_take_ocp(champ, i)) == NULL)
		return (-1);
    *i = *i + 1;
	return (write_instruction(champ, ocp, i, fd));
}
