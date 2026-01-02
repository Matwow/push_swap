/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:14:40 by maroard           #+#    #+#             */
/*   Updated: 2026/01/02 18:40:29 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_ctx *ctx, t_bool rrr)
{
	t_node	*temp;

	if (!ctx->a.top || !ctx->a.top->next)
		return ;
	temp = last_node(ctx->a.top);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	node_add_front(&ctx->a.top, temp);
	if (rrr == FALSE)
		logs_manager(ctx, RRA);
}

void	reverse_rotate_b(t_ctx *ctx, t_bool rrr)
{
	t_node	*temp;

	if (!ctx->b.top || !ctx->b.top->next)
		return ;
	temp = last_node(ctx->b.top);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = NULL;
	node_add_front(&ctx->b.top, temp);
	if (rrr == FALSE)
		logs_manager(ctx, RRB);
}

void	reverse_rotate_rotate(t_ctx *ctx)
{
	reverse_rotate_a(ctx, TRUE);
	reverse_rotate_b(ctx, TRUE);
	logs_manager(ctx, RRR);
}
