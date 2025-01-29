/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_ex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:09:03 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/29 17:15:38 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    int fd_copy;
    int nb_read;
    char    buf[15];
    
//  print this process' PID to be able to check open fds
    printf("My PID is %d\n", getpid());
//  open the file and get its fd
    fd = open("alpha.txt", O_RDONLY);
    if (fd == -1)
        return (1);
//  duplicate the fd on the smallest unused fd
    fd_copy = dup(fd);
    if (!fd_copy)
        return (1);
//  read the original fd
    nb_read = read(fd, buf, 10);
    if (nb_read == -1)
        return (1);
    buf[nb_read] = '\0';
    printf("fd %d contains: %s\n", fd, buf);
//  reads the duplicate fd
    nb_read = read(fd_copy, buf, 10);
    if (nb_read == -1)
        return (0);
    buf[nb_read] = '\0';
    printf("fd %d contains: %s\n", fd_copy, buf);
//  duplicate fd on standard input
    dup2(fd, STDIN_FILENO);
//  infinite loop to go check open fds in this process with ls -la /proc/PID/fd
    while (1)
        ;
}