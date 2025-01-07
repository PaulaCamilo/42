/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:13:45 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/05 17:25:49 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
    int i = 0;
    int length = 0;
    char temp_str;
    
    while (str[length])
        length++;
    while (i < length - 1)
    {
        temp_str = str[i];
        str[i] = str[length - 1];
        str[length - 1] = temp_str;
        length--;
        i++;
    }
    return (str);
}

#include <stdio.h>

int main(void)
{
	char str[100] = "Zedro 42";
	char *rev = NULL;

	rev = ft_strrev(str);
	printf("%s\n", rev);

	return (0);
}