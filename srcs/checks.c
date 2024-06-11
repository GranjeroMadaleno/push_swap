/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:16:08 by andefern          #+#    #+#             */
/*   Updated: 2024/06/11 12:51:48 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_limits(t_stack **stack_a)
{
	t_stack	*latest;

	latest = *stack_a;
	while (latest->next)
	{
		latest = latest->next;
		if (latest->num >= INT_MAX || latest->num <= INT_MIN)
		{
			ft_printf("Error\n");
			morgan_freeman(*stack_a);
			exit(1);
		}
	}
}

void	check_dups(t_stack **stack_a)
{
	int		checks;
	t_stack	*latest;
	t_stack	*foe;

	foe = *stack_a;
	while (foe->next)
	{
		checks = foe->num;
		latest = foe->next;
		while (latest)
		{
			if (checks == latest->num)
			{
				morgan_freeman(*stack_a);
				ft_printf("Error\n");
				exit(1);
			}
			latest = latest->next;
		}
		foe = foe->next;
	}
}

int	word_check(const char *word)
{
	int	count;

	count = 0;
	while (word[count])
	{
		if (word[count] == '-' && count == 0 && ft_isdigit(word[count + 1]))
			count++;
		else if (word[count] == '-' && word[count - 1] == ' ' \
		&& (ft_isdigit(word[count + 1]) && word[count + 1] != '\0'))
			count++;
		else if (ft_isdigit(word[count]))
			count++;
		else if (word[count] == ' ')
			count++;
		else
			return (0);
	}
	return (1);
}

void	argv_check(const char *argv[])
{
	int	latest_argv;

	latest_argv = 1;
	while (argv[latest_argv])
	{
		if (word_check(argv[latest_argv]) == 1)
			latest_argv++;
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
}
