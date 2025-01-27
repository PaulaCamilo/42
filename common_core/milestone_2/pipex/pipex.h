/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:53:18 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/27 16:57:55 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_X

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_pipex
{
    char	**cmd;
    char	**env;
    char	*infile;
    char	*outfile;
    int		infile_fd;
    int		outfile_fd;
}	t_pipex;

void	ft_error(char *str);
void	ft_free(char **str);
void	ft_pipex(t_pipex *pipex);
void	ft_pipex_child(t_pipex *pipex, int *fd, int i);
void	ft_pipex_parent(t_pipex *pipex, int *fd, int i);
void	ft_pipex_exec(t_pipex *pipex, int *fd, int i);
void	ft_pipex_open(t_pipex *pipex);
void	ft_pipex_close(t_pipex *pipex);
void	ft_pipex_dup(t_pipex *pipex, int *fd, int i);

#endif