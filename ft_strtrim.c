/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 23:36:59 by ********          #+#    #+#             */
/*   Updated: 2026/10/22 14:09:45 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char const c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		start;
	char	*result;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0' && is_set(set, s1[i]))
		i++;
	start = i;
	if (start == (int)ft_strlen(s1))
		return (ft_strdup(""));
	i = ft_strlen(s1);
	while (i > 0 && is_set(set, s1[i - 1]))
		i--;
	result = malloc((i - start) + 1);
	if (!result)
		return (NULL);
	while (start < i)
		result[j++] = s1[start++];
	result[j] = '\0';
	return (result);
}
