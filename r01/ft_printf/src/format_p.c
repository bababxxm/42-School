/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:51:26 by sklaokli          #+#    #+#             */
/*   Updated: 2024/09/09 02:29:30 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	format_p(unsigned long n, const char c)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	ft_puthex(n, c);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}
