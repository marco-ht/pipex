/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:17:38 by mpierant          #+#    #+#             */
/*   Updated: 2025/03/28 05:18:56 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"
#include "../header/pipex_bonus.h"

int	check_status_bonus(int j, int *pid)
{
	int	i;
	int	status;

	i = 0;
	while (i < j)
	{
		if (waitpid(pid[i], &status, 0) == -1)
			return (1);
		i++;
	}
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (WEXITSTATUS(status));
	return (0);
}

void	ft_exec_bonus(char *cmd, char **env)
{
	char	**args;

	if (cmd == NULL || *cmd == '\0')
		return (perror("Invalid command"));
	args = ft_split(cmd, " ");
	execve(find_path(args, env), args, env);
	ft_free_args(args);
	exit(127);
}

int	ft_start(char **argv, int *pid_j, char **env)
{
	int	fd[2];

	if (pipe(fd) < 0)
		ft_error_pipe();
	*pid_j = fork();
	if (*pid_j == -1)
		ft_fork_error();
	if (*pid_j == 0)
		ft_cmd_first(argv[1], argv[2], fd, env);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	int	j;
	int	i;
	int	pid[1000];
	int	out;

	i = 3;
	j = 0;
	if (argc < 5)
		return (perror("wrong arguments number"), 1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		out = ft_here_doc(argv[2], argc);
	else
		out = ft_start(argv, &pid[j++], env);
	while (i < argc - 2)
		ft_cmd_i(argv[i++], &pid[j++], env);
	pid[j] = fork();
	if (pid[j] == -1)
		ft_fork_error();
	if (pid[j++] == 0)
		ft_cmd_last(argv[argc - 1], argv[argc - 2], out, env);
	close(STDIN_FILENO);
	return (check_status_bonus(j, pid));
}
