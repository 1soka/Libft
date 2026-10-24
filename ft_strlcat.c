/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:05:45 by ********          #+#    #+#             */
/*   Updated: 2026/10/23 16:46:17 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = 0;
	slen = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size == ft_strlen(dst))
		return (ft_strlen(src) + ft_strlen(dst));
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	while (dlen < size && dst[dlen] != '\0')
		dlen++;
	while (dlen + i < size - 1 && src[i] != '\0')
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
