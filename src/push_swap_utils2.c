/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:07:01 by maroard           #+#    #+#             */
/*   Updated: 2025/12/18 17:02:38 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	*clear_stack(t_node **top, t_stack *A_or_B)
{
	t_node	*temp;

	while (*top)
	{
		temp = (*top)->next;
		free(*top);
		*top = temp;
	}
	free(A_or_B);
	return (NULL);
}

void	print_stack(t_node *top, char A_or_B)
{
	ft_printf("Stack %c:\n", A_or_B);
	while (top)
	{
		ft_printf("[ %d ]\n", top->content);
		top = top->next;
	}
}

int	is_number(char *arg)
{
	size_t	i;

	i = 0;
	while ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == ' ')
		i++;
	if (!arg[i])
		return (0);
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	stack_is_sorted(t_stack **A_or_B)
{
	t_node	*check;

	if (!(*A_or_B) || !(*A_or_B)->top)
		return (1);
	check = (*A_or_B)->top;
	while (check->next)
	{
		if (check->content > check->next->content)
			return (0);
		check = check->next;
	}
	return (1);
}
