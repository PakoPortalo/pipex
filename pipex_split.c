/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:39:58 by fportalo          #+#    #+#             */
/*   Updated: 2021/07/01 13:40:13 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	int	ft_contar(char const *s, char c)
{
	int		wlen;
	int		i;
	size_t	w;

	i = 0;
	wlen = 0;
	w = 0;
	while (s[i])
	{
		if (!wlen && s[i] != c)
			w++;
		if (s[i] == c)
			wlen = 0;
		else
			wlen = 1;
		i++;
	}
	return (w);
}

static	int	ft_lenword(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	str = (char **)malloc(sizeof(*str) * (ft_contar(s, c) + 1));
	if (!s || !(str))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_contar(s, c))
	{
		k = 0;
		str[i] = ft_calloc(ft_lenword(&s[j], c) + 1, 1);
		if (!(str[i]))
			str[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str[i][k++] = s[j++];
		str[i][k] = '\0';
	}
	str[i] = 0;
	return (str);
}
