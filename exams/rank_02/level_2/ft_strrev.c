/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:13:30 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/12 14:46:50 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
	int i = 0;
	int len = 0;
	char temp;

	while (str[len])
		len++;
	while (i < len - 1)
	{
		temp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = temp;
		len--;
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