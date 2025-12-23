/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:42:39 by maroard           #+#    #+#             */
/*   Updated: 2025/12/23 11:57:26 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a, t_bool rr)
{
	t_node	*temp;

	temp = (*a)->top;
	(*a)->top = (*a)->top->next;
	temp->next = NULL;
	node_add_back(&((*a)->top), temp);
	if (rr == FALSE)
		ft_printf("ra\n");
	return ;
}

void	rotate_b(t_stack **b, t_bool rr)
{
	t_node	*temp;

	temp = (*b)->top;
	(*b)->top = (*b)->top->next;
	temp->next = NULL;
	node_add_back(&((*b)->top), temp);
	if (rr == FALSE)
		ft_printf("rb\n");
	return ;
}

void	rotate_rotate(t_stack **a, t_stack **b)
{
	rotate_a(a, TRUE);
	rotate_b(b, TRUE);
	ft_printf("rr");
	return ;
}
