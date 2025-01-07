/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:16:06 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/05 18:21:30 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
    unsigned int i = 0;
    int max;
    
    if (len == 0)
        return (0);
    max = tab[i];
    while (i < len)
    {
        if (max < tab[i])
            max = tab[i];
        i++;
    }
    return (max);
}

#include <stdio.h>

int main(void)
{
	int tab[5] = { 2, 6, 42, 9, 3 };
	int n = 5;
	int i;
	int max_val;

	printf("Tab:\n");
	i = 0;
	while (i < n)
		printf("%d ", tab[i++]);
	printf("\n");
	
	max_val = max(tab, n);
	printf("Max = %d", max_val);
	printf("\n");

	return (0);
}