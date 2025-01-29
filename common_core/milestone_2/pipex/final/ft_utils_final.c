/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:50:28 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/29 15:56:32 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_final.h"

// Utility function for write
void    ft_putstr_fd(int fd, const char *str)
{
    write(fd, str, strlen(str));
}