/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:42:02 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/28 17:00:20 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int  main(int argc, char **argv, char **envp)
{
    t_pipex	pipex;

    if (argc != 5)
    {
        ft_error("Invalid input. Usage: ./pipex file1 cmd1 cmd2 file2");
        exit(1);
    }
    pipex.cmd = &argv[2];
    pipex.envp = envp;
    pipex.infile = argv[1];
    pipex.outfile = argv[4];
    ft_pipex(&pipex);
    return (0);
}
int	ft_pipex(t_pipex *pipex)
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
    char **cmd_args;

    ft_pipex_dup(pipex, fd, i);
    if (i == 0)
        ft_pipex_close(pipex);
    close(fd[0]);
    close(fd[1]);
    cmd_args = ft_split(pipex->cmd[i], ' ');
    if (!cmd_args)
    {
        ft_free(cmd_args);
        ft_error("Error: Split failed");
    }
    else if (execve(pipex->cmd[i], pipex->cmd, pipex->envp) == -1)
    {
        ft_free(cmd_args);
        ft_error("Error: Command not found");
    }
    ft_free(cmd_args);
}

void	ft_pipex_parent(t_pipex *pipex, int *fd, int i)
{
    if (i > 0)
        ft_pipex_close(pipex);
    close(fd[1]);
    ft_pipex_dup(pipex, fd, i);
    close(fd[0]);
}
void    ft_pipex_exec(t_pipex *pipex, int *fd, int i)
{
    pid_t    pid;
    char **cmd_args;

    pid = fork();
    if (pid == -1)
        ft_error("Error: Fork failed");
    if (pid == 0)
    {
        ft_pipex_dup(pipex, fd, i);
        close(fd[0]);
        close(fd[1]);
        cmd_args = ft_split(pipex->cmd[i], ' ');
        if (execve(pipex->cmd[i], pipex->cmd, pipex->envp) == -1)
        {
            ft_free(cmd_args);
            ft_error("Error: Command not found");
        }
    }
    else
    {
        close(fd[0]);
        close(fd[1]);
        waitpid(pid, NULL, 0);
    }
}