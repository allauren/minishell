#include "minishell.h"


int main(int ac, char **av, char **envp)
{
	char **env;
	t_exec exec;

	ft_bzero(&exec, sizeof(t_exec));
	if (!(env = get_env(envp)))
		return(error_display());
	if (handle_process(env, &exec))
		return(error_display());
	return 0;
}
