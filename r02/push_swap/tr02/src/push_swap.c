/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:29:45 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/17 22:50:34 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nbr	*number_new(int value)
{
	t_nbr	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	return (new);
}

bool	parse_numbers(t_stack **head, int *tab, size_t size)
{
	size_t	i;
	t_nbr	*nbr;
	t_stack	*new;

	i = 0;
	while (i < size)
	{
		nbr = number_new(tab[i]);
		if (!nbr)
		{
			stack_clear(head, free);
			return (false);
		}
		new = stack_new(nbr);
		if (!new)
		{
			free(nbr);
			stack_clear(head, free);
			return (false);
		}
		stack_add(head, new);
		i++;
	}
	return (true);
}

bool	is_sorted(t_stack *head)
{
	t_nbr	*cur;
	t_nbr	*next;

	if (!head || !head->next)
		return (true);
	while (head->next)
	{
		cur = (t_nbr *)head->content;
		next = (t_nbr *)head->next->content;
		if (cur->value > next->value)
			return (false);
		head = head->next;
	}
	return (true);
}

void	quick_sort_recursive(int *tab, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	if (start >= end)
		return ;
	pivot = tab[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (tab[j] < pivot)
		{
			i++;
			swap_ints(&tab[i], &tab[j]);
		}
		j++;
	}
	swap_ints(&tab[i + 1], &tab[end]);
	quick_sort_recursive(tab, start, i);
	quick_sort_recursive(tab, i + 2, end);
}

size_t	get_rank(int *tab, size_t size, int value)
{
	size_t	low;
	size_t	high;
	size_t	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (tab[mid] == value)
			return (mid);
		else if (tab[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (0);
}

void	set_indices(t_stack *head, int *tab, size_t size)
{
	t_stack	*cur;
	t_nbr	*nbr;
	int		*sorted_tab;

	sorted_tab = duplicate_tab(tab, size);
	if (!sorted_tab)
		return ;
	quick_sort_recursive(sorted_tab, 0, (int)size - 1);
	cur = head;
	while (cur)
	{
		nbr = (t_nbr *)cur->content;
		nbr->index = get_rank(sorted_tab, size, nbr->value);
		cur = cur->next;
	}
	free(sorted_tab);
}

void	ps_init(t_ps *ps)
{
	ps->a = NULL;
	ps->b = NULL;
}

void	ps_clear(t_ps *ps)
{
	if (!ps)
		return ;
	stack_clear(&ps->a, free);
	stack_clear(&ps->b, free);
	ps->a = NULL;
	ps->b = NULL;
}

bool	push_swap(int *tab, size_t size)
{
	t_ps	ps;

	if (!tab || size < 2)
		return (false);
	ps_init(&ps);
	if (!parse_numbers(&ps.a, tab, size))
		return (ps_clear(&ps), false);
	if (is_sorted(ps.a))
		return (ps_clear(&ps), true);
	set_indices(ps.a, tab, size);
	if (size == 2)
		sort_two(&ps);
	else if (size == 3)
		sort_three(&ps);
	else if (size > 3)
		sort_radix(&ps);
	ps_clear(&ps);
	return (true);
}
