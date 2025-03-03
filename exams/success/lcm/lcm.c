/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:28:42 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/07 16:31:27 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    lcm(unsigned int a, unsigned int b)
{
    int n = 0;
    
    if ((a == 0) || (b == 0))
        return (0);
    if (a < b)
        n = a;
    else
        n = b;
    while (1)
    {
        if ((n % a == 0) && (n % b == 0))
            return (n);
        n++;
    }
}