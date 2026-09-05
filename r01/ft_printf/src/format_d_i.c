/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:51:44 by sklaokli          #+#    #+#             */
/*   Updated: 2024/09/09 02:29:28 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	format_d_i(int num)
{
	long	n;
	int		len;

	n = num;
	len = 0;
	ft_putnbr(num);
	if (n <= 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
