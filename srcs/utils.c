/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:07:09 by andefern          #+#    #+#             */
/*   Updated: 2024/06/10 13:06:29 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*trick(t_stack **stack)
{
	t_stack	*latest;

	latest = *stack;
	while (latest->next)
	{
		if (latest->num == 0)
			latest = latest->next;
		else
			break ;
	}
	return (latest);
}

t_stack	*base(t_stack **stack)
{
	t_stack	*latest;

	latest = *stack;
	while (latest->next)
		latest = latest->next;
	return (latest);
}

int	left(t_stack **stack)
{
	t_stack	*latest;

	latest = trick(stack);
	while (latest->next)
		latest = latest->next;
	return (latest->pos);
}

int	sort(t_stack **stack)
{
	t_stack	*a;
	int		n;

	a = *stack;
	n = 1;
	while (a->num == 0 && a->next)
	{
		n++;
		a = a->next;
	}
	if (a->num == 0)
		return (0);
	while (a->next)
	{
		if (a->num != n)
			return (0);
		n++;
		a = a->next;
	}
	return (1);
}
