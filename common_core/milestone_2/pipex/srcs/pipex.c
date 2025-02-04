/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:42:02 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/04 13:55:41 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute(char *cmd, char **env, int *fd)
{
	char	**x_cmd;
	char	*path;

	x_cmd = ft_split(cmd, ' ');
	path = get_path(x_cmd[0], env);
	if (!path || execve(path, x_cmd, env) == -1)
	{
		free_str(x_cmd);
		perror("Error: Command not found");
		close_fd(fd);
		exit(EXIT_FAILURE);
	}
	free_str(x_cmd);
	free(path);
}

void child(char **av, int *pipe_fd, char **env)
{
	int	fd;

	close(pipe_fd[0]);
	fd = open(av[1], O_RDONLY, 0444);
	if (fd == -1)
	{
		close(pipe_fd[1]);
		exit_util(4);
	}
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pipe_fd[1]);
	close(fd);
	execute(av[2], env, pipe_fd);
}

void	parent(char **av, int *pipe_fd, char **env)
{
	int	fd;

	close(pipe_fd[1]);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		close(pipe_fd[0]);
		exit(EXIT_FAILURE);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(fd);
	execute(av[3], env, pipe_fd);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
		exit_util(1);
	if (pipe(fd) < 0)
		exit_util(2);
	pid = fork();
	if (pid == -1)
		exit_util(3);
	if (pid == 0)
		child(av, fd, env);
	else
		parent(av, fd, env);
	return (0);
}
