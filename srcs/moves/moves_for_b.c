/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_for_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:59:12 by andefern          #+#    #+#             */
/*   Updated: 2024/06/11 12:39:11 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **stack_b)
{
	int		num;
	t_stack	*top;
	t_stack	*bot;

	top = *stack_b;
	while (top->num == 0 && top->next)
		top = top->next;
	bot = top->next;
	num = top->num;
	top->num = bot->num;
	bot->num = num;
	update(stack_b);
	write(1, "sb\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_a;
	t_stack	*top_b;

	top_a = trick(stack_a);
	top_b = *stack_b;
	while (top_b->next != trick(stack_b))
		top_b = top_b->next;
	top_b->num = top_a->num;
	trick(stack_a)->num = 0;
	update(stack_a);
	update(stack_b);
	write(1, "pb\n", 3);
}
