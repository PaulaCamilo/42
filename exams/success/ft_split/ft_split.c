/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:41:11 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/09 13:08:58 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int word_length(char *str)
{
    int i = 0;
    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        i++;
    return (i);
}

char *word_dup(char *str)
{
    int i = 0;
    int length = word_length(str);
    char *word = malloc(sizeof(char) * (length + 1));

    word[length] = '\0';
    while (i < length)
    {
        word[i] = str[i];
        i++;
    }
    return (word);
}

void fill_words(char **array, char *str)
{
    int word_index = 0;
    while (*str == ' ' || *str == '\t' || *str == '\n')
        ++str;
    while (*str)
    {
        array[word_index] = word_dup(str);
        ++word_index;
        while(*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
            ++str;
        while (*str == ' ' || *str == '\t' || *str == '\n')
            ++str;
    }
}

int count_words(char *str)
{
    int num_words = 0;
    
    while (*str == ' ' || *str == '\t' || *str == '\n')
        ++str;
    while (*str)
    {
        ++num_words;
        while(*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
            ++str;
        while (*str == ' ' || *str == '\t' || *str == '\n')
            ++str;
    }
    return (num_words);
}

char    **ft_split(char *str)
{
    int num_words = count_words(str);
    char **array = malloc(sizeof(char *) * (num_words + 1));

    array[num_words] = 0;
    fill_words(array, str);
    return (array);
}