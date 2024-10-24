/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:30:08 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/24 10:30:11 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	number_len(int n);

char	*ft_itoa(int n)
{
	char			*str;
	long			len;
	int				number;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = number_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str [0] = '-';
		number = -n;
	}
	else
		number = n;
	if (number == 0)
		str[0] = '0';
	str[len] = '\0';
	while (number != '\0')
	{
		str[len - 1] = (number % 10) + '0';
		number = number / 10;
		len--;
	}
	return (str);
}

static long int	number_len(int n)
{
	long int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
