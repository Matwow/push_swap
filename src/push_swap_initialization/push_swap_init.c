/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:51:32 by maroard           #+#    #+#             */
/*   Updated: 2025/12/17 19:20:40 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

static int	is_number(char *arg)
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

static int	add_back(size_t i, char **arg, t_stack **a)
{
	if (!is_number(arg[i])
		|| !(ft_atoll(arg[i]) >= INT_MIN && ft_atoll(arg[i]) <= INT_MAX))
		return (0);
	node_add_back(&((*a)->top), create_node(ft_atoi(arg[i])));
	(*a)->size++;
	return (1);
}

static void	*free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static t_stack	*args_split(char *arg)
{
	char	**tab;
	size_t	i;
	t_stack	*a;

	tab = ft_split(arg, ' ');
	if (!tab || !tab[0])
		return (free_tab(tab));
	i = 0;
	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	while (tab[i])
	{
		if (!add_back(i++, tab, &a))
			return (clear_stack(&(a->top), a));
	}
	free_tab(tab);
	return (a);
}

t_stack	*create_stack_a(int argc, char *argv[])
{
	size_t	i;
	t_stack	*a;

	if (argc == 2 && ft_strchr(argv[1], ' '))
		return (args_split(argv[1]));
	i = 1;
	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	while (i < (size_t)(argc))
	{
		if (!add_back(i++, argv, &a))
			return (clear_stack(&(a->top), a));
	}
	return (a);
}
