/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 04:28:42 by mpierant          #+#    #+#             */
/*   Updated: 2025/03/28 04:19:47 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

char	*my_getenv(char **env, char *word)
{
	int	word_len;
	int	i;

	word_len = ft_strlen(word);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], word, word_len) == 0)
			return (env[i] + word_len);
		i++;
	}
	perror("PATH not found in environment");
	exit(1);
}

char	*find_path(char **cmd, char **env)
{
	char	*path_str;
	char	*cmd_str;
	char	**paths;
	int		i;

	path_str = my_getenv(env, "PATH=");
	paths = ft_split(path_str, ":");
	i = 0;
	while (paths[i])
	{
		path_str = ft_strjoin(paths[i], "/");
		cmd_str = ft_strjoin(path_str, cmd[0]);
		free(path_str);
		if (access(cmd_str, F_OK | X_OK) == 0)
		{
			ft_free_args(paths);
			return (cmd_str);
		}
		free(cmd_str);
		i++;
	}
	ft_free_args(paths);
	ft_free_args(cmd);
	perror("Command not found");
	exit(127);
}
