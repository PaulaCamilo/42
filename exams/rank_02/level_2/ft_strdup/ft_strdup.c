/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:52:31 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/05 13:02:38 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int	i = 0;
	int	length = 0;
	char *strcpy;
	
	while (src[length])
		length++;
	strcpy = malloc(sizeof(*strcpy) * (length + 1));
	if (strcpy != NULL)
	{
		while (src[i])
		{
			strcpy[i] = src[i];
			i++;
		}
		strcpy[i] = '\0';
	}
	return (strcpy);
}

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc == 1)
    {
        printf("ft_strdup(\"\") = %s\n", ft_strdup(""));
		printf("strdup(\"\") = %s\n", strdup(""));
        return(0);
    }
    printf("ft_strdup(\"%s\") = %s\n", argv[1], ft_strdup(argv[1]));
	printf("strdup(\"%s\") = %s\n", argv[1], strdup(argv[1]));
    return(0);
}