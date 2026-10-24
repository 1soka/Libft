/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:44:45 by ********          #+#    #+#             */
/*   Updated: 2026/10/23 16:15:10 by ********         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static int	is_a_charset(char c, const char s)
{
	if (c == s)
		return (1);
	return (0);
}

static int	count_word(char c, const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (!is_a_charset(c, s[i])
			&& (i == 0 || is_a_charset(c, s[i - 1])))
			count++;
		i++;
	}
	return (count);
}

static char	*get_word(char c, const char *s, int *i)
{
	int		limit;
	int		k;
	char	*word;

	while (s[*i] != '\0' && is_a_charset(c, s[*i]))
		(*i)++;
	limit = *i;
	while (s[*i] != '\0' && !is_a_charset(c, s[*i]))
		(*i)++;
	word = malloc(((*i - limit) + 1) * sizeof(char));
	if (!word)
		return (NULL);
	k = 0;
	while (limit < *i)
	{
		word[k] = s[limit];
		limit++;
		k++;
	}
	word[k] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = 0;
	arr = malloc((count_word(c, s) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && is_a_charset(c, s[i]))
			i++;
		if (s[i] != '\0')
			arr[j++] = get_word(c, s, &i);
		if (j > 0 && !arr[j - 1])
			return (ft_free_arr(arr));
	}
	arr[j] = NULL;
	return (arr);
}
