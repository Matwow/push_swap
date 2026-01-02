/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:17:50 by maroard           #+#    #+#             */
/*   Updated: 2026/01/02 17:07:02 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strategy_selector(int argc, char *argv[], t_ctx *ctx)
{
	if (argc == 1 || (argc == 2 && !is_number(argv[1])))
		return (0);
	if (argc >= 3 && !ft_strncmp("--simple", argv[1], 8))
		ctx->strategy = SIMPLE;
	else if (argc >= 3 && !ft_strncmp("--medium", argv[1], 8))
		ctx->strategy = MEDIUM;
	else if (argc >= 3 && !ft_strncmp("--complex", argv[1], 9))
		ctx->strategy = COMPLEX;
	else if (argc >= 3 && !ft_strncmp("--bench", argv[1], 7))
	{
		ctx->bench.is_active = TRUE;
		ctx->strategy = ADAPTIVE;
	}
	else if (argc >= 3 && !is_number(argv[1])
		&& ft_strncmp("--adaptive", argv[1], 10))
		return (0);
	else
		ctx->strategy = ADAPTIVE;
	return (1);
}
