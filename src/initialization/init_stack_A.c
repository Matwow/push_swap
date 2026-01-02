/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_A.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:51:32 by maroard           #+#    #+#             */
/*   Updated: 2026/01/02 17:34:46 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

static int	add_back(size_t i, char **arg, t_stack *A)
{
	if (!is_number(arg[i])
		|| !(ft_atoll(arg[i]) >= INT_MIN && ft_atoll(arg[i]) <= INT_MAX))
		return (0);
	node_add_back(&A->top, create_node(ft_atoi(arg[i])));
	A->size++;
	return (1);
}

static int	free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

static int	args_split(char *arg, t_stack *A)
{
	char	**tab;
	size_t	i;

	tab = ft_split(arg, ' ');
	if (!tab || !tab[0])
		return (free_tab(tab));
	i = 0;
	while (tab[i])
	{
		if (!add_back(i++, tab, A))
			return (clear_stack(&A->top));
	}
	free_tab(tab);
	return (1);
}

int	create_stack_a(int argc, char *argv[], t_stack *A)
{
	int		i;

	if (argc == 2 && ft_strchr(argv[1], ' '))
		return (args_split(argv[1], A));
	if (argc == 3 && ft_strchr(argv[2], ' '))
		return (args_split(argv[2], A));
	i = 1;
	if (!is_number(argv[i]))
		i = 2;
	while (i < (argc))
	{
		if (!add_back(i++, argv, A))
			return (clear_stack(&A->top));
	}
	return (1);
}
