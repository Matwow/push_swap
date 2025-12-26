/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:42:39 by maroard           #+#    #+#             */
/*   Updated: 2025/12/26 17:43:35 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **A, t_bool rr)
{
	t_node	*temp;

	
	if (!(*A)->top || !(*A)->top->next)
		return ;
	temp = (*A)->top;
	(*A)->top = (*A)->top->next;
	(*A)->top->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	node_add_back(&((*A)->top), temp);
	if (rr == FALSE)
		ft_printf("ra\n");
}

void	rotate_b(t_stack **B, t_bool rr)
{
	t_node	*temp;

	if (!(*B)->top || !(*B)->top->next)
		return ;
	temp = (*B)->top;
	(*B)->top = (*B)->top->next;
	(*B)->top->prev = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	node_add_back(&((*B)->top), temp);
	if (rr == FALSE)
		ft_printf("rb\n");
}

void	rotate_rotate(t_stack **A, t_stack **B)
{
	rotate_a(A, TRUE);
	rotate_b(B, TRUE);
	ft_printf("rr");
}
