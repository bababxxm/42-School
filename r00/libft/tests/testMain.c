/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 16:15:00 by sklaokli          #+#    #+#             */
/*   Updated: 2026/09/05 16:15:00 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define COLOR_GREEN "\033[32m"
#define COLOR_RED   "\033[31m"
#define COLOR_CYAN  "\033[36m"
#define COLOR_RESET "\033[0m"

static int g_total = 0;
static int g_passed = 0;

static void	test_check(const char *name, int condition)
{
	g_total++;
	if (condition)
	{
		g_passed++;
		printf("  %s[PASS]%s %s\n", COLOR_GREEN, COLOR_RESET, name);
	}
	else
	{
		printf("  %s[FAIL]%s %s\n", COLOR_RED, COLOR_RESET, name);
	}
}

static void	test_ctype(void)
{
	printf("%s--- Character Type Checks ---%s\n", COLOR_CYAN, COLOR_RESET);
	test_check("ft_isalpha('a')", ft_isalpha('a') != 0);
	test_check("ft_isalpha('1')", ft_isalpha('1') == 0);
	test_check("ft_isdigit('5')", ft_isdigit('5') != 0);
	test_check("ft_isdigit('a')", ft_isdigit('a') == 0);
	test_check("ft_isalnum('Z')", ft_isalnum('Z') != 0);
	test_check("ft_isalnum('7')", ft_isalnum('7') != 0);
	test_check("ft_isalnum('!')", ft_isalnum('!') == 0);
	test_check("ft_isascii(127)", ft_isascii(127) != 0);
	test_check("ft_isascii(128)", ft_isascii(128) == 0);
	test_check("ft_isprint(' ')", ft_isprint(' ') != 0);
	test_check("ft_isprint('\t')", ft_isprint('\t') == 0);
	test_check("ft_toupper('a')", ft_toupper('a') == 'A');
	test_check("ft_toupper('A')", ft_toupper('A') == 'A');
	test_check("ft_tolower('Z')", ft_tolower('Z') == 'z');
	test_check("ft_tolower('z')", ft_tolower('z') == 'z');
}

static void	test_string_basic(void)
{
	printf("%s--- Basic String Operations ---%s\n", COLOR_CYAN, COLOR_RESET);
	test_check("ft_strlen(\"Hello 42\")", ft_strlen("Hello 42") == 8);
	test_check("ft_strlen(\"\")", ft_strlen("") == 0);

	test_check("ft_strchr(\"bangkok\", 'g')", ft_strchr("bangkok", 'g') != NULL && *ft_strchr("bangkok", 'g') == 'g');
	test_check("ft_strchr(\"bangkok\", 'z')", ft_strchr("bangkok", 'z') == NULL);
	test_check("ft_strrchr(\"banana\", 'a')", ft_strrchr("banana", 'a') != NULL && ft_strrchr("banana", 'a') == &("banana"[5]));

	test_check("ft_strncmp(\"abc\", \"abc\", 3)", ft_strncmp("abc", "abc", 3) == 0);
	test_check("ft_strncmp(\"abc\", \"abd\", 2)", ft_strncmp("abc", "abd", 2) == 0);
	test_check("ft_strncmp(\"abc\", \"abd\", 3)", ft_strncmp("abc", "abd", 3) < 0);

	test_check("ft_strnstr(\"42 Bangkok Common Core\", \"Bangkok\", 20)", ft_strnstr("42 Bangkok Common Core", "Bangkok", 20) != NULL);
	test_check("ft_strnstr(\"42 Bangkok\", \"Bangkok\", 5)", ft_strnstr("42 Bangkok", "Bangkok", 5) == NULL);
}

static void	test_memory(void)
{
	char buf1[32];
	char buf2[32];

	printf("%s--- Memory Operations ---%s\n", COLOR_CYAN, COLOR_RESET);
	ft_memset(buf1, 'A', 10);
	buf1[10] = '\0';
	test_check("ft_memset", strcmp(buf1, "AAAAAAAAAA") == 0);

	ft_bzero(buf1, 5);
	test_check("ft_bzero", buf1[0] == 0 && buf1[4] == 0 && buf1[5] == 'A');

	ft_memcpy(buf2, "Hello", 6);
	test_check("ft_memcpy", strcmp(buf2, "Hello") == 0);

	char overlap[] = "123456789";
	ft_memmove(overlap + 2, overlap, 5);
	test_check("ft_memmove overlapping", memcmp(overlap, "121234589", 9) == 0);

	test_check("ft_memcmp identical", ft_memcmp("abcd", "abcd", 4) == 0);
	test_check("ft_memcmp diff", ft_memcmp("abcd", "abce", 4) < 0);
}

static void	test_alloc_and_conversions(void)
{
	printf("%s--- Allocations & Conversions ---%s\n", COLOR_CYAN, COLOR_RESET);
	test_check("ft_atoi(\"42\")", ft_atoi("42") == 42);
	test_check("ft_atoi(\"   -2147483648\")", ft_atoi("   -2147483648") == -2147483648LL);
	test_check("ft_atoi(\" +42abc\")", ft_atoi(" +42abc") == 42);

	char *dup = ft_strdup("42 Bangkok");
	test_check("ft_strdup", dup != NULL && strcmp(dup, "42 Bangkok") == 0);
	free(dup);

	char *sub = ft_substr("0123456789", 3, 4);
	test_check("ft_substr", sub != NULL && strcmp(sub, "3456") == 0);
	free(sub);

	char *join = ft_strjoin("Hello ", "World!");
	test_check("ft_strjoin", join != NULL && strcmp(join, "Hello World!") == 0);
	free(join);

	char *trim = ft_strtrim("   xxHello 42xx   ", " x");
	test_check("ft_strtrim", trim != NULL && strcmp(trim, "Hello 42") == 0);
	free(trim);

	char *itoa_val = ft_itoa(-12345);
	test_check("ft_itoa(-12345)", itoa_val != NULL && strcmp(itoa_val, "-12345") == 0);
	free(itoa_val);

	char **split = ft_split("split**this*string*properly", '*');
	int split_ok = (split != NULL && split[0] && strcmp(split[0], "split") == 0
		&& split[1] && strcmp(split[1], "this") == 0
		&& split[2] && strcmp(split[2], "string") == 0
		&& split[3] && strcmp(split[3], "properly") == 0
		&& split[4] == NULL);
	test_check("ft_split", split_ok);
	if (split)
	{
		for (int i = 0; split[i]; i++)
			free(split[i]);
		free(split);
	}
}

static void	noop_del(void *content)
{
	(void)content;
}

static void	test_linked_list(void)
{
	printf("%s--- Bonus Linked List Operations ---%s\n", COLOR_CYAN, COLOR_RESET);
	t_list *node1 = ft_lstnew("First");
	test_check("ft_lstnew", node1 != NULL && strcmp((char *)node1->content, "First") == 0 && node1->next == NULL);

	t_list *node0 = ft_lstnew("Zero");
	ft_lstadd_front(&node1, node0);
	test_check("ft_lstadd_front", node1 == node0);
	test_check("ft_lstsize (2 nodes)", ft_lstsize(node1) == 2);

	t_list *node2 = ft_lstnew("Second");
	ft_lstadd_back(&node1, node2);
	test_check("ft_lstsize (3 nodes)", ft_lstsize(node1) == 3);
	test_check("ft_lstlast", ft_lstlast(node1) == node2);

	ft_lstclear(&node1, noop_del);
	test_check("ft_lstclear", node1 == NULL);
}

int	main(void)
{
	printf("\n=========================================\n");
	printf("       %sLIBFT UNIT TEST RUNNER%s        \n", COLOR_CYAN, COLOR_RESET);
	printf("=========================================\n\n");

	test_ctype();
	printf("\n");
	test_string_basic();
	printf("\n");
	test_memory();
	printf("\n");
	test_alloc_and_conversions();
	printf("\n");
	test_linked_list();

	printf("\n=========================================\n");
	printf("RESULTS: %s%d passed%s / %d total tests\n",
		(g_passed == g_total) ? COLOR_GREEN : COLOR_RED,
		g_passed, COLOR_RESET, g_total);
	printf("=========================================\n\n");

	return (g_passed == g_total ? 0 : 1);
}
