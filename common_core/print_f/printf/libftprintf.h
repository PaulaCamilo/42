/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:42:41 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/06 16:48:12 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

//printf
int		ft_check_format(const char type, va_list args);
int		ft_printf(const char *str, ...);

//main functions
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_dec_int(int number);
int		ft_print_un_dec(unsigned int number);

//helper functions
int		ft_strlen(char *str);
int		ft_string_fd(char *str, int fd);
#endif
