/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:49:20 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/22 17:53:54 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int check_base(char c, int base)
{
    char *up_base = "0123456789ABCDEF";
    char *low_base = "0123456789abcdef";

    while (base--)
    {
        if (up_base[base] == c || low_base[base] == c)
            return (1);
    }
    return (0);
}

int value(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] && str[i] <= 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (check_base(str[i], str_base))
    {
        result = result * str_base + (value(str[i]));
        i++;
    }
    return (result);
}