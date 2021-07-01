#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"

#define READ_END    0    /* index pipe extremo lectura */
#define WRITE_END   1    /* index pipe extremo escritura */

#define INFILE      0

#define FILE_NAME  "file.txt"   /* nombre del archivo donde escribir */

int     main();
void    manage_infile(char **argv, int *fd_pipe, char **envp);

char    **get_all_path(char **envp);
char    *find_the_path(char *argv, char **all_path);
char    *manage_path(char **envp, char *argv);

void    number_arguments(int argc);
void    correct_path(char *path);
void    open_file(int fd);
void    bad_pid(void);

// int     ft_strlen(char *str);
// int	    ft_strncmp(const char *s1, const char *s2, size_t n);
// void	*ft_calloc(size_t n, size_t s);
// void	ft_bzero(void *s, size_t n);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strdup(const char *s1);
// void	*ft_memcpy(void *dst, const void *src, size_t n);
// int		ft_freearray(char **array);
// char	**ft_split(const char *s, char c);
