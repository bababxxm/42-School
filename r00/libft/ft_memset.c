/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:22:57 by sklaokli          #+#    #+#             */
/*   Updated: 2024/08/25 17:22:59 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*tmp;

	tmp = (char *)s;
	while (n > 0)
	{
		tmp[n - 1] = (char)c;
		n--;
	}
	return ((char *)tmp);
}

// int	main()
// {
// 	char str[3] = "abc";
// 	ft_memset(str, '2', 3);
// 	printf("%s", str);
// }
