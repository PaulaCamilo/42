/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:53:18 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/04 11:18:06 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct s_pipex
{
    char	**cmd;
    char	**envp;
    char	*infile;
    char	*outfile;
    int		infile_fd;
    int		outfile_fd;
}	t_pipex;

//pipex.c
void	execute(char *cmd, char **env, int *fd);
void    child(char **av, int *pipe_fd, char **env);
void	parent(char **av, int *pipe_fd, char **env);

// pipex_utils.c
void	close_fd(int *fd);
void	exit_util(int exit_n);
int	    open_util(char *file, int inp_or_outp);
void	free_str(char **str);
char	*get_path(char *cmd, char **env);

// ft_utils.c
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);

// ft_utils2.c
char	*ft_strnstr(const char *big, const char *little, size_t n);
int	    ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif