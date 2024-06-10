/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:55:26 by andefern          #+#    #+#             */
/*   Updated: 2024/06/10 12:36:24 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_3(t_stack **stack_a, int all_ints)
{
	if (trick(stack_a)->num == all_ints - 2 && !sort(stack_a))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (trick(stack_a)->num == all_ints - 1)
	{
		if (trick(stack_a)->next->num == all_ints - 2)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else if (trick(stack_a)->num == all_ints)
	{
		if (trick(stack_a)->next->num == all_ints - 2)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	if_5(t_stack **stack_a, t_stack **stack_b, int all_ints)
{
	while (left(stack_a) > 3)
	{
		if (trick(stack_a)->num <= 2)
			pb(stack_a, stack_b);
		else if (base(stack_a)->num <= 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	if_3(stack_a, all_ints);
	if (trick(stack_b)->num == 1)
		sb(stack_b);
	if (all_ints == 5)
		pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
