/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:42:41 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/11/12 09:23:51 by ppaula-d         ###   ########.fr       */
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
int		ft_printf(const char *var, ...);

//main functions
int		ft_print_char(int c);
int		ft_print_dec_int(int number);
int		ft_print_hexa(unsigned int number, int type);
int		ft_print_pointer(void *ptr);
int		ft_print_string(char *str);
int		ft_print_un_dec(unsigned int number);

//utils functions
int		ft_base16(unsigned long number, char *base);
int		ft_char_fd(char c, int fd);
int		ft_string_fd(char *str, int fd);
int		ft_strlen(char *str);

#endif
