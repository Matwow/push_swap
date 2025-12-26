/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_based_sorting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:31:02 by maroard           #+#    #+#             */
/*   Updated: 2025/12/26 15:53:32 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "math.h"

static void	indexation(t_stack **A_or_B)
{
	t_node	*current;
	t_node	*checker;

	current = (*A_or_B)->top;
	while (current)
	{
		current->index = 0;
		current = current->next;
	}
	current = (*A_or_B)->top;
	while (current)
	{
		checker = (*A_or_B)->top;
		while (checker)
		{
			if (checker->content < current->content)
				current->index++;
			checker = checker->next;
		}
		current = current->next;
	}
}

static void	injection(t_stack **A, t_stack **B)
{
	int	i;

	i = 0;
	indexation(B);
	while ((*B)->top->index != (*B)->size - 1)
	{
		rotate_b(B, FALSE);
		i++;
	}
	push_a(A, B);
	if ((*B)->size == 2)
	{
		if ((*B)->top->index < (*B)->top->next->index)
			swap_b(B, FALSE);
		return (push_a(A, B));
	}
	while (i--)
		reverse_rotate_b(B, FALSE);
}

static void	extraction(t_stack **A, t_stack **B, int range_size)
{
	indexation(A);
	if ((*B)->size / range_size >= 1)
		indexation(A);
	if ((*A)->top->index < range_size)
		push_b(A, B);
	else if ((*A)->top->next)
		rotate_a(A, FALSE);
}

void	range_based_sorting(t_stack **A, t_stack **B)
{
	int	range_size;

	range_size = (int)sqrtf((*A)->size);
	while ((*A)->top)
		extraction(A, B, range_size);
	while ((*B)->top)
		injection(A, B);
}
