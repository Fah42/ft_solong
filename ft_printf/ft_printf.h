/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:03:12 by fhadhri           #+#    #+#             */
/*   Updated: 2022/06/16 12:21:32 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
int		ft_formats(va_list args, char c);
int		ft_printchar(int c);
int		ft_printint(int n);
int		ft_printu(unsigned int n);
int		ft_printpercent(void);
int		ft_printhex(unsigned int n, char c);
int		ft_printstr(char *str);
int		ft_printaddr(unsigned long long n);
void	ft_putchar_fd(char c, int fd);
int		ft_intlen(long nb);
char	*ft_itoa(int n);
int		ft_intlent(long nb);
char	*ft_utoa(unsigned long n);
size_t	ft_strlen(const char *s);

#endif