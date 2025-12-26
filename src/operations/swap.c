/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:23 by maroard           #+#    #+#             */
/*   Updated: 2025/12/26 12:43:50 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a, t_bool ss)
{
	t_node	*temp;

	temp = (*a)->top;
	(*a)->top = (*a)->top->next;
	(*a)->top->next = temp;
	if (ss == FALSE)
		ft_printf("sa\n");
}

void	swap_b(t_stack **b, t_bool ss)
{
	t_node	*temp;

	temp = (*b)->top;
	(*b)->top = (*b)->top->next;
	(*b)->top->next = temp;
	if (ss == FALSE)
		ft_printf("sb\n");
}

void	swap_swap(t_stack **a, t_stack **b)
{
	swap_a(a, TRUE);
	swap_b(b, TRUE);
	ft_printf("ss\n");
}
