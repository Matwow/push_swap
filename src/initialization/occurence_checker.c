/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occurence_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:38:11 by maroard           #+#    #+#             */
/*   Updated: 2025/12/23 11:13:27 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	occurence_checker(t_stack *A)
{
	t_node	*current;
	t_node	*checker;

	current = A->top;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->content == checker->content)
				return (0);
			checker = checker->next;
		}
		current = current->next;
	}
	return (1);
}
