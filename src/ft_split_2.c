/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:27:42 by mpierant          #+#    #+#             */
/*   Updated: 2025/03/25 18:32:59 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	ft_alloc(char **matrix, int j, int dim)
{
	matrix[j] = (char *)malloc((dim + 1) * sizeof(char));
	if (matrix[j] == NULL)
	{
		j--;
		while (j >= 0)
		{
			free(matrix[j]);
			j--;
		}
		return (1);
	}
	return (0);
}
