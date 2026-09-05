/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:59:21 by sklaokli          #+#    #+#             */
/*   Updated: 2024/08/30 18:59:22 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	issep(char const *s, char c)
{
	int	sep;

	if (!s)
		return (0);
	sep = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			sep++;
		s++;
	}
	return (sep);
}

static int	len(char const *s, char c)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	**freesplit(char **str, int nb)
{
	while (nb >= 0)
		free(str[nb--]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		start;
	int		idx;

	str = (char **)malloc(sizeof(char *) * (issep(s, c) + 1));
	if (!s || !str)
		return (NULL);
	start = 0;
	idx = 0;
	while (s[start])
	{
		if (s[start] != c)
		{
			str[idx] = ft_substr(s, start, len(&s[start], c));
			if (!str[idx])
				return (freesplit(str, idx));
			idx++;
			start += len(&s[start], c);
		}
		else
			start++;
	}
	str[idx] = 0;
	return (str);
}
