/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:28:32 by andefern          #+#    #+#             */
/*   Updated: 2024/06/11 10:38:13 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_change(int srch, int index, t_stack **obj, t_stack **src)
{
	t_stack	*latest_obj;
	t_stack	*latest_src;

	latest_obj = *obj;
	latest_src = *src;
	while (latest_src->num != srch && latest_src->next)
	{
		latest_obj = latest_obj->next;
		latest_src = latest_src->next;
	}
	latest_obj->num = index;
}

t_stack	*index_ints(int all_ints, t_stack **stack_a)
{
	t_stack	*new_stack;
	t_stack	*c_stack_a;
	int		big;
	int		small;
	int		count;

	big = INT_MAX;
	count = -1;
	new_stack = NULL;
	c_stack_a = *stack_a;
	stack_dup(stack_a, &new_stack);
	while (++count < all_ints)
	{
		small = INT_MIN;
		while (c_stack_a)
		{
			if (small < c_stack_a->num && c_stack_a->num < big)
				small = c_stack_a->num;
			c_stack_a = c_stack_a->next;
		}
		big = small;
		index_change(big, (all_ints - count), &new_stack, stack_a);
		c_stack_a = *stack_a;
	}
	return (morgan_freeman(*stack_a), new_stack);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

int	get_ints(const char *argv[], int argc, t_stack **stack_a)
{
	char	**split_argv;
	int		latest_argv;
	int		c_word;
	int		all_ints;

	latest_argv = 1;
	all_ints = 0;
	c_word = 0;
	while (latest_argv < argc)
	{
		split_argv = ft_split(argv[latest_argv], ' ');
		while (split_argv[c_word])
		{
			new_node(ft_atoi(split_argv[c_word]), all_ints + 1, stack_a);
			c_word++;
			all_ints++;
		}
		free_split(split_argv);
		c_word = 0;
		latest_argv++;
	}
	return (all_ints);
}

void	init_stack_b(int all_ints, t_stack **stack_b)
{
	int	latest_int;

	latest_int = 0;
	while (++latest_int <= all_ints)
		new_node(0, 0, stack_b);
}

/* int	str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_num(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (str_isdigit(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
 */
