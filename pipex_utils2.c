/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:42:54 by fportalo          #+#    #+#             */
/*   Updated: 2021/07/01 14:29:09 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	l;

	l = ft_strlen(s1);
	s2 = (char *)malloc(l + 1);
	if (s2)
	{
		ft_memcpy(s2, s1, l);
		s2[l] = '\0';
	}
	else
		return (0);
	return (s2);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (src == 0 && dst == 0)
		return (dst);
	while (n > 0)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		n--;
	}
	return (dst);
}

int	ft_freearray(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (1);
}
