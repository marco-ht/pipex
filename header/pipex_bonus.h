/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 05:04:45 by mpierant          #+#    #+#             */
/*   Updated: 2025/03/28 05:29:14 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

int		check_status_bonus(int argc, int *pid);
void	ft_error_here_doc(void);
void	ft_fork_error(void);
void	ft_error_pipe(void);
int		ft_here_doc(char *limiter, int argc);
void	ft_cmd_last(char *outfile, char *cmd_last, int out, char **env);
void	ft_cmd_first(char *infile, char *cmd_first, int *fd, char **env);
void	ft_cmd_i(char *cmd_i, int *pid_j, char **env);
void	ft_exec_bonus(char *cmd, char **env);

#endif
