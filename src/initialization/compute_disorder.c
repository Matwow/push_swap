/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:00:10 by maroard           #+#    #+#             */
/*   Updated: 2025/12/23 11:12:54 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *A)
{
	t_node	*current;
	t_node	*checker;
	float	mistakes;
	float	total_pairs;

	if (!A || !A->top || !A->top->next)
		return (0);
	current = A->top;
	mistakes = 0;
	total_pairs = 0;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			total_pairs++;
			if (current->content > checker->content)
				mistakes++;
			checker = checker->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}
