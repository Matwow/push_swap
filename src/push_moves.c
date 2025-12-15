/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:21 by maroard           #+#    #+#             */
/*   Updated: 2025/12/15 19:15:40 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int push_A(t_stack **A, t_stack **B)
{
    t_node  *temp;

    if (!(*B) || !(*B)->top)
        return (0);
    temp = (*B)->top;
    (*B)->top = (*B)->top->next;
    node_add_front(&((*A)->top), temp);
    (*A)->size++;
    (*B)->size--;
    ft_printf("pa\n");
    return (1);
}

int push_B(t_stack **A, t_stack **B)
{
	t_node  *temp;

	if (!(*A) || !(*A)->top)
		return (0);
	temp = (*A)->top;
	(*A)->top = (*A)->top->next;
	node_add_front(&((*B)->top), temp);
	(*B)->size++;
	(*A)->size--;
	ft_printf("pb\n");
	return (1);
}
