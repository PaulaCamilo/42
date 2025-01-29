/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:33:36 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/29 16:04:36 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Utility function for write
void    writestr(int fd, const char *str)
{
    write(fd, str, strlen(str));
}

int main(void)
{
    int pipefd[2];  // stores the pipe's fds:
                    // - pipefd[0]: read only
                    // - pipefd[1]: write only
    pid_t   pid;    // stores fork's return value
    char    buf;    // stores characters read by read

//  create a pipe. stop everything on failure
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
//  create a child process
    pid = fork(); // creates a new process. the return value
                  // distinguishes between the parent and chil
                  // processes
    if (pid == -1) // an error occurred during forking 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) // current process is the child
    {
    // close the unused write end
        close(pipefd[1]);
        writestr(STDOUT_FILENO, "Child: What is the secret in this pipe?\n");
        writestr(STDOUT_FILENO, "Child: \"");
    // read characters from the pipe one by one
        while (read(pipefd[0], &buf, 1) > 0)
        {
            // write the read character to standard output
            write (STDOUT_FILENO, &buf, 1);
        }
        writestr (STDOUT_FILENO, "\"\n");
        writestr(STDOUT_FILENO, "Child: Wow! I must go see my father. \n");
    //  close the read end of the pipe;
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }
    else    // current process is the parent
    {
    //  close unused read end
        close(pipefd[0]);
        writestr(STDOUT_FILENO, "Parent: I'm writing a secret in this pipe...\n");
    //  write into the pipe
        writestr(pipefd[1], "\e[33mI am your father mwahahahah!\e[0m");
    //  close write end of the pipe (reader will see EOF)
        close(pipefd[1]);
    //  wait for child
        wait (NULL);
        writestr(STDOUT_FILENO, "Parent: Hello child!\n");
        exit(EXIT_SUCCESS);
    }
}