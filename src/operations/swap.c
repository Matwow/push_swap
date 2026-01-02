/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:23 by maroard           #+#    #+#             */
/*   Updated: 2026/01/02 18:41:20 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_ctx *ctx, t_bool ss)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!ctx->a.top || !ctx->a.top->next)
		return ;
	first = ctx->a.top;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	ctx->a.top = second;
	if (ss == FALSE)
		logs_manager(ctx, SA);
}

void	swap_b(t_ctx *ctx, t_bool ss)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!ctx->b.top || !ctx->b.top->next)
		return ;
	first = ctx->b.top;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	ctx->b.top = second;
	if (ss == FALSE)
		logs_manager(ctx, SB);
}

void	swap_swap(t_ctx *ctx)
{
	swap_a(ctx, TRUE);
	swap_b(ctx, TRUE);
	logs_manager(ctx, SS);
}
