/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:52:20 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/09/18 09:11:43 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	whitespaces_signs(char *str, int *ptr_p)
{
	int	counter;
	int	p;

	p = 0;
	counter = 1;
	while ((str[p] >= 9 && str[p] <= 13) || str[p] == 32)
		p++;
	while (str[p] == 43 || str[p] == 45)
	{
		if (str[p] == 45)
			counter *= -1;
		p++;
	}
	*ptr_p = p;
	return (counter);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	p;

	result = 0;
	sign = whitespaces_signs(str, &p);
	while (str[p] && str[p] >= 48 && str[p] <= 57)
	{
		result *= 10;
		result += str[p] - 48;
		p++;
	}
	result *= sign;
	return (result);
}
