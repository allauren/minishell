#include "minishell.h"

int		ft_isspace(char *str)
{
	if (str && *str && (*str == ' ' || *str == '\n' || *str == '\t'))
		return (1);
	return (0);
}

int		is_stringok(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i])
	{
		if (!str2[i] || str1[i] != str2[i])
			return (0);
		i++;
	}
	return (i);
}

void	free_split(char **split)
{
	int i;

	if (!split)
		return;
	i = -1;
	while (split[++i])
		ft_strdel(&split[i]);
	ft_memdel((void**)&split);
}

void	print_split(char **split)
{
	int i;

	i = -1;
	while (split[++i])
		ft_printf("je suis le truc %s\n", split[i]);
}

void	free_exec(t_exec *exec)
{
	ft_strdel(&exec->line);
	ft_strdel(&exec->path);
	free_split(exec->av);
	ft_bzero(exec, sizeof(t_exec));
}

void		check_status(int wstatus)
{
	if(WIFEXITED(wstatus))
	{
		ft_printf("executed right ok\n");
	}
    /*   if (WEXITSTATUS(wstatus))
              returns  the  exit  status  of  the  child.  This consists of the least significant 8 bits of the status argument that the child specified in a call to
              exit(3) or _exit(2) or as the argument for a return statement in main().  This macro should be employed only if WIFEXITED returned true.

       WIFSIGNALED(wstatus)
              returns true if the child process was terminated by a signal.

       WTERMSIG(wstatus)
              returns the number of the signal that caused the child process to terminate.  This macro should be employed only if WIFSIGNALED returned true.

       WCOREDUMP(wstatus)
              returns true if the child produced a core dump.  This macro should be employed only if WIFSIGNALED returned true.

              This macro is not specified in POSIX.1-2001 and is not available on some UNIX implementations (e.g., AIX, SunOS).  Therefore, enclose  its  use  inside
              #ifdef WCOREDUMP ... #endif.

       WIFSTOPPED(wstatus)
              returns  true if the child process was stopped by delivery of a signal; this is possible only if the call was done using WUNTRACED or when the child is
              being traced (see ptrace(2)).

       WSTOPSIG(wstatus)
              returns the number of the signal which caused the child to stop.  This macro should be employed only if WIFSTOPPED returned true.

       WIFCONTINUED(wstatus)
              (since Linux 2.6.10) returns true if the child process was resumed by delivery of SIGCONT.
*/
}
