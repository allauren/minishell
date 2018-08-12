#include "minishell.h"

int		ms_exit(char *params)
{
	exit();
}

int		ms_env(char *params)
{
return (ft_printf("%s\n", params));
}

int		ms_unsetenv(char *params)
{
return (ft_printf("%s\n", params));
}

int		ms_setenv(char *params)
{
return (ft_printf("%s\n", params));
}

int		ms_cd(char *params)
{
return (ft_printf("%s\n", params));
}

int		ms_echo(char *params)
{
return (ft_printf("%s\n", params));
}
