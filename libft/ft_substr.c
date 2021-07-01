/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:59:19 by fportalo          #+#    #+#             */
/*   Updated: 2021/06/29 15:57:37 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subst;
	size_t	maxl;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	maxl = ft_strlen(s);
	if (start >= maxl)
		return (ft_strdup(""));
	subst = (char *)malloc(sizeof(char) * len + 1);
	if (!subst)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		subst[j] = s[i];
		j++;
		i++;
	}
	subst[j] = '\0';
	return (subst);
}
