/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:24:26 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/21 18:25:38 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	    is_power_of_2(unsigned int n)
{
    // If n is 0, it's not a power of 2, so we return 0. 
    // If n is a power of 2, n & n - 1 will be 0, so we return 1. 
    return (n && !(n & n - 1)); 
}