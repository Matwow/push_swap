/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_min_max_extraction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:48:49 by maroard           #+#    #+#             */
/*   Updated: 2025/12/18 19:02:30 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_extremum(t_stack *a, t_bool min, t_bool max)
{
	t_node	*current;
	t_node	*check;
	int		i;

	current = a->top;
	i = 0;
	while (current)
	{
		check = a->top;
		while (check)
		{
			if ((min && current->content > check->content)
				|| (max && current->content < check->content))
				break ;
			if (!check->next && ((min && current->content <= check->content)
				|| (max && current->content >= check->content)))
				return (i);
			check = check->next;
		}
		current = current->next;
		i++;
	}
	return (0);
}

static int	chose_min_or_max(t_stack **a)
{
	int	min_position;
	int	max_position;

	min_position = find_extremum(*a, TRUE, FALSE);
	max_position = find_extremum(*a, FALSE, TRUE);
	ft_printf("min: %d\n", min_position);
	ft_printf("max: %d\n", max_position);
	if (((*a)->size / 2) - min_position >= ((*a)->size / 2) - max_position)
		return (min_position);
	return (max_position);
}

static void	extract_a_sort_b(t_stack **a, t_stack **b)
{
	int	i_to_extract;
	int	i;

	i_to_extract = chose_min_or_max(a);
	ft_printf("i_to_extract: %d\n", i_to_extract);
	if (i_to_extract <= (*a)->size / 2)
		i = 1;
	else
		i = (*a)->size / 2;
	while (i <= i_to_extract)
	{
		if (i_to_extract <= (*a)->size / 2)
			rotate_a(a, FALSE);
		else
			reverse_rotate_a(a, FALSE);
		i++;
	}
	push_b(a, b);
	// if ((*b)->top->content < (*b)->top->next->content)
	// 	swap_b(b, FALSE);
}

int	simple_min_max_extraction(t_stack **a, t_stack **b)
{
	extract_a_sort_b(a, b);
	print_stack((*a)->top, 'A');
	ft_printf("\n");
	print_stack((*b)->top, 'B');
	ft_printf("\n");

	extract_a_sort_b(a, b);
	print_stack((*a)->top, 'A');
	ft_printf("\n");
	print_stack((*b)->top, 'B');
	ft_printf("\n");

	extract_a_sort_b(a, b);
	print_stack((*a)->top, 'A');
	ft_printf("\n");
	print_stack((*b)->top, 'B');
	ft_printf("\n");

	extract_a_sort_b(a, b);
	print_stack((*a)->top, 'A');
	ft_printf("\n");
	print_stack((*b)->top, 'B');
	ft_printf("\n");

	extract_a_sort_b(a, b);
	print_stack((*a)->top, 'A');
	ft_printf("\n");
	print_stack((*b)->top, 'B');
	ft_printf("\n");
	// while (!stack_is_sorted(a))
	// {
	// 	while (!stack_is_sorted(b))
	// 	{
	// 		extract_a_sort_b(a, b);
	// 		print_stack((*a)->top, 'A');
	// 		ft_printf("\n");
	// 		print_stack((*b)->top, 'B');
	// 		ft_printf("\n");
	// 	}
	// 	push_a(a, b);
	// 	print_stack((*a)->top, 'A');
	// 	ft_printf("\n");
	// 	print_stack((*b)->top, 'B');
	// 	ft_printf("\n");
	// }
	return (1);
}
