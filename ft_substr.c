/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 23:24:56 by ********          #+#    #+#             */
/*   Updated: 2026/10/22 19:20:41 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length;
	char	*result;

	i = (size_t)start;
	j = 0;
	if (start >= ft_strlen(s))
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	length = len;
	if (len >= ft_strlen(s) - start)
		length = ft_strlen(s) - start;
	result = malloc(length + 1);
	if (!result)
		return (NULL);
	while (s[i] != '\0' && (i < start + length))
		result[j++] = s[i++];
	result[j] = '\0';
	return (result);
}
