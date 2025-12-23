/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:21 by maroard           #+#    #+#             */
/*   Updated: 2025/12/23 11:57:58 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_node	*temp;

	temp = (*b)->top;
	(*b)->top = (*b)->top->next;
	node_add_front(&((*a)->top), temp);
	(*a)->size++;
	(*b)->size--;
	ft_printf("pa\n");
	return ;
}

void	push_b(t_stack **a, t_stack **b)
{
	t_node	*temp;

	temp = (*a)->top;
	(*a)->top = (*a)->top->next;
	node_add_front(&((*b)->top), temp);
	(*b)->size++;
	(*a)->size--;
	ft_printf("pb\n");
	return ;
}
