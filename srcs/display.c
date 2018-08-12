#include "minishell.h"

void	print_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		ft_printf("%s\n", env[i]);
	}
}
