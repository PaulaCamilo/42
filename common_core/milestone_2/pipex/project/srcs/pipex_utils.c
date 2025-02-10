/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:41:46 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/02/10 10:15:21 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	exit_util(int exit_n)
{
	if (exit_n == 1)
	{
		ft_putstr_fd("Invalid input: try ./pipex file1 cmd1 cmd2 file 2\n", 2);
		exit(EXIT_FAILURE);
	}
	if (exit_n == 2)
	{
		ft_putstr_fd("Failed to create pipe\n", 2);
		exit(EXIT_FAILURE);
	}
	if (exit_n == 3)
	{
		ft_putstr_fd("Fork failed\n", 2);
		exit(EXIT_FAILURE);
	}
	if (exit_n == 4)
	{
		ft_putstr_fd("Failed to open file\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	open_util(char *file, int inp_or_outp)
{
	int	return_v;

	if (inp_or_outp == 0)
		return_v = open(file, O_RDONLY, 0444);
	if (inp_or_outp == 1)
		return_v = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (return_v);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**full_path;
	char	*part_path;
	char	*path;

	i = 0;
	if (!env[i])
		return (NULL);
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	full_path = ft_split(env[i] + 5, ':');
	i = 0;
	while (full_path[i])
	{
		part_path = ft_strjoin(full_path[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
			return (free_str(full_path), path);
		free(path);
		i++;
	}
	free_str(full_path);
	return (NULL);
}
