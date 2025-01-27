/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:41:46 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/27 17:44:58 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
    perror(str);
    exit(1);
}

void	ft_free(char **str)
{
    int	i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void	ft_pipex_open(t_pipex *pipex)
{
    pipex->infile_fd = open(pipex->infile, O_RDONLY);
    if (pipex->infile_fd == -1)
        ft_error("Error: Open failed");
    pipex->outfile_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (pipex->outfile_fd == -1)
        ft_error("Error: Open failed");
}

void	ft_pipex_close(t_pipex *pipex)
{
    close(pipex->infile_fd);
    close(pipex->outfile_fd);
}

void	ft_pipex_dup(t_pipex *pipex, int *fd, int i)
{
    if (i == 0)
    {
        dup2(pipex->infile_fd, STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
    }
    else if (!pipex->cmd[i + 1])
    {
        dup2(fd[0], STDIN_FILENO);
        dup2(pipex->outfile_fd, STDOUT_FILENO);
    }
    else
    {
        dup2(fd[0], STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
    }
}

void	ft_pipex_exec(t_pipex *pipex, int *fd, int i)
{
    pid_t	pid;

    pid = fork();
    if (pid == -1)
        ft_error("Error: Fork failed");
    if (pid == 0)
    {
        ft_pipex_dup(pipex, fd, i);
        if (execve(pipex->cmd[i], pipex->cmd, pipex->env) == -1)
            ft_error("Error: Command not found");
    }
    else
        waitpid(pid, NULL, 0);
}