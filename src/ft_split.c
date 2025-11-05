/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:27:42 by mpierant          #+#    #+#             */
/*   Updated: 2025/03/25 18:33:10 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	ft_issep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count(char *str, char *charset)
{
	int	words;
	int	i;
	int	dim;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_issep(str[i], charset))
			i++;
		dim = 0;
		while (str[i] != '\0' && !ft_issep(str[i], charset))
		{
			dim++;
			i++;
		}
		if (dim > 0)
			words++;
	}
	return (words);
}

void	ft_fill(char *str, char *charset, char *dest, int i)
{
	int	j;

	j = 0;
	while (str[i] != '\0' && !ft_issep(str[i], charset))
		dest[j++] = str[i++];
	dest[j] = '\0';
}

int	ft_create(char *str, char *charset, char **matrix)
{
	int	i;
	int	j;
	int	dim;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_issep(str[i], charset))
			i++;
		dim = 0;
		while (str[i] != '\0' && !ft_issep(str[i], charset))
		{
			dim++;
			i++;
		}
		if (dim > 0)
		{
			if (ft_alloc(matrix, j, dim))
				return (1);
			ft_fill(str, charset, matrix[j], i - dim);
			j++;
		}
	}
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**matrix;
	int		dim;
	int		check;

	dim = ft_count(str, charset);
	matrix = (char **)malloc((dim + 1) * sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	matrix[dim] = 0;
	check = ft_create(str, charset, matrix);
	if (check == 1)
		return (free(matrix), NULL);
	return (matrix);
}
