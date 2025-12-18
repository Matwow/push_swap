/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:32 by maroard           #+#    #+#             */
/*   Updated: 2025/12/17 19:20:33 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push_swap_init(int argc, char *argv[], t_stack **a)
{
	*a = create_stack_a(argc, argv);
	if (!(*a) || !occurence_checker(*a))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	//t_stack	*b;

	if (argc == 1 || !push_swap_init(argc, argv, &a))
	{
		ft_putstr_fd("Error\n", 0);
		return (-1);
	}
	print_stack(a->top, 'A');
	printf("\nDisorder: %f\n", compute_disorder(a));
	ft_putstr_fd("OK\n", 1);
	clear_stack(&a->top, a);
	return (0);
}
