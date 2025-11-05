/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 04:28:42 by mpierant          #+#    #+#             */
/*   Updated: 2025/03/28 04:19:37 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	r;

	if (s == NULL)
		return (0);
	r = 0;
	while (s[r] != '\0')
	{
		r++;
	}
	return (r);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	dim;
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dim = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((dim + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
