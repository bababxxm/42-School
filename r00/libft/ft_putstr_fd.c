/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:00:14 by sklaokli          #+#    #+#             */
/*   Updated: 2024/08/30 19:00:15 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if ((!s) || fd < 0)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

// int	main()
// {
// 	int fd = open("./filetest_plz_rm.txt", O_CREAT | O_WRONLY);
// 	ft_putstr_fd("dsadasadasda\n", fd);
// 	close(fd);
// }