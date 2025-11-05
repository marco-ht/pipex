/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 04:28:04 by mpierant          #+#    #+#             */
/*   Updated: 2025/03/29 03:15:43 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"
#include "../header/pipex_bonus.h"

void	ft_cmd_last(char *outfile, char *cmd_last, int out, char **env)
{
	int	outfd;

	if (out == 1)
		outfd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		outfd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (outfd < 0)
		exit(1);
	dup2(outfd, STDOUT_FILENO);
	close(outfd);
	ft_exec_bonus(cmd_last, env);
}

void	ft_cmd_first(char *infile, char *cmd_first, int *fd, char **env)
{
	int	infd;

	infd = open(infile, O_RDONLY);
	if (infd < 0)
		exit(1);
	dup2(infd, STDIN_FILENO);
	close(infd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	ft_exec_bonus(cmd_first, env);
}

void	ft_cmd_i(char *cmd_i, int *pid_j, char **env)
{
	int	fd[2];

	if (pipe(fd) == -1)
		ft_error_pipe();
	*pid_j = fork();
	if (*pid_j == -1)
		ft_fork_error();
	if (*pid_j == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_exec_bonus(cmd_i, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void	ft_child(int *fd, char *limiter)
{
	char	*line;

	close(fd[0]);
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			close(fd[1]);
			exit(0);
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(fd[1]);
}

int	ft_here_doc(char *limiter, int argc)
{
	int	fd[2];
	int	pid;

	if (argc < 6)
		ft_error_here_doc();
	if (pipe(fd) == -1)
		ft_error_pipe();
	pid = fork();
	if (pid == -1)
		ft_fork_error();
	if (pid == 0)
	{
		ft_child(fd, limiter);
		return (2);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		wait(NULL);
		return (2);
	}
}
