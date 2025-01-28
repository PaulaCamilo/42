/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:50:28 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/28 17:00:39 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_free(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

static int ft_word_length(char *str)
{
    int i = 0;
    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        i++;
    return (i);
}

static char *ft_word_dup(char *str)
{
    int i = 0;
    int length = ft_word_length(str);
    char *word = malloc(sizeof(char) * (length + 1));
    
    if (!word)
        return (NULL);
    word[length] = '\0';
    while (i < length)
    {
        word[i] = str[i];
        i++;
    }
    return (word);
}

static void ft_fill_words(char **array, char *str)
{
    int word_index = 0;
    while (*str == ' ' || *str == '\t' || *str == '\n')
        ++str;
    while (*str)
    {
        array[word_index] = ft_word_dup(str);
        ++word_index;
        while(*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
            ++str;
        while (*str == ' ' || *str == '\t' || *str == '\n')
            ++str;
    }
}

static int ft_count_words(char *str)
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

char    **ft_split(char *str, char c)
{
    int num_words = ft_count_words(str);
    char **array = malloc(sizeof(char *) * (num_words + 1));

    if(!array)
        return (NULL);
    array[num_words] = 0;
    ft_fill_words(array, str);
    return (array);
}