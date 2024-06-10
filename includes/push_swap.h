/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:50:21 by andefern          #+#    #+#             */
/*   Updated: 2024/06/10 13:05:21 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				pos;
	struct s_stack	*next;
}					t_stack;

// MAIN
void	initializer(t_stack **stack_a, t_stack **stack_b, int all_inits);
void	selector(t_stack **stack_a, t_stack **stack_b, int all_ints);
int		main(int argc, char const *argv[]);
// PARSER
void	index_change(int srch, int index, t_stack **obj, t_stack **src);
t_stack	*index_ints(int all_ints, t_stack **stack_a);
void	free_split(char **split);
int		get_ints(const char *argv[], int argc, t_stack **stack_a);
void	init_stack_b(int all_ints, t_stack **stack_b);
// LISTS
void	update(t_stack **stack);
void	morgan_freeman(t_stack *stack);
void	stack_dup(t_stack **src, t_stack **dst);
void	new_node(int num, int pos, t_stack **stack);
// CHECKS
void	check_limits(t_stack **stack);
void	check_dups(t_stack **stack_a);
int		word_check(const char *word);
void	argv_check(const char *argv[]);
// MOVES A
void	sa(t_stack **stack_a);
void	ra(t_stack **stack_a);
void	rra(t_stack **stack_a);
void	pa(t_stack **stack_a, t_stack **stack_b);
// MOVES B	
void	sb(t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
// SPECIAL CASES
void	if_3(t_stack **stack_a, int all_ints);
void	if_5(t_stack **stack_a, t_stack **stack_b, int all_ints);
// UTILS
t_stack	*trick(t_stack **stack);
t_stack	*base(t_stack **stack);
int		left(t_stack **stack);
int		sort(t_stack **stack);
int		str_isdigit(int c);
//int		check_num(char **argv);
// ALGORITHM(RADIX)
void	rythm(t_stack **stack_a, t_stack **stack_b, int all_ints, int bit);

#endif
