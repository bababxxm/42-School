/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:00:44 by sklaokli          #+#    #+#             */
/*   Updated: 2024/08/30 19:00:45 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	long	n;

	n = num;
	if (fd < 0)
		return ;
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

// int	main()
// {
// 	int fd = open("./filetest_plz_rm.txt", O_CREAT | O_WRONLY);
// 	// ft_putstr_fd("dsadasadasda\n", fd);
// 	ft_putnbr_fd(1234, fd);
// 	close(fd);
// }
