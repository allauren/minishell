#ifndef MINISHELL_H
#define MINISHELL_H

#include "printf.h"

typedef	struct		s_built
{
	char *name;
	int (*function)(char*);
}					t_built;

typedef	struct		s_exec
{
	char *line;
	char *path;
	char **av;
	int wstatut;
}					t_exec;

int		error_display(void);
void	free_exec(t_exec *exec);
int			is_builtin(char *line);
char	**get_env(char **envp);
void	print_env(char **env);
int		is_stringok(char *str1, char *str2);
int		handle_process(char **env, t_exec *exec);
int		ft_isspace(char *str);

int		ms_exit(char *params);
int		ms_env(char *params);
int		ms_unsetenv(char *params);
int		ms_cd(char *params);
int		ms_echo(char *params);
int		ms_setenv(char *params);
#endif
