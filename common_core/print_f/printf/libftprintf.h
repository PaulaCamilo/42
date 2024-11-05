/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:42:41 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/05 14:56:33 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printchar(char c);
int		ft_printf(const char *str, ...);
int		ft_printnb(int number);
int		ft_printstring(char *str);

void	ft_printstring_fd(char *str, int fd)
#endif
