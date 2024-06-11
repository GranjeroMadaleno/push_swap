/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:50:15 by andefern          #+#    #+#             */
/*   Updated: 2024/06/11 12:39:22 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initializer(t_stack **stack_a, t_stack **stack_b, int all_ints)
{
	check_limits(stack_a);
	check_dups(stack_a);
	*stack_a = index_ints(all_ints, stack_a);
	init_stack_b(all_ints, stack_b);
}

void	selector(t_stack **stack_a, t_stack **stack_b, int all_ints)
{
	if (all_ints == 2)
		sa(stack_a);
	else if (all_ints == 3)
		if_3(stack_a, all_ints);
	else if (all_ints <= 5)
		if_5(stack_a, stack_b, all_ints);
	else if (all_ints > 5)
		rythm(stack_a, stack_b, all_ints, 0);
}

int	main(int argc, char const *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		all_ints;

	if (argc == 1 || (ft_strlen(argv[1]) == 1 && argv[1][0] == ' ') \
	|| ft_strlen(argv[1]) == 0)
		return (0);
	argv_check(argv);
	stack_a = NULL;
	stack_b = NULL;
	all_ints = get_ints(argv, argc, &stack_a);
	initializer(&stack_a, &stack_b, all_ints);
	if (!sort(&stack_a) && all_ints > 1)
		selector(&stack_a, &stack_b, all_ints);
	morgan_freeman(stack_a);
	morgan_freeman(stack_b);
	return (0);
}

/* 
t_push	*new_node(void)
{
	t_push	*node;

	node = malloc(sizeof(t_push *));
	node->num = 0;
	node->index = 0;
	return (node);
}

void	new_list(t_push **list, int count)
{
	t_push	*node;

	node = new_node();
	*list = node;
	while (count > 1)
	{
		node->next = new_node();
		node = node->next;
		count--;
	}
	node->next = *list;
}

int	main(int argc, char **argv)
{
	t_push	*stack_a;
	int		i;

	if (argc < 2 || check_num(argv) == 1)
		return (0);
	stack_a = NULL;
	new_list(&stack_a, 3);
	i = 0;
	while (stack_a)
	{
		printf("soy el nodo %d y tengo el valor %d\n", i, stack_a->num);
		stack_a = stack_a->next;
		i++;
	}
	ft_printf("xd\n");
	return (0);
}
 */
