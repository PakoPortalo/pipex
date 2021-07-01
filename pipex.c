/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:45:19 by fportalo          #+#    #+#             */
/*   Updated: 2021/07/01 13:13:55 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



void    manage_infile(char **argv, int *fd_pipe, char **envp)
{
    int     fd_infile;
    char    *the_path;
    char    **binary;
    

    the_path = manage_path(envp, argv[2]);
    binary = ft_split(argv[2], ' ');
    
    close(fd_pipe[READ_END]);
    fd_infile = open(argv[1], O_RDONLY);
    open_file(fd_infile);
    dup2(fd_infile, STDIN_FILENO);                   //Asociamos stdin a lo que haya en el archivo de entrada 'infile'
    close(fd_infile);
    dup2(fd_pipe[WRITE_END], STDOUT_FILENO);             //Asociamos el archivo del infile a la entrada de lectura de pipe
    close(fd_pipe[WRITE_END]);                       //No necesitamos Write_End

    execve(the_path, binary, envp);
}

void    manage_outfile(char **argv, int *fd_pipe, char **envp)
{
    int fd_out;
    char *the_path;
    char **binary;

    the_path = manage_path(envp, argv[3]);
    binary = ft_split(argv[3], ' ');
    
    fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
    open_file(fd_out);
    dup2(fd_pipe[READ_END], STDIN_FILENO);
    close(fd_pipe[READ_END]);
    dup2(fd_out, STDOUT_FILENO);		   
    close(fd_out);

    // printf("Path: %s, binary: %s\n", the_path, binary[0]);
    execve(the_path, binary, envp);
}

int main (int argc, char *argv[], char **envp)
{
    int fd_pipe[2];
    pid_t pid;
    int status;
    
    number_arguments(argc);
    pipe(fd_pipe);
    pid = fork();
    if (pid == 0)      
        manage_infile(argv, fd_pipe, envp);     // Open infile and attach to command
    else if (pid == -1)
        bad_pid();
    close(fd_pipe[WRITE_END]);
    pid = fork();
    if (pid == 0)                           // SON 2
        manage_outfile(argv, fd_pipe, envp);
    else if (pid == -1)
        bad_pid();
    else                                   
        close(fd_pipe[READ_END]);
    wait(&status);
    wait(&status); 
    return (0);
}