/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroard <maroard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:20:35 by maroard           #+#    #+#             */
/*   Updated: 2025/12/15 18:47:32 by maroard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_node
{
    int				content;
    struct s_node	*next;
}					t_node;

typedef struct s_stack
{
    t_node	*top;
    int		size;
}			t_stack;

int     ft_printf(const char *s, ...);

t_node	*create_node(int content);
t_node	*last_node(t_node *top);
void	node_add_back(t_node **top, t_node *new);
void	node_add_front(t_node **top, t_node *new);
void    *clear_stack(t_node **top, t_stack *A_or_B);
void	print_stack(t_node *top, char A_or_B);

t_stack *create_stack_A(int argc, char *argv[]);

int push_A(t_stack **A, t_stack **B);
int push_B(t_stack **A, t_stack **B);

#endif
