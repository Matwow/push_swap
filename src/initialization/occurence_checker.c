/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occurence_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:38:11 by maroard           #+#    #+#             */
/*   Updated: 2025/12/17 18:59:38 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	occurence_checker(t_stack *A)
{
	t_node	*current;
	t_node	*next;

	current = A->top;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->content == next->content)
				return (0);
			next = next->next;
		}
		current = current->next;
	}
	return (1);
}
