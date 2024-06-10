/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_for_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:19:35 by andefern          #+#    #+#             */
/*   Updated: 2024/06/10 12:39:19 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	int		num;
	t_stack	*top;
	t_stack	*bot;

	top = *stack_a;
	while (top->num == 0 && top->next)
		top = top->next;
	bot = top->next;
	num = top->num;
	top->num = bot->num;
	bot->num = num;
	update(stack_a);
	write(1, "sa\n", 3);
}

void	ra(t_stack **stack_a)
{
	int		top_num;
	t_stack	*top;
	t_stack	*bot;

	top = *stack_a;
	while (top->num == 0 && top->next)
		top = top->next;
	top_num = top->num;
	while (top->next)
	{
		bot = top->next;
		top->num = bot->num;
		top = top->next;
	}
	top->num = top_num;
	update(stack_a);
	write(1, "ra\n", 3);
}

void	rra(t_stack **stack_a)
{
	int		pre_num;
	int		post_num;
	t_stack	*top;
	t_stack	*bot;

	top = *stack_a;
	while (top->num == 0 && top->next)
		top = top->next;
	post_num = top->num;
	while (top->next)
	{
		bot = top->next;
		post_num = bot->num;
		bot->num = pre_num;
		pre_num = post_num;
		top = top->next;
	}
	bot = *stack_a;
	while (bot->num == 0 && bot->next)
		bot = bot->next;
	bot->num = pre_num;
	update(stack_a);
	write(1, "rra\n", 4);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_a;
	t_stack	*top_b;

	top_a = *stack_a;
	while (top_a->next)
	{
		if (top_a->next->num == 0)
			top_a = top_a->next;
		else
			break ;
	}
	top_b = *stack_b;
	while (top_b->next)
	{
		if (top_b->num == 0)
			top_b = top_b->next;
		else
			break ;
	}
	top_a->num = top_b->num;
	top_b->num = 0;
	update(stack_a);
	update(stack_b);
	write(1, "pa\n", 3);
}
