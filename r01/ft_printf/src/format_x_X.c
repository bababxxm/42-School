/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x_X.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:52:23 by sklaokli          #+#    #+#             */
/*   Updated: 2024/09/09 02:29:16 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	format_both_x(unsigned int n, const char c)
{
	int	len;

	len = 0;
	ft_puthex(n, c);
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}
