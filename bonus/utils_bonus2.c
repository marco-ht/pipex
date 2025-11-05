/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 04:28:09 by mpierant          #+#    #+#             */
/*   Updated: 2025/03/28 05:30:26 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	ft_error_here_doc(void)
{
	perror("wrong arguments number");
	exit(1);
}

void	ft_fork_error(void)
{
	perror("fork error");
	exit(1);
}

void	ft_error_pipe(void)
{
	perror("pipe error");
	exit(1);
}
