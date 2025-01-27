/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:42:02 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/27 17:42:32 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int  main(int argc, char **argv, char **env)
{
    t_pipex	pipex;

    if (argc != 5)
        ft_error("Error: Wrong number of arguments");
    pipex.cmd = &argv[2];
    pipex.env = env;
    pipex.infile = argv[1];
    pipex.outfile = argv[4];
    ft_pipex(&pipex);
    return (0);
}

void	ft_pipex(t_pipex *pipex)
{
    int		fd[2];
    int		i;
    pid_t	pid;

    i = 0;
    ft_pipex_open(pipex);
    while (pipex->cmd[i + 1])
    {
        if (pipe(fd) == -1)
            ft_error("Error: Pipe failed");
        pid = fork();
        if (pid == -1)
            ft_error("Error: Fork failed");
        if (pid == 0)
            ft_pipex_child(pipex, fd, i);
        else
            ft_pipex_parent(pipex, fd, i);
        i++;
    }
    ft_pipex_exec(pipex, fd, i);
    ft_pipex_close(pipex);
}

void	ft_pipex_child(t_pipex *pipex, int *fd, int i)
{
    ft_pipex_dup(pipex, fd, i);
    if (i == 0)
        ft_pipex_close(pipex);
    if (execve(pipex->cmd[i], pipex->cmd, pipex->env) == -1)
        ft_error("Error: Command not found");
}

void	ft_pipex_parent(t_pipex *pipex, int *fd, int i)
{
    if (i > 0)
        ft_pipex_close(pipex);
    close(fd[1]);
    ft_pipex_dup(pipex, fd, i);
}

