/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:08:54 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/12/17 14:34:28 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ver_base(char c, int base)
{
	char *up_base = "0123456789ABCDEF";
	char *down_base = "0123456789abcdef";
	while (base--)
	{
		if(up_base[base] == c || down_base[base] == c)
			return (1);
	}
	return (0);
}

int value(char c)
{
	if(c >= '0' && c <= '9')
	{
		return(c - '0');
	}else if(c >= 'A' && c <= 'F'){
		return (c - 'A' + 10);
	}else if(c >= 'a' && c <= 'f'){
		return (c - 'a' + 10);
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int i = 0;
	
	while(str[i] != '\0' && str[i] <= 32)
	{
		i++;
	}
	if(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while(ver_base(str[i], str_base))
	{
		result = result * str_base + value(str[i]);
		i++;
	}
	return (result * sign);
}

int		main(void)
{
	printf("%d\n", ft_atoi_base("011", atoi("2")));
	printf("%d\n", ft_atoi_base("16", atoi("8")));
	printf("%d\n", ft_atoi_base("123", atoi("10")));
	printf("%d\n", ft_atoi_base("FF", atoi("16")));
}