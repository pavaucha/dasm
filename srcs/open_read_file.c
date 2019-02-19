#include "reverse.h"

static int		ft_error(int i)
{
	ft_printf("Erreur dans le fichier %i\n", i);
	return (-1);
}


static int		bytes_to_int(uint8_t *bytes, unsigned *integer)
{
	unsigned 		i;
	unsigned		j;

	i = 0;
	j = 0;
	i = (bytes[0] | i) << 8;
	i = bytes[1] | i;
	j = (bytes[2] | j | i) << 8;
	j = bytes[3] | j;
	*integer = (i | j);
	if (*integer > CHAMP_MAX_SIZE)
		return (ft_error(1));
	return (1);
}

static int		check_magic(int fd, t_champ *champ)
{
	static uint8_t	magic[4] = MAGIC;
	ssize_t			ret;

	if ((ret = read(fd, champ->magic, 4)) != 4)
		return (ft_error(1));
	else if (ft_memcmp(champ->magic, magic, 4))
		return (ft_error(1));
	else
		return (0);
}

static int			complete_meta(int fd, t_champ *champ)
{
	ssize_t			ret;
	uint8_t			bytes[4];
	char			*buffer[200];

	if ((ret = read(fd, champ->name, PROG_NAME_LEN)) != PROG_NAME_LEN)
		return (ft_error(1));
	else if ((ret = read(fd, bytes, 4)) != 4)
		return (ft_error(2));
	else if ((ret = read(fd, bytes, 4)) != 4)
		return (ft_error(3));
	else if (bytes_to_int(bytes, &(champ->len)) == -1)
		return (ft_error(4));
	else if ((ret = read(fd, champ->comment, COMMENT_LEN)) != COMMENT_LEN)
		return (ft_error(5));
	else if ((ret = read(fd, bytes, 4)) != 4)
		return (ft_error(6));
	else if ((ret = read(fd, champ->instructions, champ->len)) != champ->len)
			return (ft_error(7));
	else if (read(fd, buffer, 1) != 0)
		return (ft_error(8));
	else
	{
		return (1);

	}
}

static int		complete(int fd, t_champ *champ)
{
	int 		ret;

	if ((ret = check_magic(fd, champ)) != 0)
		return (ret);
	else if ((ret = complete_meta(fd, champ)) != 0)
		return (ret);
	else
		return (1);
}

int					open_read_file(char *name, t_champ *champ)
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
