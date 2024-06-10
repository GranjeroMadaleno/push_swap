/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:45:52 by andefern          #+#    #+#             */
/*   Updated: 2024/06/10 12:59:52 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update(t_stack **stack)
{
	t_stack	*latest;
	int		index;

	latest = *stack;
	index = 1;
	while (latest)
	{
		if (latest->num > 0)
			latest->pos = index++;
		else
			latest->pos = 0;
		latest = latest->next;
	}
}

void	morgan_freeman(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

void	stack_dup(t_stack **src, t_stack **dst)
{
	t_stack	*latest_src;	

	latest_src = *src;
	while (latest_src)
	{
		new_node(latest_src->num, latest_src->pos, dst);
		latest_src = latest_src->next;
	}
}

void	new_node(int num, int pos, t_stack **stack)
{
	t_stack	*node;
	t_stack	*first;

	node = malloc(sizeof(t_stack));
	node->next = NULL;
	node->num = num;
	node->pos = pos;
	if (!*stack)
		*stack = node;
	else
	{
		first = (*stack);
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = node;
		(*stack) = first;
	}
}
