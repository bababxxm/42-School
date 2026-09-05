/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:48:54 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/16 19:32:04 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_format(const char *format, va_list ap)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len += format_c_pcnt(va_arg(ap, int));
	else if (*format == 's')
		len += format_s(va_arg(ap, char *));
	else if (*format == 'p')
		len += format_p(va_arg(ap, unsigned long), *format);
	else if (*format == 'd' || *format == 'i')
		len += format_d_i(va_arg(ap, int));
	else if (*format == 'u')
		len += format_u(va_arg(ap, unsigned int));
	else if ((*format == 'x') || (*format == 'X'))
		len += format_both_x(va_arg(ap, unsigned int), *format);
	else if (*format == '%')
		len += format_c_pcnt('%');
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		else if (format[i] == '%') len += ft_format(&format[++i], ap);
		else len += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

// int	main(void)
// {
// 	int len;

// 	// len = ft_printf("%%1234\n");
// 	// printf("%d\n", len);
// 	// len = printf("%%1234\n");
// 	// printf("%d\n", len);

// 	// len = ft_printf("%%-1234 %d %d %i\n", -1234, 0 ,123);
// 	// printf("%d\n", len);
// 	// len = printf("%%-1234 %d %d %i\n", -1234, 0 ,123);
// 	// printf("%d\n", len);

// 	// // this is gonna crash
// 	// len = ft_printf("%d %d\n", INT_MIN, INT_MAX);
// 	// printf("%d\n", len);
// 	// len = printf("%d %d\n", INT_MIN, INT_MAX);;
// 	// printf("%d\n", len);

// 	// printf("%d\n", printf("%u\n", -1123));
// 	// printf("%d\n", ft_printf("%u\n", -1123));

// 	printf("%d\n", ft_printf("%X\n", 15));
// }
