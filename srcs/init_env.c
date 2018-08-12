#include "minishell.h"

char		**get_env(char **envp)
{
	char **env;
	int i;

	env = 0;
	i = 0;
	while (envp[i])
		i++;
	if (!(env = ft_memalloc(sizeof(char**) * (i + 1))))
		return (0);
	ft_printf("%d\n", i);
	while (--i > -1)
	{
		if (!(env[i] = malloc((ft_strlen(envp[i]) + 1))))
			return (0);
		ft_memcpy(env[i], envp[i], ft_strlen(envp[i]) + 1);
	}
	return (env);
}
