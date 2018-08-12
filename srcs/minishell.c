#include "minishell.h"

int			is_builtin(char *line)
{
	int		i;
	int count;
	static const t_built builtins[6] = {
		{"echo", &ms_echo}, {"cd", &ms_cd}, {"setenv", &ms_setenv},  {"unsetenv", &ms_unsetenv}, {"env", &ms_env}, {"exit", &ms_exit}};

	count = 0;
	i = 0;
	while(ft_isspace(&line[i]))
		i++;
	while (count < 6)
	{
		if (is_stringok(builtins[count].name, &line[i]))
		{
			while(line[i] && !ft_isspace(&line[i]))
				i++;
			builtins[count].function(&line[i]);
			return(0);
		}
		count++;
	}
	return(1);
}

char		*is_access(char *path, t_exec *exec)
{
	static char	*kpath = NULL;
	static int	len3 = 0;
	int			len1;
	int			i;
	int			j;

	i = 0;
	while(ft_isspace(&exec->line[(j = i)]))
		i++;
	while(exec->line[j] && !ft_isspace(&exec->line[j]))
		j++;
	
	exec->line[j] = 0;
	len1 = ft_strlen(path) + 2;
	len1 += ft_strlen(&exec->line[i]);
	if (len1 > len3)
	{
		if (kpath)
			ft_strdel(&kpath);
		kpath = malloc((len3 = (len1 * 4)));
	}
	ft_bzero(kpath, len3);
	ft_strcat(kpath, path);
	ft_strcat(kpath, "/");
	ft_strcat(kpath, &exec->line[i]);
	return (access(kpath, X_OK) ? NULL : ft_strdup(kpath));
}

int			is_exec(t_exec *exec, char **env)
{
	int		i;
	int		j;
	char **splited;

	i = 0;
	splited = NULL;
	if (ft_strlen(exec->line))
	while(env[i])
	{
		if ((j = is_stringok("PATH=", env[i])))
		{
			splited = ft_strsplit(&env[i][j], ':');
			exec->av = ft_strsplit(exec->line, ' ');
			j = -1;
			while (splited[++j])
				if ((exec->path = is_access(splited[j], exec)))
				{
					free_split(splited);
					return (ft_printf("je suis ici %s \n", exec->path));
				}
			free_split(splited);
		}
		i++;
	}
	return (0);
}

int			line_ok(t_exec *exec, char **env)
{
	pid_t pid;

	pid = 0;
	if ((is_builtin(exec->line)))
	{
		if (is_exec(exec, env))
		{
			if ((pid = fork()) == -1)
				ft_printf("caca le fork\n");
			if (!pid)
				execve(exec->path, exec->av, env);
			else 
				waitpid(-1, &exec->wstatut, 0);
			check_status(exec->wstatut);
		}
	}
	return(0);
}

int			handle_process(char **env, t_exec *exec)
{
	while (1)
	{
		if (get_next_line(0, &exec->line) < 0)
			return (-1);
		line_ok(exec, env);
		free_exec(exec);
	}
	return(0);
}
