/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:50:13 by sklaokli          #+#    #+#             */
/*   Updated: 2024/09/09 02:30:24 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_format(const char *format, va_list ap);

int		format_c_pcnt(char c);
int		format_s(char *s);
int		format_p(unsigned long n, const char c);
int		format_d_i(int num);
int		format_u(unsigned int n);
int		format_both_x(unsigned int n, const char c);

int		ft_putchar(char c);
void	ft_puthex(unsigned long n, const char c);
void	ft_putnbr(int num);
void	ft_putuns(unsigned int n);

#endif