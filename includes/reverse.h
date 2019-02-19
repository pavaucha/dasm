#ifndef REVERSE_H
# define REVERSE_H

# include "libft.h"
# include "ft_printf.h"
# include <stdint.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define IND_SIZE			2
# define REG_SIZE			4
# define DIR_SIZE			REG_SIZE

# define REG_CODE			1
# define DIR_CODE			2
# define IND_CODE			3

# define MAX_ARGS_NUMBER	4
# define MAX_PLAYERS		4
# define MEM_SIZE			4*1024
# define IDX_MOD			MEM_SIZE / 8
# define CHAMP_MAX_SIZE		MEM_SIZE / 6

# define REG_NUMBER			16

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		50
# define NBR_LIVE			21
# define MAX_CHECKS			10

# define T_REG				1
# define T_DIR				2
# define T_IND				4
# define T_LAB				8

# define PROG_NAME_LEN		128
# define COMMENT_LEN		2048
# define COREWAR_EXEC_MAGIC	0xea83f3
# define MAGIC				{0x00, 0xea, 0x83, 0xf3}

# define REG_PC 			0
# define REG_CF 			17
# define MAX_REG 			18


typedef	struct		s_champ
{
	uint32_t	len;
	uint8_t		magic[4];
	uint8_t		instructions[CHAMP_MAX_SIZE];
	uint8_t		name[PROG_NAME_LEN + 1];
	uint8_t		comment[COMMENT_LEN + 1];
}					t_champ;

int         main(int ac, char **av);
int         parsing_champ(char *name, t_champ *champ);
int			open_read_file(char *name, t_champ *champ);

#endif 