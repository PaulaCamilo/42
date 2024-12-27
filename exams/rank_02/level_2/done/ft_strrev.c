/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:13:42 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/13 09:19:49 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
	int i = 0;
	int length = 0;
	char temp;

	while (str[length])
		length++;
	while (i < length - 1)
	{
		temp = str[i];
		str[i] = str[length - 1];
		str[length -1] = temp;
		length--;
		i++;
	}
	return (str);
}