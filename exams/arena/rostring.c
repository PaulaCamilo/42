/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:07:45 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/21 19:19:25 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int word_start; // variable to store the start of the first word
    int word_end; // variable to store the end of the first word

    if (ac > 1)
    {
        i = 0;
        while (av[1][i]) // while the string is not null
        {
            while (av[1][i] == ' ' || av[1][i] == '\t') // while the character is a space or tab
                i++; // move to the next character
            word_start = i; // store the start of the first word
            while (av[1][i] && !(av[1][i] == ' ' || av[1][i] == '\t')) // while the character is not a space or tab
                i++; // move to the next character
            word_end = i; // store the end of the first word
            while (av[1][i] == ' ' || av[1][i] == '\t') // while the character is a space or tab
                i++; // move to the next character
            while (av[1][i]) // while the string is not null
            {
                if (av[1][i] && !(av[1][i] == ' ' || av[1][i] == '\t') // if the character is not a space or tab, and the previous character is a space or tab
                    && (av[1][i - 1] == ' ' || av[1][i - 1] == '\t'))
                    {
                        while (av[1][i] && !(av[1][i] == ' ' || av[1][i] == '\t'))  // while the character is not a space or tab
                        {
                            write (1, &av[1][i], 1); // write the character
                            i++; // move to the next character
                        }
                        write (1, " ", 1); // write a space after the word is written
                    }
                    i++;
            }
            while (word_start < word_end) // while the start of the first word is less than the end of the first word
            {
                write (1, &av[1][word_start], 1); // write the character
                word_start++; // write the character
            }
        }
    }
    write (1, "\n", 1);
    return (0);
}