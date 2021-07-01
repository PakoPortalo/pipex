/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:45:34 by fportalo          #+#    #+#             */
/*   Updated: 2021/07/01 14:28:20 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	number_arguments(int argc)
{
	if (argc != 5)
	{
		perror("Error bro: número de argumentos inválido.\n");
		exit(-1);
	}
}

void	correct_path(char *path)
{
	if (!path)
	{
		perror("Error bro: Path incorrecto");
		exit(-1);
	}
}

void	open_file(int fd)
{
	if (!fd)
	{
		perror("Error bro: Archivo no abierto");
		exit (-1);
	}
}

void	bad_pid(void)
{
	perror("Error bro: Hijo no encontrado");
	exit(-1);
}
