/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:14:40 by maroard           #+#    #+#             */
/*   Updated: 2025/12/26 17:44:06 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **A, t_bool rrr)
{
	t_node	*temp;

	if (!(*A)->top || !(*A)->top->next)
		return ;
	temp = last_node((*A)->top);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	node_add_front(&((*A)->top), temp);
	if (rrr == FALSE)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **B, t_bool rrr)
{
	t_node	*temp;

	if (!(*B)->top || !(*B)->top->next)
		return ;
	temp = last_node((*B)->top);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	node_add_front(&((*B)->top), temp);
	if (rrr == FALSE)
		ft_printf("rrb\n");
}

void	reverse_rotate_rotate(t_stack **A, t_stack **B)
{
	reverse_rotate_a(A, TRUE);
	reverse_rotate_b(B, TRUE);
	ft_printf("rrr\n");
}
