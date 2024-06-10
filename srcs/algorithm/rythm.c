/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rythm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:55:28 by andefern          #+#    #+#             */
/*   Updated: 2024/06/10 11:34:21 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rythm(t_stack **stack_a, t_stack **stack_b, int all_ints, int bit)
{
	int	i;

	i = 0;
	if (sort(stack_a) || bit >= 16)
		return ;
	while (i++ < all_ints)
	{
		if ((trick(stack_a)->num >> bit) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
	while (left(stack_a) < all_ints)
		pa(stack_a, stack_b);
	rythm(stack_a, stack_b, all_ints, ++bit);
}
