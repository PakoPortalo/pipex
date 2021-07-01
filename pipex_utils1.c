/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:29:56 by fportalo          #+#    #+#             */
/*   Updated: 2021/07/01 14:29:59 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (((unsigned char)s1[i] != 0 || (unsigned char)s2[i] != 0) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (((unsigned char)s1[i] != (unsigned char)s2[i]) && i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

void	*ft_calloc(size_t n, size_t s)
{
	void	*ptr;

	ptr = malloc(n * s);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, n * s);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (n > 0)
	{
		((char *)s)[i] = '\0';
		n--;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	j;
	unsigned int	k;
	char			*p;

	j = 0;
	k = 0;
	if (!s1)
		return (NULL);
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (0);
	while (s1[j] != '\0')
	{
		p[j] = s1[j];
		j++;
	}
	while (s2[k] != '\0')
		p[j++] = s2[k++];
	p[j] = '\0';
	return (p);
}
