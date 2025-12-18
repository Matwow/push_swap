/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:23 by maroard           #+#    #+#             */
/*   Updated: 2025/12/17 19:15:04 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_stack **a, t_bool ss)
{
	t_node	*temp;

	if (!(*a) || !(*a)->top || !(*a)->top->next)
		return (0);
	temp = (*a)->top;
	(*a)->top = (*a)->top->next;
	(*a)->top->next = temp;
	if (ss == FALSE)
		ft_printf("sa\n");
	return (1);
}

int	swap_b(t_stack **b, t_bool ss)
{
	t_node	*temp;

	if (!(*b) || !(*b)->top || !(*b)->top->next)
		return (0);
	temp = (*b)->top;
	(*b)->top = (*b)->top->next;
	(*b)->top->next = temp;
	if (ss == FALSE)
		ft_printf("sb\n");
	return (1);
}

int	swap_swap(t_stack **a, t_stack **b)
{
	if ((!(*a) || !(*a)->top || !(*a)->top->next)
		|| (!(*b) || !(*b)->top || !(*b)->top->next))
		return (0);
	swap_a(a, TRUE);
	swap_b(b, TRUE);
	ft_printf("ss\n");
	return (1);
}
