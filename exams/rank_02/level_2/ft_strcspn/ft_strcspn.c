/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:54:20 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/05 12:51:10 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i = 0;
	size_t	count = 0;

	while (*s)
	{
		while (reject[i] && *s != reject[i])
			i++;
		if (reject[i] != '\0')
			return (count);
		i = 0;
		count++;
		s++;
	}
	return (count);	
}


#include <stdio.h>
#include <string.h>
size_t	ft_strcspn(const char *s, const char *reject);

int main(int argc, char **argv)
{
    if (argc == 3)
	{
        printf("ft_strcspn(\"%s\", \"%s\") = %zu\n", argv[1], argv[2], ft_strcspn(argv[1], argv[2]));
		printf("strcspn(\"%s\", \"%s\") = %zu\n", argv[1], argv[2], strcspn(argv[1], argv[2]));
		printf("number of characters in the original string if same char as reject is not found");
	}
    return(0);
}