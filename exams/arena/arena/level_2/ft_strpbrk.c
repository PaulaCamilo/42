/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:21:01 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/05 17:11:10 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    while (*s1)
    {
        i = 0;
        while (s2[i])
        {
            if (s2[i] == *s1)
                return ((char *)s1);
            i++;
        }
        s1++;
    }
    return (0);
}

#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = "abaaaZ";
	char *accept = "Zzb Top";
	char *found = NULL;
    char *found2 = NULL;

	printf("str address : %p\n", s);
	printf("str value : %s\n", s);

	printf("accept values : %s\n", accept);

	found = ft_strpbrk(s, accept);
	printf("found : %c\n", *found);
	printf("at address : %p\n", found);

    found2 = strpbrk(s, accept);
	printf("found : %c\n", *found2);
	printf("at address : %p\n", found2);
	
	return (0);
}