/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:45:34 by fportalo          #+#    #+#             */
/*   Updated: 2021/07/02 14:13:32 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	number_arguments(int argc)
{
	if (argc != 5)
	{
		errno = EINVAL;
		perror("Error bro");
		exit(-1);
	}
}

void	correct_path(char *path)
{
	if (!path)
	{
		perror("Error bro");
		exit(-1);
	}
}

void	open_file(int fd)
{
	if (fd < 0)
	{
		perror("Error bro");
		exit (-1);
	}
}

void	bad_pid(void)
{
	perror("Error bro");
	exit(-1);
}
