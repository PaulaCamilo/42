/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:58:17 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/16 13:11:21 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	p;
	int	c;

	p = 0;
	c = 0;
	if (to_find[c] == '\0')
	{
		return (str);
	}
	while (str[p] != '\0')
	{
		while (str[p + c] == to_find[c] && str[p + c] != '\0')
		{
			c++;
		}
		if (to_find[c] == '\0')
		{
			return (str + p);
		}
		p++;
		c = 0;
	}
	return (0);
}
