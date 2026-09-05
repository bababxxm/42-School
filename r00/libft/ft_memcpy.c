/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:23:45 by sklaokli          #+#    #+#             */
/*   Updated: 2024/08/25 17:23:46 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if ((!dst) && (!src))
		return (dst);
	while (++i < n)
		*((char *)dst + i) = *((char *)src + i);
	return (dst);
}
// int	main()
// {
// 	char	dst[30];
// 	printf("%s", (char *)ft_memcpy(dst, "zyxwvutsrqponmlkjihgfedcba", 14));
// }
