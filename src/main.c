/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:32 by maroard           #+#    #+#             */
/*   Updated: 2025/12/18 17:15:00 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static int	algo_caller(t_stack **a, t_stack **b, int strategy)
{
	float	disorder;

	disorder = compute_disorder(*a);
	if (strategy == ADAPTIVE)
	{
		if (disorder < 0.2)
			strategy = SIMPLE;
		else if (disorder >= 0.2 && disorder < 0.5)
			strategy = MEDIUM;
		else if (disorder >= 0.5)
			strategy = COMPLEX;
	}
	if (strategy == SIMPLE && !(simple_min_max_extraction(a, b)))
		return (0);
	// if (strategy == MEDIUM && !())
	// 	return (0);
	// if (strategy == COMPLEX && !())
	// 	return (0);
	return (1);
}

static int	init(int argc, char *argv[], t_stack **a, t_stack **b)
{
	*a = create_stack_a(argc, argv);
	if (!(*a) || !occurence_checker(*a))
		return (0);
	*b = malloc(sizeof(a));
	if (!(*b))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_strat	strategy;
	t_stack	*a;
	t_stack *b;

	if (!strategy_selector(argc, argv, &strategy) || !init(argc, argv, &a, &b))
	{
		ft_printf("Strategy: %d\n", strategy);
		ft_putstr_fd("Error\n", 0);
		return (-1);
	}
	ft_printf("Strategy: %d\n", strategy);
	printf("\nDisorder: %f\n", compute_disorder(a));
	ft_putstr_fd("OK\n\n", 1);
	algo_caller(&a, &b, strategy);
	clear_stack(&a->top, a);
	clear_stack(&b->top, b);
	return (0);
}
