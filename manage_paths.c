/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:18:42 by fportalo          #+#    #+#             */
/*   Updated: 2021/07/01 13:17:55 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **get_all_path(char **envp)
{
    int     i;
    char    **path;

    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 4) == 0)
        {
            envp[i] += 5;
            path = ft_split(envp[i], ':');
        }
        i++;
    }
    i = 0;
    while (path[i++])
        path[i] = ft_strjoin(path[i], "/");
    return (path);
}

char    *find_the_path(char *argv, char **all_path)
{
    char    *the_path;
    int     i;
    int     fd_path;
    char    **binary;

    i = 0;
    binary = ft_split(argv, ' ');
    while (all_path[i++])
    {
        all_path[i] = ft_strjoin(all_path[i], binary[0]);
        fd_path = open(all_path[i], O_RDONLY);
        if (fd_path > 0)
        {
            the_path = ft_strdup(all_path[i]);
            close(fd_path);
            ft_freearray(all_path);
            return (the_path);
        }
        close(fd_path);
    }
    return (NULL);

}

char    *manage_path(char **envp, char *argv)
{
    char    **all_path;
    char    *the_path;

    all_path = get_all_path(envp);
    the_path = find_the_path(argv, all_path);
    correct_path(the_path);
    return (the_path);
}