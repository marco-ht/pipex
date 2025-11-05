/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 05:04:45 by mpierant          #+#    #+#             */
/*   Updated: 2025/03/28 05:01:51 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../bonus/gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char *str, char *charset);
char	*find_path(char **cmd, char **env);
void	ft_free_args(char **args);
int		ft_alloc(char **matrix, int j, int dim);
char	*my_getenv(char **env, char *word);

#endif
