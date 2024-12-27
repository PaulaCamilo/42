/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:47:19 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/16 13:51:46 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *rev_print(char *str)
{
	int i = 0;
	
	while (str[i])
		i++;;
	while (i >= 0)
	{
		write (1, &str[i], 1);
		i--;
	}
	write (1, "\n", 1);
	return (str);
}

int main(void)
{
  rev_print("Hello world");
  write (1, "\n", 1);
  rev_print("tnirp esreveR");
  write (1, "\n", 1);
  rev_print("");
  write (1, "\n", 1);
}