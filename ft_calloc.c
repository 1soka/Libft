/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 18:58:55 by ********          #+#    #+#             */
/*   Updated: 2026/10/23 18:27:17 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*buffer;

	i = 0;
	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	while (i < (nmemb * size))
		((unsigned char *)buffer)[i++] = 0;
	return (buffer);
}
