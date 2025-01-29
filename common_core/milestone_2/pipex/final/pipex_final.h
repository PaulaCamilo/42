/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_final.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:53:18 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/29 15:57:07 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_FINAL_H
# define PIPEX_FINAL_H

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


// pipex_utils.c


// ft_utils.c
void    ft_putstr_fd(int fd, const char *str);

#endif