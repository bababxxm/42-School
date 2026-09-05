/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:02:17 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/15 23:46:03 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	printf(" | printf len: %d\n", printf(NULL));
	printf(" | ft_printf len: %d\n", ft_printf(NULL));

	printf(" | printf len: %d\n", printf("%c", '\0'));
	printf(" | ft_printf len: %d\n", ft_printf("%c", '\0'));

	printf(" | printf len: %d\n", printf("Hello"));
	printf(" | ft_printf len: %d\n", ft_printf("Hello"));

	printf(" | printf len: %d\n", printf("%%"));
	printf(" | ft_printf len: %d\n", ft_printf("%%"));

	printf(" | printf len: %d\n", printf("%d", INT_MAX + 1));
	printf(" | ft_printf len: %d\n", ft_printf("%d", INT_MAX + 1));

	printf(" | printf len: %d\n", printf("%x", 42));
	printf(" | ft_printf len: %d\n", ft_printf("%x", 42));

	printf(" | printf len: %d\n", printf("%X", 42));
	printf(" | ft_printf len: %d\n", ft_printf("%X", 42));

	printf(" | printf len: %d\n", printf("%u", 42));
	printf(" | ft_printf len: %d\n", ft_printf("%u", 42));

	printf(" | printf len: %d\n", printf("%s", "P Kai Sleepy"));
	printf(" | ft_printf len: %d\n", ft_printf("%s", "P Kai Sleepy"));

	char *ptr1 = NULL;
	char *ptr2 = NULL;

	printf(" | printf len: %d\n", printf("%p", ptr1));
	printf(" | ft_printf len: %d\n", ft_printf("%p", ptr1));

	printf(" | printf len: %d\n", printf("%p", ptr2));
	printf(" | ft_printf len: %d\n", ft_printf("%p", ptr2));

	printf(" | printf len: %d\n", printf("%"));
	printf(" | ft_printf len: %d\n", ft_printf("%"));
}