/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 03:34:03 by mpierant          #+#    #+#             */
/*   Updated: 2025/03/27 22:43:28 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	check_status(int pid1, int pid2)
{
	int	status;

	waitpid(pid1, NULL, 0);
	if (waitpid(pid2, &status, 0) == -1)
		return (1);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (WEXITSTATUS(status));
	return (0);
}

void	ft_exec(char *cmd, char **env)
{
	char	**args;

	args = ft_split(cmd, " ");
	execve(find_path(args, env), args, env);
	ft_free_args(args);
	exit(127);
}

void	ft_cmd2(char *outfile, char *cmd2, int *fd, char **env)
{
	int	outfd;

	if (cmd2 == NULL || *cmd2 == '\0')
		return (perror("Invalid command"));
	outfd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfd < 0)
		exit(1);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	dup2(outfd, STDOUT_FILENO);
	close(outfd);
	ft_exec(cmd2, env);
}

void	ft_cmd1(char *infile, char *cmd1, int *fd, char **env)
{
	int	infd;

	if (cmd1 == NULL || *cmd1 == '\0')
		return (perror("Invalid command"));
	infd = open(infile, O_RDONLY);
	if (infd < 0)
		exit(1);
	dup2(infd, STDIN_FILENO);
	close(infd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	ft_exec(cmd1, env);
}

int	main(int argc, char **argv, char **env)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		return (perror("wrong arguments number"), 1);
	if (pipe(fd) < 0)
		return (perror("pipe error"), 1);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("fork error"), 1);
	if (pid1 == 0)
		ft_cmd1(argv[1], argv[2], fd, env);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("fork error"), 1);
	if (pid2 == 0)
		ft_cmd2(argv[4], argv[3], fd, env);
	close(fd[0]);
	close(fd[1]);
	return (check_status(pid1, pid2));
}
// se argc != 5 execve (pipex_bonus.c)