/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:23 by maroard           #+#    #+#             */
/*   Updated: 2025/12/26 17:42:42 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **A, t_bool ss)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!(*A)->top || !(*A)->top->next)
		return ;
	first = (*A)->top;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	(*A)->top = second;
	if (ss == FALSE)
		ft_printf("sa\n");
}

void	swap_b(t_stack **B, t_bool ss)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!(*B)->top || !(*B)->top->next)
		return ;
	first = (*B)->top;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	(*B)->top = second;
	if (ss == FALSE)
		ft_printf("sb\n");
}

void	swap_swap(t_stack **A, t_stack **B)
{
	swap_a(A, TRUE);
	swap_b(B, TRUE);
	ft_printf("ss\n");
}
