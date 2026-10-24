/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:44:39 by ********          #+#    #+#             */
/*   Updated: 2026/10/23 16:02:21 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_malloc(char *result, long int nb)
{
	if (nb < 0)
		result = malloc((ft_itoa_len(nb) + 2));
	else
		result = malloc((ft_itoa_len(nb) + 1));
	if (!result)
		return (NULL);
	return (result);
}

char	*ft_itoa(int n)
{
	int			i;
	int long	nb;
	char		*result;

	nb = n;
	result = ft_itoa_malloc(NULL, nb);
	if (!result)
		return (NULL);
	i = ft_itoa_len(nb);
	i--;
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
		i++;
	}
	result[i + 1] = '\0';
	if (nb == 0)
		result[0] = '0';
	while (nb > 0)
	{
		result[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (result);
}
