/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:32 by maroard           #+#    #+#             */
/*   Updated: 2025/12/18 12:23:36 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	init(int argc, char *argv[], t_stack **a)
{
	*a = create_stack_a(argc, argv);
	if (!(*a) || !occurence_checker(*a))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	int		strategy;
	t_stack	*a;
	//t_stack	*b;

	if (!strategy_selector(argc, argv, &strategy) || !init(argc, argv, &a))
	{
		ft_printf("Strategy: %d\n", strategy);
		ft_putstr_fd("Error\n", 0);
		return (-1);
	}
	ft_printf("Strategy: %d\n", strategy);
	print_stack(a->top, 'A');
	printf("\nDisorder: %f\n", compute_disorder(a));
	ft_putstr_fd("OK\n", 1);
	clear_stack(&a->top, a);
	return (0);
}
