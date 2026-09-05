/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:00:05 by sklaokli          #+#    #+#             */
/*   Updated: 2024/08/30 19:00:06 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

// int	main()
// {
// 	int fd = open("./filetest_plz_rm.txt", O_CREAT | O_WRONLY);
// 	ft_putchar_fd('e', fd);
// 	close(fd);
// }
