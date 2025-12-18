/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:17:50 by maroard           #+#    #+#             */
/*   Updated: 2025/12/18 12:29:22 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strategy_selector(int argc, char *argv[], int *strategy)
{
	if (argc == 1)
		return (0);
	if (!ft_strncmp("--simple", argv[1], ft_strlen(argv[1])))
		*strategy = SIMPLE;
	else if (!ft_strncmp("--medium", argv[1], ft_strlen(argv[1])))
		*strategy = MEDIUM;
	else if (!ft_strncmp("--complex", argv[1], ft_strlen(argv[1])))
		*strategy = COMPLEX;
	else
		*strategy = ADAPTIVE;
	return (1);
}
